#ifndef TREE_H
#define TREE_H

#include <stdint.h>
#include "emulator.h"

typedef struct tree_node {
  struct tree_node *parent;
  struct tree_node *children[2];
  void (*fun_ptr)(emulator_t*, uint8_t*); //points to our opcode function handler
} tree_node_t;

typedef struct tree {
  tree_node_t *root;
} tree_t;

void tree_init(tree_t* t);
tree_node_t* tree_insert(tree_t *t, char *bs, void (*fun_ptr)(emulator_t*, uint8_t*));
void (*get_value(tree_t *t, char *bs))(emulator_t*, uint8_t*);
/*Made for passing numbers instead of bit strings*/
void (*get_value_op(tree_t *t, uint8_t *opcode))(emulator_t*, uint8_t*);

#endif
