#ifndef D_TYPE_FUNCS_H
#define D_TYPE_FUNCS_H

#include <stdio.h>
#include "instruction_utils.h"

void instruction_ldur(emulator_t* emulator, uint8_t* instruction);
void instruction_stur(emulator_t* emulator, uint8_t* instruction);

#endif
