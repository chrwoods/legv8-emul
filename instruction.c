#include <stdlib.h>
#include <stdint.h>
#include "tree.h"

void get_d_format_params(uint8_t* instruction, uint8_t* rn, uint8_t* rm, uint8_t* rd, uint8_t* shamt) {
  return;
}

void placeholder(uint16_t* registers, uint8_t* instruction) {
  return;
}

void instruction_add(uint16_t* registers, uint8_t* instruction) {
  return;
}

tree_t* generate_opcode_tree() {
  tree_t* t = malloc(sizeof(tree_t)); 
  tree_init(t);

  tree_insert(t, "0", placeholder);
  tree_insert(t, "10001011000", instruction_add);
  
  return t;
}

short run_instruction(tree_t* opcode_tree, uint8_t* instruction, uint16_t* registers) {
  void (*instruction_handler)(uint16_t*, uint8_t*) = get_value_op(opcode_tree, instruction);
  if (!instruction_handler) {
    return -1;
  }
  instruction_handler(registers, instruction);
  return 0;
}
