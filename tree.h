#ifndef TREE_H
#define TREE_H

#include <stdint.h>

typedef struct tree_node {
    struct tree_node *parent;
    struct tree_node *children[2];
    char *value;
} tree_node_t;

typedef struct tree {
    tree_node_t *root;
} tree_t;

void tree_init(tree_t *t);
tree_node_t *tree_insert(tree_t *t, char *bs, char *v);
char *get_value(tree_t *t, char *bs);

#endif
