#ifndef I_TYPE_FUNCS_H
#define I_TYPE_FUNCS_H

#include <stdio.h>
#include "instruction_utils.h"
#include "../emulator.h"

void instruction_addi(emulator_t* emulator, uint8_t* instruction);
void instruction_addis(emulator_t* emulator, uint8_t* instruction);
void instruction_subi(emulator_t* emulator, uint8_t* instruction);
void instruction_subis(emulator_t* emulator, uint8_t* instruction);
void instruction_andi(emulator_t* emulator, uint8_t* instruction);
void instruction_andis(emulator_t* emulator, uint8_t* instruction);
void instruction_orri(emulator_t* emulator, uint8_t* instruction);
void instruction_eori(emulator_t* emulator, uint8_t* instruction);
#endif
