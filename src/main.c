#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "io.h"
#include "tree.h"
#include "instructions/instruction.h"
#include "emulator.h"

int main(int argc, char *argv[]) {
  uint8_t* bytes;
  long filelen;
  
  if (argc > 1) {
    bytes = get_bytes_from_file(argv[1], &filelen);
    printf("%d, %d\n", bytes[0], bytes[1]);
  } else {
    printf("No file was given.\n");
    return 0;
  }

  tree_t* opcode_tree = init_opcode_tree();
  
  emulator_t* e = init_emulator(NUM_REGISTERS, MEM_SIZE, STACK_SIZE);

  while (e->pc < filelen) {
    run_instruction(opcode_tree, bytes + e->pc, e);
    e->pc += 4;
    e->instructions++;
  }

  printf("\nExtra Statistics:\n");
  printf("----------------------\n");
  printf("Unpipelined Cycles: %lu\n", e->instructions);
  printf("Pipelined Cycles: %lu\n", e->instructions * 5 + e->no_bypass_bubbles);
  printf("Data Hazards: %u\n", e->data_hazards);
  printf("Control Hazards: %u\n", e->control_hazards);
  printf("Pipelined Cycles: %lu\n", e->instructions * 5 + e->bypass_bubbles);
    
  return 0;
}
