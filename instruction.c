#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "tree.h"

int get_param(uint8_t* instruction, short offset, short length) {
  int temp = 0;
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

void get_i_format_params(uint8_t* instruction, uint8_t* immediate, uint8_t* rn, uint8_t* rd) {
  *immediate = get_param(instruction, 10, 12);
  *rn = get_param(instruction, 22, 5);
  *rd = get_param(instruction, 27, 5);
}

void placeholder(uint16_t* registers, uint8_t* instruction) {
  return;
}

void instruction_add(uint16_t* registers, uint8_t* instruction) {
  uint8_t rm, shamt, rn, rd;
  get_r_format_params(instruction, &rm, &shamt, &rn, &rd);
  printf("ADD called on %d, %d, %d with shamt %d.\n", rm, rn, rd, shamt);
}

tree_t* init_opcode_tree() {
  printf("Hello!\n");
  tree_t* t = malloc(sizeof(tree_t)); 
  tree_init(t);
  printf("Hello!\n");
  
  tree_insert(t, "01010100", placeholder);
  printf("Hello!\n");

  tree_insert(t, "10001011000", instruction_add);
  printf("Hello!\n");
  
  return t;
}

short run_instruction(tree_t* opcode_tree, uint8_t* instruction, uint16_t* registers) {
  void (*instruction_handler)(uint16_t*, uint8_t*) = get_value_op(opcode_tree, instruction);
  if (!instruction_handler) {
    return -1;
  }
  printf("Helo!");
  instruction_handler(registers, instruction);
  return 0;
}
