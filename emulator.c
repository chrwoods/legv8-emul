#include "emulator.h"
#include <stdlib.h>

emulator_t* init_emulator() {
  emulator_t* e = malloc(sizeof(emulator_t));
  e->registers = malloc(NUM_REGISTERS*sizeof(uint64_t));
  e->memory = malloc(MEM_SIZE*sizeof(uint8_t));
  e->stack = malloc(STACK_SIZE*sizeof(uint8_t));
  e->frame = malloc(sizeof(uint8_t));

  return e;
}
