#include "emulator.h"
#include <stdlib.h>

emulator_t* init_emulator(uint8_t num_registers, uint16_t memory_size, uint16_t stack_size) {
  emulator_t* e = malloc(sizeof(emulator_t));
  e->registers = malloc(num_registers * sizeof(int64_t));
  e->memory = malloc(memory_size * sizeof(uint8_t));
  e->stack = malloc(stack_size * sizeof(uint8_t));
  e->frame = malloc(stack_size * sizeof(uint8_t));

  for (int i = 0; i < num_registers; i++) {
    e->registers[i] = 0;
  }

  for (int i = 0; i < memory_size; i++) {
    e->memory[i] = 0;
  }

  for (int i = 0; i < stack_size; i++) {
    e->stack[i] = 0;
    e->frame[i] = 0;
  }

  for (int i = 0; i < 14; i++) {
    e->condition_codes[i] = 0;
  }

  //TODO: init FP + SP
  
  return e;
}
