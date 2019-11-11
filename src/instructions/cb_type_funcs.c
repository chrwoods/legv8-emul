#include "cb_type_funcs.h"
#include <stdio.h>

void add_control_hazard(emulator_t* emulator) {
  emulator->control_hazards++;
  emulator->bypass_bubbles += 3;
  emulator->no_bypass_bubbles += 3;
  shift_written(emulator->bypass, 3);
  shift_written(emulator->no_bypass, 3);
}
  

void instruction_bcond(emulator_t* emulator, uint8_t* instruction) {
  int32_t address;
  uint8_t rt;
  get_cb_format_params(instruction, &address, &rt);
  if (rt > 13) {
    halt(emulator);
  }
  if (emulator->condition_codes[rt]) {
    emulator->pc += address * 4 - 4;
    add_control_hazard(emulator);
  }
}

void instruction_cbnz(emulator_t* emulator, uint8_t* instruction) {
  int32_t address;
  uint8_t rt;
  get_cb_format_params(instruction, &address, &rt);
  if (get_reg(emulator, rt)) {
    emulator->pc += address * 4 - 4;
    add_control_hazard(emulator);
  }
}

void instruction_cbz(emulator_t* emulator, uint8_t* instruction) {
  int32_t address;
  uint8_t rt;
  get_cb_format_params(instruction, &address, &rt);
  printf("X%d = %ld.\n",rt, get_reg(emulator,rt));
  if (!get_reg(emulator, rt)) {
    emulator->pc += address * 4 - 4;
    add_control_hazard(emulator);
  }
}
