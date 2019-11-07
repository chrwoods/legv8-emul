#ifndef I_TYPE_FUNCS_H
#define I_TYPE_FUNCS_H

#include <stdio.h>
#include "instruction_utils.h"

void instruction_addi(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("ADDI called: X%d = X%d + #%d.\n", rd, rn, immediate);
}

void instruction_addis(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("ADDIS called: X%d = X%d + #%d.\n", rd, rn, immediate);
}

void instruction_subi(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("SUBI called: X%d = X%d - #%d.\n", rd, rn, immediate);
}

void instruction_subis(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("SUBIS called: X%d = X%d - #%d.\n", rd, rn, immediate);
}

void instruction_andi(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("ANDI called: X%d = X%d & #%d.\n", rd, rn, immediate);
}

void instruction_andis(uint16_t* registers, uint8_t* instruction) {
  uint8_t rn, rd;
  uint16_t immediate;
  get_i_format_params(instruction, &immediate, &rn, &rd);
  printf("ANDIS called: X%d = X%d & #%d.\n", rd, rn, immediate);
}

#endif
