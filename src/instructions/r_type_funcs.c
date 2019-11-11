//#include "r_type_funcs.h"
#include "instruction_utils.h"
#include "../io.h"
#include <stdio.h>
#include <stdlib.h>

void instruction_add(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("ADD called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) + get_reg(emulator, rn);
  set_reg(emulator, rd, result, 1);
}

void instruction_adds(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("ADDS called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) + get_reg(emulator, rn);
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
}

void instruction_sub(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("SUB called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) - get_reg(emulator, rn);
  set_reg(emulator, rd, result, 1);
}

void instruction_subs(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("SUBS called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) - get_reg(emulator, rn);
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
}

void instruction_and(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("AND called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) & get_reg(emulator, rn);
  set_reg(emulator, rd, result, 1);
}

void instruction_ands(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("ANDS called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) & get_reg(emulator, rn);
  set_condition_codes(emulator, result);
  set_reg(emulator, rd, result, 1);
}

void instruction_orr(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("ORR called: X%d = X%d | X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) | get_reg(emulator, rn);
  set_reg(emulator, rd, result, 1);
}

void instruction_eor(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  //printf("EOR called: X%d = X%d ^ X%d with shamt %d.\n", rd, rn, rm, shamt);
  int64_t result = get_reg(emulator, rm) ^ get_reg(emulator, rn);
  set_reg(emulator, rd, result, 1);
}

void instruction_br(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  
}

// this function is a quick bodge to not count a Sheaffer-defined method in pipeline/cycle counts
void ignore_cycle(emulator_t* emulator) {
  emulator->instructions--;
  emulator->bypass[0] = emulator->bypass[1];
  emulator->bypass[1] = emulator->bypass[2];
  emulator->no_bypass[0] = emulator->no_bypass[1];
  emulator->no_bypass[1] = emulator->no_bypass[2];
}

void instruction_prnl(emulator_t* emulator, uint8_t* instruction) {
  ignore_cycle(emulator);
  print_line("");
}

void instruction_prnt(emulator_t* emulator, uint8_t* instruction) {
  ignore_cycle(emulator);
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  print_register(rd, emulator->registers[rd]);
}

void instruction_dump(emulator_t* emulator, uint8_t* instruction) {
  ignore_cycle(emulator);
  dump(emulator);
}

void instruction_halt(emulator_t* emulator, uint8_t* instruction) {
  ignore_cycle(emulator);
  halt(emulator);
}

void instruction_mul(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  print_register(rd, emulator->registers[rd]);
}

void instruction_div(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  print_register(rd, emulator->registers[rd]);
}
