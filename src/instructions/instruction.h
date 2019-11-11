#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <stdint.h>
#include "../emulator.h"
#include "../tree.h"

tree_t* init_opcode_tree();
short run_instruction(tree_t* opcode_tree, uint8_t* instruction, emulator_t* emulator);
  
#endif
