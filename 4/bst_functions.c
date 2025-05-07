// bst_functions.c
#include "header.h"

void add_node(struct address_t **master_list, struct address_t *new_node) {

    if (*master_list == NULL) {
        *master_list = new_node;
        return;
    }

    struct address_t *curr = *master_list, *prev = NULL;
    int comp_val;
    comp_val = check_all_node_dups(curr, new_node);

    
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
        root->octet[0] = temp->octet[0];
        root->octet[1] = temp->octet[1];
        root->octet[2] = temp->octet[2];
        root->octet[3] = temp->octet[3];

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

int check_all_node_dups(struct address_t *curr_ip4, struct address_t *new_ip4) {
    if (curr_ip4 == NULL)
        return 0;

    int to_add = 0;

    if (equal_structures(curr_ip4, new_ip4))
        to_add++;

    if (curr_ip4->leftChild != NULL)
    {
        // return check_all_node_dups(curr_ip4->leftChild, new_ip4) + to_add;
        to_add += check_all_node_dups(curr_ip4->leftChild, new_ip4);
    }

    // if (curr_ip4 != NULL) {
    //     check_all_alias(curr_ip4);
    // }

    if (curr_ip4 -> rightChild != NULL) {
        // return check_all_node_dups(curr_ip4 -> rightChild, new_ip4) + to_add;
        to_add += check_all_node_dups(curr_ip4 -> rightChild, new_ip4);
    }

    return to_add;
}
// int check_all_address(struct address_t *, struct address_t *) {

// }