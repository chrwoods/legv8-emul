#ifndef R_TYPE_FUNCS_H
#define R_TYPE_FUNCS_H

#include <stdio.h>
#include "instruction_utils.h"

void instruction_add(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ADD called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_adds(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ADDS called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_sub(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("SUB called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_subs(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("SUBS called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_and(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("AND called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_ands(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ANDS called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
}

#endif
