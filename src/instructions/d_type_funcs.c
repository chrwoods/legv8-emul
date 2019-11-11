#include <stdio.h>
#include "instruction_utils.h"

void instruction_ldur(emulator_t* emulator, uint8_t* instruction) {
  uint16_t address;
  uint8_t op2, rn, rt;
  get_d_format_params(instruction, &address, &op2, &rn, &rt);
  int64_t result = get_data(emulator, address, rn);
  set_reg(emulator, rt, result, 0);
  //printf("LDUR called: X%d = X%d[%d] with op:%d.\n", rt, rn, address, op2);
}

void instruction_stur(emulator_t* emulator, uint8_t* instruction) {
  uint16_t address;
  uint8_t op2, rn, rt;
  get_d_format_params(instruction, &address, &op2, &rn, &rt);
  int64_t result = get_reg(emulator, rt);
  set_data(emulator, address, rn, result);
  //printf("STUR called: X%d[%d] = X%d with op:%d.\n", rn, address, rt, op2);
}
