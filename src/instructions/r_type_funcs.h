#ifndef R_TYPE_FUNCS_H
#define R_TYPE_FUNCS_H

#include <stdlib.h>
#include "../emulator.h"

void instruction_add(emulator_t* emulator, uint8_t* instruction);
void instruction_adds(emulator_t* emulator, uint8_t* instruction);
void instruction_sub(emulator_t* emulator, uint8_t* instruction);
void instruction_subs(emulator_t* emulator, uint8_t* instruction);
void instruction_and(emulator_t* emulator, uint8_t* instruction);
void instruction_ands(emulator_t* emulator, uint8_t* instruction);
void instruction_orr(emulator_t* emulator, uint8_t* instruction);
void instruction_eor(emulator_t* emulator, uint8_t* instruction);
void instruction_br(emulator_t* emulator, uint8_t* instruction);
void instruction_prnl(emulator_t* emulator, uint8_t* instruction);
void instruction_prnt(emulator_t* emulator, uint8_t* instruction);
void instruction_dump(emulator_t* emulator, uint8_t* instruction);
void instruction_halt(emulator_t* emulator, uint8_t* instruction);
void instruction_mul(emulator_t* emulator, uint8_t* instruction);
void instruction_div(emulator_t* emulator, uint8_t* instruction);
void instruction_lsl(emulator_t* emulator, uint8_t* instruction);
void instruction_lsr(emulator_t* emulator, uint8_t* instruction);
#endif
