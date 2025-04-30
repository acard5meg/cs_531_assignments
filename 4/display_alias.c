// This file contains the code to execute menu option
// 6) Display alias for location

#include "header.h"

void display_alias(struct address_t *ip4) {

    if (ip4 == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Please enter the address location in the following format: ");
    printf("X X, where X is between 0 and 255\n");

    bool keep_prompting = true;
    int first, second, total_read;
    char input_string[100], junk;

    // Put inside loop to keep reprompting the user if they enter incorrect values
    while (keep_prompting) {

        // junk is used to catch any character in between the aliases
        // unsure if it is supposed to be ' ' or '.'
        // Assume the input string is 100 characters or less in length
        total_read = sscanf(fgets(input_string, 100, stdin), "%d%c%d", &first, &junk, &second);

        if (! valid_ip(first)) {
            printf("Invalid first IP entry. Please re-enter.\n");
        }
        else if (! valid_ip(second)) {
            printf("Invalid second IP entry. Please re-enter.\n");
        }
        else {
            keep_prompting = false;
        }

    }

    // return value of sscanf must be three because it will also read
    // the junk value between the two IPv4 digits
    if (total_read != 3) {
        printf("Invalid input!\n");
        return;
    }

    alias_address_pairs(ip4, first, second);

    
}

// We've already checked for the situation where the IPv4 list is empty
void alias_address_pairs(struct address_t *curr_list, int first, int second) {

    struct address_t *temp_ptr = curr_list;
    int in_list = check_in_list(temp_ptr, first, second);

    temp_ptr = curr_list;
    if (in_list > 0)
        print_pairs(temp_ptr, first, second);
    else
        printf("Location not in list!\n");
    // if (! in_list)
            
}

void print_pairs(struct address_t *node, int first, int second) {

    if (node -> leftChild != NULL) {
        print_pairs(node -> leftChild, first, second);
    }

    if (node != NULL && node -> octet[0] == first && node -> octet[1] == second) {
        // display_node(node);
        printf("Address: %d.%d.%d.%d. Alias: %s\n", node -> octet[0],
            node -> octet[1], node -> octet[2], node -> octet[3],
            node -> alias);
    }

    if (node -> rightChild != NULL) {
        print_pairs(node -> rightChild, first, second);
    }
}

int check_in_list(struct address_t *node, int first, int second) {
    if (node == NULL)
        return 0;
    if (node -> octet[0] == first && node -> octet[1] == second)
        return 1;
    return check_in_list(node->leftChild, first, second) \
    + check_in_list(node->rightChild, first, second);
}
