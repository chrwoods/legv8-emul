#include <stdio.h>
#include "instruction_utils.h"
#include "../emulator.h"

void instruction_addi(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) + immediate;
  set_reg(emulator, rd, result, 1);
  //emulator->registers[rd] = emulator->registers[rn] + immediate;
  //printf("ADDI called: X%d = X%d + #%d.\n", rd, rn, immediate);
}

void instruction_addis(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) + immediate;
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
  //printf("ADDIS called: X%d = X%d + #%d.\n", rd, rn, immediate);
}

void instruction_subi(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) - immediate;
  set_reg(emulator, rd, result, 1);
  //emulator->registers[rd] = emulator->registers[rn] - immediate;
  //printf("SUBI called: X%d = X%d - #%d.\n", rd, rn, immediate);
}

void instruction_subis(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) - immediate;
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
  //printf("SUBIS called: X%d = X%d - #%d.\n", rd, rn, immediate);
}

void instruction_andi(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) & immediate;
  set_reg(emulator, rd, result, 1);
  //printf("ANDI called: X%d = X%d & #%d.\n", rd, rn, immediate);
}

void instruction_andis(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) & immediate;
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
  //printf("ANDIS called: X%d = X%d & #%d.\n", rd, rn, immediate);
}

void instruction_orri(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) | immediate;
  set_reg(emulator, rd, result, 1);
  //printf("ORRI called: X%d = X%d | #%d.\n", rd, rn, immediate);
}

void instruction_eori(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rn, rd;
  int16_t immediate;
  get_i_format_params(instruction,&immediate, &rn, &rd);
  int64_t result = get_reg(emulator, rn) ^ immediate;
  set_reg(emulator, rd, result, 1);
  //printf("EORI called: X%d = X%d ^ #%d.\n", rd, rn, immediate);
}
