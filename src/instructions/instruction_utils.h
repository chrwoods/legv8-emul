#ifndef INSTRUCTION_UTILS_H
#define INSTRUCTION_UTILS_H

#include <stdint.h>

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

#endif
