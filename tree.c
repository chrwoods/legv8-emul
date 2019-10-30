#include "tree.h"
#include <stddef.h>
#include <stdlib.h>

void tree_init(tree_t *t) {
    t->root = malloc(sizeof(tree_node_t));
    t->root->parent = NULL;
}

tree_node_t *tree_insert(tree_t *t, char *bs, char *v) {
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
    cur->value = v;
    return cur;
}

char *get_value(tree_t *t, char *bs) {
    tree_node_t *cur = t->root;
    char *ptr;
    for (ptr = bs; *ptr != '\0'; ptr++) {
        int index = *ptr == '0' ? 0 : 1;
        if (!cur->children[index])
            return NULL;
        cur = cur->children[index];
    }
    return cur->value; 
}
