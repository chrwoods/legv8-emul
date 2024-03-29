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

  //init SP + FP
  e->registers[28] = stack_size;
  e->registers[29] = stack_size;

  e->pc = 0;

  for (int i = 0; i < 3; i++) {
    e->bypass[i] = -1;
    e->no_bypass[i] = -1;
  }
  
  e->instructions = 0;

  e->bypass_bubbles = 0;
  e->no_bypass_bubbles = 0;

  e->data_hazards = 0;
  e->control_hazards = 0;
  
  return e;
}

void destroy_emulator(emulator_t* emulator) {
  free(emulator->registers);
  free(emulator->memory);
  free(emulator->stack);
  free(emulator->frame);
  free(emulator);
}
