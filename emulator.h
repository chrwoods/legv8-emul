#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdint.h>
#define NUM_REGISTERS 32
#define MEM_SIZE 4096
#define STACK_SIZE 512

typedef struct emulator_t {
  uint64_t* registers;
  uint8_t* memory;
  uint8_t* stack;
  uint8_t* frame;
  short condition_codes[14];
} emulator_t;

emulator_t* init_emulator();
#endif
