#include <stdio.h>
#include <stdlib.h>
#include "../tree.h"
#include "opcodes.h"
#include "instruction_utils.h"
#include "r_type_funcs.h"
#include "i_type_funcs.h"
#include "d_type_funcs.h"

void placeholder(emulator_t* registers, uint8_t* instruction) {
  return;
}

void init_r_type_funcs(tree_t* t) {
  tree_insert(t, OP_ADD, instruction_add);
  tree_insert(t, OP_ADDS, instruction_adds);
  tree_insert(t, OP_SUB, instruction_sub);
  tree_insert(t, OP_SUBS, instruction_subs);
  tree_insert(t, OP_AND, instruction_and);
  tree_insert(t, OP_ANDS, instruction_ands);
  tree_insert(t, OP_ORR, instruction_orr);
  tree_insert(t, OP_EOR, instruction_eor);
}

void init_i_type_funcs(tree_t* t) {
  tree_insert(t, OP_ADDI, instruction_addi);
  tree_insert(t, OP_ADDIS, instruction_addis);
  tree_insert(t, OP_SUBI, instruction_subi);
  tree_insert(t, OP_SUBIS, instruction_subis);
  tree_insert(t, OP_ANDI, instruction_andi);
  tree_insert(t, OP_ANDIS, instruction_andis);
  tree_insert(t, OP_ORRI, instruction_orri);
  tree_insert(t, OP_EORI, instruction_eori);
}

void init_d_type_funcs(tree_t* t) {
  tree_insert(t, OP_LDUR, instruction_ldur);
  tree_insert(t, OP_STUR, instruction_stur);
}

tree_t* init_opcode_tree() {
  tree_t* t = malloc(sizeof(tree_t)); 
  tree_init(t);
  
  tree_insert(t, "01010100", placeholder);
  
  init_r_type_funcs(t);
  init_i_type_funcs(t);
  init_d_type_funcs(t);

  return t;
}

short run_instruction(tree_t* opcode_tree, uint8_t* instruction, emulator_t* emulator) {
  void (*instruction_handler)(emulator_t*, uint8_t*) = get_value_op(opcode_tree, instruction);
  if (!instruction_handler) {
    return -1;
  }
  instruction_handler(emulator, instruction);
  return 0;
}
