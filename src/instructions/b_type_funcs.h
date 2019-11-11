#ifndef B_TYPE_FUNCS_H
#define B_TYPE_FUNCS_H

#include "instruction_utils.h"
#include "../emulator.h"

void instruction_b(emulator_t* emulator, uint8_t* instruction);
void instruction_bl(emulator_t* emulator, uint8_t* instruction);

#endif