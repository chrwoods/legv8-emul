#ifndef CB_TYPE_FUNCS_H
#define CB_TYPE_FUNCS_H

#include "instruction_utils.h"
#include "../emulator.h"

void instruction_bcond(emulator_t* emulator, uint8_t* instruction);
void instruction_cbnz(emulator_t* emulator, uint8_t* instruction);
void instruction_cbz(emulator_t* emulator, uint8_t* instruction);
#endif