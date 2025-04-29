// bst_functions.c
#include "header.h"

void add_node(struct address_t **master_list, struct address_t *new_node) {

    if (*master_list == NULL) {
        *master_list = new_node;
        return;
    }

    struct address_t *curr = *master_list, *prev = NULL;
    int comp_val;
    while (curr != NULL)
    {
        prev = curr;

        comp_val = equal_name(curr, new_node);

        if (comp_val > 0)
            curr = curr -> leftChild;
        else
            curr = curr -> rightChild;
    }

    comp_val = equal_name(prev, new_node);

    if (comp_val > 0)
        prev -> leftChild = new_node;
    else
        prev -> rightChild = new_node;
}

int size(struct address_t *node) {
    if (node == NULL)
        return 0;
    return size(node -> leftChild) + size(node -> rightChild) + 1;
}