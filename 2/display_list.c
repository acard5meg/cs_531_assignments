#include "header.h"

void display_list(struct address_t *ip4) {
    if (ip4 == NULL) {
        printf("The list is empty!\n");
        return;
    }

    struct address_t *temp_ptr = ip4;
    int num_nodes = 0;

    while (temp_ptr != NULL) {
        display_node(temp_ptr);
        num_nodes++;
        temp_ptr = temp_ptr -> next;
    }
    printf("Number of nodes in the list: %d\n", num_nodes);

    free(temp_ptr);
}

void display_node(struct address_t *curr_node) {
    printf("Address: ");

    int i;
    for (i = 0; i < IP_LENGTH-1; i++)
        printf("%d.", curr_node -> octet[i]);
    printf("%d\n", curr_node -> octet[i]);

    printf("Alias: %s\n", curr_node -> alias);
}