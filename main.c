#include <stdio.h>
#include <stdint.h>
#include "io.h"
#include "tree.h"
#include <stdlib.h>
void doshit(uint16_t *num1, uint8_t *num2) {
    printf("%d, %d\n",*num1,*num2);
}


int main(int argc, char *argv[]) {
  /*if (argc > 1) {
    uint8_t* bytes = get_bytes_from_file(argv[1]);
    printf("%d, %d\n", bytes[0], bytes[1]);
  } else {
    printf("No file was given.\n");
  }*/
  
  uint16_t a = (1 << 9) + 1;
  uint8_t b = 120;
  uint16_t *pA = &a;
  uint8_t *pB = &b;
  /*doshit(pA, pB);*/

  /*void (*doshit_ptr)(uint16_t*, uint8_t*) = &doshit;*/
  tree_t *t = malloc(sizeof(tree_t)); 
  tree_init(t);
  char* bs = "101";
  uint16_t opcode = 5 << 8;
  tree_node_t *leaf = tree_insert(t,bs,doshit);
  (*leaf->fun_ptr)(pA,pB);
  void (*doshit_ptr)(uint16_t*,uint8_t*) = get_value(t,bs);
  (*doshit_ptr)(pA,pB);

  return 0;
}
