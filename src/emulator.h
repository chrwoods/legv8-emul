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
  int8_t bypass[3]; //current + last 2 written registers, -1 if nothing being written, +32 if from ALU
  int8_t no_bypass[3]; //same as above
  uint64_t instructions; //instructions read
  uint32_t bypass_bubbles;
  uint32_t no_bypass_bubbles;
  uint32_t data_hazards;
  uint32_t control_hazards;
} emulator_t;

emulator_t* init_emulator(uint8_t num_registers, uint16_t memory_size, uint16_t stack_size);

void destroy_emulator(emulator_t* emulator);

#endif
