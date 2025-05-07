// This file contains the code to execute menu option
// 5) Display list
#include "header.h"

// Displays the list one node at a time along with the number of nodes in the list
void display_list(struct address_t *ip4) {
    if (ip4 == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct address_t *temp_ptr = ip4;
    int num_nodes = size(ip4);
    inorder_traversal(ip4);
    
    printf("Number of nodes in the list: %d\n", num_nodes);

}

void inorder_traversal(struct address_t *node) {

    if (node == NULL)
        return;
        
    if (node->leftChild != NULL)
    {
        inorder_traversal(node -> leftChild);
    }

    if (node != NULL) {
        display_node(node);
    }

    if (node -> rightChild != NULL) {
        inorder_traversal(node -> rightChild);
    }

}

void display_node(struct address_t *curr_node) {
    printf("Address: ");

    int i;
    for (i = 0; i < IP_LENGTH-1; i++)
        printf("%d.", curr_node -> octet[i]);
    printf("%d. ", curr_node -> octet[i]);

    printf("Alias: %s\n", curr_node -> alias);
}