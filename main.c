#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "io.h"
#include "tree.h"
#include "instruction.h"

void do_stuff(uint16_t *num1, uint8_t *num2) {
    printf("%d, %d\n",*num1,*num2);
}

int main(int argc, char *argv[]) {
  uint8_t* bytes;
  
  if (argc > 1) {
    bytes = get_bytes_from_file(argv[1]);
    printf("%d, %d\n", bytes[0], bytes[1]);
  } else {
    printf("No file was given.\n");
    return 0;
  }

  tree_t* opcode_tree = init_opcode_tree();

  run_instruction(opcode_tree, bytes, 0);
  
  /*uint16_t a = (1 << 9) + 1;
  uint8_t b = 120;
  uint16_t *pA = &a;
  uint8_t *pB = &b;
  
  tree_t *t = malloc(sizeof(tree_t)); 
  tree_init(t);
  char* bs = "101";
  uint8_t opcode = 5 << 5;
  tree_node_t *leaf = tree_insert(t, bs, do_stuff);
  (*leaf->fun_ptr)(pA,pB);
  
  void (*do_stuff_ptr)(uint16_t*,uint8_t*) = get_value_op(t, &opcode);
  (*do_stuff_ptr)(pA,pB);*/

  return 0;
}
