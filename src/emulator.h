#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdint.h>
#define NUM_REGISTERS 32
#define MEM_SIZE 4096
#define STACK_SIZE 512

typedef struct emulator_t {
  int64_t* registers;
  uint8_t* memory;
  uint8_t* stack;
  uint8_t* frame;
  short condition_codes[14];
  uint64_t pc;
  int8_t cur; //currently written register, -1 if nothing being written, +32 if from ALU
  int8_t prev; //most recently written register
  int8_t gap; //second most recently written register
  uint64_t cycles; //instructions read
  uint32_t data_hazards[4]; //mem prev, mem gap, alu prev, alu gap
  uint32_t control_hazards;
} emulator_t;

emulator_t* init_emulator(uint8_t num_registers, uint16_t memory_size, uint16_t stack_size);

void destroy_emulator(emulator_t* emulator);

#endif
