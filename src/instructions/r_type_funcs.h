#ifndef R_TYPE_FUNCS_H
#define R_TYPE_FUNCS_H

#include <stdio.h>
#include <stdlib.h>
#include "instruction_utils.h"
#include "../emulator.h"
#include "../io.h"

void instruction_add(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ADD called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_adds(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ADDS called: X%d = X%d + X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_sub(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("SUB called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_subs(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("SUBS called: X%d = X%d - X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_and(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("AND called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_ands(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ANDS called: X%d = X%d & X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_orr(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ORR called: X%d = X%d | X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_eor(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("EOR called: X%d = X%d ^ X%d with shamt %d.\n", rd, rn, rm, shamt);
}

void instruction_br(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
}

void instruction_prnl(emulator_t* emulator, uint8_t* instruction) {
  print_line("");
}

void instruction_prnt(emulator_t* emulator, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  print_register(rd, emulator->registers[rd]);
}

void instruction_dump(emulator_t* emulator, uint8_t* instruction) {
  print_line("Registers:");
  for (int i = 0; i < 32; i++) {
    print_register(i, emulator->registers[i]);
  }
  print_line("");
  print_line("Stack:");
  hexdump(emulator->stack, STACK_SIZE);
  print_line("");
  print_line("Main Memory:");
  hexdump(emulator->memory, MEM_SIZE);
}

void instruction_halt(emulator_t* emulator, uint8_t* instruction) {
  instruction_dump(emulator, instruction);
  //TODO: change handle allocated memory before exit
  exit(0);
}

#endif
