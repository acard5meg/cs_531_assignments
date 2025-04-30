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

struct address_t* delete_node(struct address_t *root, char key[])
{
    if (root == NULL)
    {
        return root;
    }

    int comp_val = equal_name2(root -> alias, key);

    // if (key < root->data)
    if (comp_val > 0)
    {
        root->leftChild = delete_node(root->leftChild, key);
    }
    // else if (key > root->data)
    else if (comp_val < 0)
    {
        root->rightChild = delete_node(root->rightChild, key);
    }
    else
    {
        if (root->leftChild == NULL)
        {
            struct address_t *temp = root->rightChild;
            free(root);
            return temp;
        }
        else if (root->rightChild == NULL)
        {
            struct address_t *temp = root->leftChild;
            free(root);
            return temp;
        }
        struct address_t *temp = find_smallest_node(root->rightChild);

        char temp_str[75];

        int i = 0;
        for (; temp->alias[i] != '\0'; i++)
            temp_str[i] = temp->alias[i];

        temp_str[i] = '\0';

        strcpy(root->alias, temp_str);

        root->rightChild = delete_node(root->rightChild, temp->alias);
    }
    return root;
 
}

struct address_t* find_smallest_node(struct address_t *root)
{
    struct address_t *curr = root;

    while (curr != NULL && curr->leftChild != NULL)
    {
        curr = curr->leftChild;
    }
    return curr;
}

