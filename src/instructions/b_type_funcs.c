#include "b_type_funcs.h"
#include <stdio.h>

void instruction_b(emulator_t* emulator, uint8_t* instruction) {
  int32_t address;
  get_b_format_params(instruction, &address);
  //printf("addr: %d.\n", address);
  emulator->pc += 4*address - 4;
}

void instruction_bl(emulator_t* emulator, uint8_t* instruction) {
  int32_t address;
  get_b_format_params(instruction, &address);
  set_reg(emulator, 30, emulator->pc+4, 0);
  emulator->pc += 4*address - 4;
}