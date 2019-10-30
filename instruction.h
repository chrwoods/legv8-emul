#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include "tree.h"

tree_t* generate_opcode_tree();
short run_instruction(tree_t* opcode_tree, uint8_t* instruction, uint16_t* registers);
  
#endif
