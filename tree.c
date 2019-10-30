#include "tree.h"
#include <stddef.h>
#include <stdlib.h>

void tree_init(tree_t *t) {
    t->root = malloc(sizeof(tree_node_t));
    t->root->parent = NULL;
}

tree_node_t *tree_insert(tree_t *t, char *bs, void (*fun_ptr)(uint16_t*, uint8_t*)) {
    tree_node_t *cur = t->root;
    char *ptr;
    for (ptr = bs; *ptr != '\0'; ptr++) {
        int index = *ptr == '0' ? 0 : 1;
        if (!cur->children[index]) {
            cur->children[index] = malloc(sizeof(tree_node_t));
            cur->children[index]->parent = cur;
        }
        cur = cur->children[index];
    }
    cur->fun_ptr = fun_ptr;
    return cur;
}

void (*get_value(tree_t *t, char *bs))(uint16_t*, uint8_t*) {
    tree_node_t *cur = t->root;
    char *ptr;
    for (ptr = bs; *ptr != '\0'; ptr++) {
        int index = *ptr == '0' ? 0 : 1;
        if (!cur->children[index])
            return NULL;
        cur = cur->children[index];
    }
    return cur->fun_ptr; 
}

tree_node_t *tree_insert_op(tree_t *t, uint16_t opcode, uint8_t oplength, void (*fun_ptr)(uint16_t*, uint8_t*)) {
    tree_node_t *cur = t->root;
    uint16_t offset = 10;
    uint8_t i;
    for (i = oplength; i > 0; i--) {
      uint8_t index = (opcode & (1 << offset)) == 0 ? 0 : 1;
      if (!cur->children[index]) {
          cur->children[index] = malloc(sizeof(tree_node_t));
          cur->children[index]->parent = cur;
      }
      cur = cur->children[index];
      offset--;
    }
    cur->fun_ptr = fun_ptr;
    return cur;
}

void (*get_value_op(tree_t *t, uint8_t *opcode))(uint16_t*, uint8_t*) {
  tree_node_t *cur = t->root;
  short offset = 7;
  while (!cur->fun_ptr) {
    if(offset < 0) {
      offset = 7;
      opcode++; //go to the next byte, assuming big-endian output
    }
    uint8_t index = (*opcode >> offset--) & 1;
    cur = cur->children[index];
    if (!cur) {
      return NULL;
    }
  }
  return cur->fun_ptr; 
}
