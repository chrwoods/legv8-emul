#ifndef INSTRUCTION_UTILS_H
#define INSTRUCTION_UTILS_H

#include <stdint.h>
#include "../emulator.h"
int32_t get_param(uint8_t* instruction, short offset, short length);
int32_t convert_to_signed(uint32_t to_convert, short length);

void get_r_format_params(uint8_t* instruction, uint8_t* rm, uint8_t* shamt, uint8_t* rn, uint8_t* rd);
void get_d_format_params(uint8_t* instruction, uint16_t* address, uint8_t* op2, uint8_t* rn, uint8_t* rt);
void get_i_format_params(uint8_t* instruction, int16_t* immediate, uint8_t* rn, uint8_t* rd);
void get_b_format_params(uint8_t* instruction, int32_t* address);
void get_cb_format_params(uint8_t* instruction, int32_t* address, uint8_t* rt);
void set_condition_codes(emulator_t* emulator, int64_t result);
void halt(emulator_t* emulator);
int64_t get_reg(emulator_t* emulator, uint8_t index);
void set_reg(emulator_t* emulator, uint8_t index, int64_t value);
int64_t get_data(emulator_t* emulator, uint16_t address, uint8_t reg);
void set_data(emulator_t* emulator, uint16_t address, uint8_t reg, int64_t value);
#endif
