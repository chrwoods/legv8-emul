#include "../io.h"
#include "instruction_utils.h"

/* maybe move to its own file but probably not*/
typedef union bytes {
  int64_t value;
  uint8_t byteArr[8];
} bytes_t;

int32_t get_param(uint8_t* instruction, short offset, short length) {
  int32_t temp = 0;
  instruction += offset / 8;
  offset = 7 - (offset % 8);
  for (int i = 0; i < length; i++) {
    temp *= 2;
    if (offset < 0) {
      offset = 7;
      instruction++;
    }
    temp += (*instruction >> offset--) & 1;
  }
  return temp;
}

int32_t convert_to_signed(uint32_t to_convert, short length) {
  uint32_t check = 1 << (length - 1);
  int32_t converted = to_convert;
  if ((to_convert & check) != 0) {
    check <<= 1;
    check -= 1;
    converted = converted ^ check;
    converted += 1;
    converted *= -1;
  }
  return converted;
}

void get_r_format_params(uint8_t* instruction, uint8_t* rm, uint8_t* shamt, uint8_t* rn, uint8_t* rd) {
  *rm = get_param(instruction, 11, 5);
  *shamt = get_param(instruction, 16, 6);
  *rn = get_param(instruction, 22, 5);
  *rd = get_param(instruction, 27, 5);
}

void get_d_format_params(uint8_t* instruction, uint16_t* address, uint8_t* op2, uint8_t* rn, uint8_t* rt) {
  *address = get_param(instruction, 11, 9);
  *op2 = get_param(instruction, 20, 2);
  *rn = get_param(instruction, 22, 5);
  *rt = get_param(instruction, 27, 5);
}

void get_i_format_params(uint8_t* instruction, int16_t* immediate, uint8_t* rn, uint8_t* rd) {
  *immediate = convert_to_signed(get_param(instruction, 10, 12), 12);
  *rn = get_param(instruction, 22, 5);
  *rd = get_param(instruction, 27, 5);
}

void get_b_format_params(uint8_t* instruction, int32_t* address) {
  *address = convert_to_signed(get_param(instruction, 6, 26), 26);
}

void get_cb_format_params(uint8_t* instruction, int32_t* address, uint8_t* rt) {
  *address = convert_to_signed(get_param(instruction, 8, 19), 19);
  *rt = get_param(instruction, 27, 5);
}

void set_condition_codes(emulator_t* emulator, int64_t result) {
  short eq = 0;
  short gt = 0;
  short lt = 0;
  if (result == 0) {
    eq = 1;
  } else if (result > 0) {
    gt = 1;
  } else {
    lt = 1;
  }
  emulator->condition_codes[0] = eq;
  emulator->condition_codes[1] = eq | gt;
  emulator->condition_codes[2] = gt;
  emulator->condition_codes[3] = gt;
  emulator->condition_codes[4] = eq | gt;
  emulator->condition_codes[5] = lt | eq;
  emulator->condition_codes[6] = lt;
  emulator->condition_codes[7] = lt | eq;
  emulator->condition_codes[8] = lt;
  emulator->condition_codes[9] = lt;
  emulator->condition_codes[10] = !eq;
  emulator->condition_codes[11] = eq | gt;
}

void halt(emulator_t* emulator) {
  dump(emulator);
  destroy_emulator(emulator);
  exit(0);
}

void shift_read_instructions(emulator_t* emulator) {
  emulator->gap = emulator->prev;
  emulator->prev = emulator->cur;
  emulator->cur = -1;
}

int64_t get_reg(emulator_t* emulator, uint8_t index) {
  if (index < 0 || index > 31) {
    halt(emulator);
  }

  //TODO: fix
  if (emulator->prev == index) {
    emulator->data_hazards[0]++; 
  } else if (emulator->prev == index - 32) {
    emulator->data_hazards[2]++;
  } else if (emulator->gap == index) {
    emulator->data_hazards[1]++;
  } else if (emulator->gap == index - 32) {
    emulator->data_hazards[3]++;
  }
  
  return emulator->registers[index];
}

void set_reg(emulator_t* emulator, uint8_t index, int64_t value, uint8_t is_alu) {
  if (index < 0 || index > 31) {
    halt(emulator);
  }
  
  if (index != 31) {
    emulator->registers[index] = value;
    emulator->cur = is_alu * 32 + index;
  } else {
    emulator->cur = -1;
  }
}

int64_t get_data(emulator_t* emulator, uint16_t address, uint8_t reg) {
  bytes_t b;
  int64_t result = get_reg(emulator, reg);
  uint16_t offset = result+address;
  if (address < 0 || address > 4096 || offset < 0 || offset > 4079)
    halt(emulator);
  
  uint16_t i;
  for (i = offset; i < offset+8; i++)
    b.byteArr[offset+7-i] = emulator->memory[i];
  return b.value;
}

void set_data(emulator_t* emulator, uint16_t address, uint8_t reg, int64_t value) {
  bytes_t b;
  int64_t result = get_reg(emulator, reg);
  uint16_t offset = result+address;
  b.value = result;
  if (address < 0 || address > 4096 || offset < 0 || offset > 4079)
    halt(emulator);
  uint16_t writeStart = 7-(offset%8)+offset;
  uint16_t i;
  for (i=0; i < 8-(offset%8);i++) {
    emulator->memory[writeStart-i] = b.byteArr[7-(offset%8)-i];
  }

  //emulator->memory[reg+address] = b.value;  
}
