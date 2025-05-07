// This file contains the code to execute menu option
// 1) Add address

#include "header.h"

// Pointer to a pointer to allow this function to update the linked list
// within the function and not have to return anything to main
void add_address(struct address_t **addr) {
    
    printf("Please enter the IPv4 address and an alias ");
    printf("in the format X.X.X.X alias.\nThe values X must ");
    printf("be between 0 and 255 inclusive and the alias ");
    printf("less than or equal to 10 characters: ");


    struct address_t *new_node = malloc(sizeof(struct address_t));

    if( new_node == NULL ) {
        puts("Can't allocate memory!");
        exit(0);
    }

    int first, second, third, fourth, total_read;

    // Assuming the user input string is 100 characters or less and the alias is 75 or less
    char temp_str[75], input_string[100];

    // Assuming the user enters the correct format for the IPv4 address
    total_read = sscanf(fgets(input_string, 100, stdin), "%d.%d.%d.%d %s", &first, &second, &third, &fourth, temp_str);

    int string_len = strlen(temp_str);

    if (total_read != 5) {
        printf("Invalid input!\n");
        return;
    }

    // Checks each IPv4 entry is within 8 bit range or stops execution and 
    // returns to main
    if (! valid_ip(first)) {
        printf("Invalid first IP entry.\n");
        return;
    }
    else if (! valid_ip(second)) {
        printf("Invalid second IP entry.\n");
        return;
    }
    else if (! valid_ip(third)) {
        printf("Invalid third IP entry.\n");
        return;
    }
    else if (! valid_ip(fourth)) {
        printf("Invalid fourth IP entry.\n");
        return;
    }
    else if (string_len == 0 || string_len > 10) {
        printf("Invalid alias.\n");
        return;
    }

    new_node -> octet[0] = first;
    new_node -> octet[1] = second;
    new_node -> octet[2] = third;
    new_node -> octet[3] = fourth;

    int i = 0;
    for ( ; temp_str[i] != '\0'; i++) {
        new_node -> alias[i] = temp_str[i];
    }

    new_node -> alias[i] = temp_str[i];

    if (check_duplciates(*addr, new_node)) {
        printf("Already in list!\n");
        return;
    }

    // new_node -> next = *addr;

    new_node -> leftChild = NULL;
    new_node -> rightChild = NULL;

    add_node(addr, new_node);

    // *addr = new_node;
}

bool valid_ip(int alias) {
    return (alias >= 0 && alias <= 255) ? true : false;
}

// CHANGES
bool check_duplciates(struct address_t *curr_ip4, struct address_t *new_ip4) {

    if (curr_ip4 == NULL)
        return false;

    struct address_t *temp_ptr = curr_ip4;
    // bool value;
    int comp_val = check_all_node_dups(temp_ptr, new_ip4);

    // while (temp_ptr != NULL) {

    //     if (equal_structures(temp_ptr, new_ip4)) {
    //         // printf("EQUAL STRUCT\n");
    //         return true;
    //     }
    //     else {
    //         // temp_ptr = temp_ptr -> next;

    //         comp_val = equal_name(temp_ptr, new_ip4);
    //         if (comp_val > 0)
    //             temp_ptr = temp_ptr -> leftChild;
    //         else
    //             temp_ptr = temp_ptr -> rightChild;
    //     }
    // }
    // return false;

    if (comp_val > 0)
        return true;
    else
        return false;
}

// CHANGES
bool equal_structures(struct address_t *curr_ip4, struct address_t *new_ip4) {
    bool ip = equal_ip(curr_ip4, new_ip4);
    int name = equal_name(curr_ip4, new_ip4);

    if (ip || (name == 0))
        return true;
    else
        return false;

}

// NO CHANGES HW 4
// checks IPv4 address is unique, amounts to one entry being different
bool equal_ip(struct address_t *curr_ip4, struct address_t *new_ip4) {

    if (curr_ip4 -> octet[0] != new_ip4 -> octet[0])
        return false;
    if (curr_ip4 -> octet[1] != new_ip4 -> octet[1])
        return false;
    if (curr_ip4 -> octet[2] != new_ip4 -> octet[2])
        return false;
    if (curr_ip4 -> octet[3] != new_ip4 -> octet[3])
        return false;

    return true;
}

// CHANGES HW 4
// checks alias is unique accounting for alias names not being case sensitive
int equal_name(struct address_t *curr_ip4, struct address_t *new_ip4) {
    

    // if (strlen(curr_ip4 -> alias) != strlen(new_ip4 -> alias))
    //     return strcmp;
    //     return 1; // anything other than 0 to denote the names are different

    char curr_arr[11], new_arr[11];
    int i = 0, j= 0;
    // for (; ((curr_ip4 -> alias[i] != '\0') && (new_ip4 -> alias[i] != '\0')); i++) {
    //     curr_arr[i] = tolower(curr_ip4 -> alias[i]);
    //     new_arr[i] = tolower(new_ip4 -> alias[i]);
    // }
    for (; curr_ip4 -> alias[i] != '\0'; i++) {
        curr_arr[i] = tolower(curr_ip4 -> alias[i]);
        // new_arr[i] = tolower(new_ip4 -> alias[i]);
    }
    curr_arr[i] = '\0';

    for (; new_ip4 -> alias[j] != '\0'; j++) {
        // curr_arr[j] = tolower(curr_ip4 -> alias[j]);
        new_arr[j] = tolower(new_ip4 -> alias[j]);
    }
    
    new_arr[j] = '\0';

    int to_return = strcmp(curr_arr, new_arr);
    // printf("NAME COMPARISON: %d\n", to_return);
    return to_return;
    // if (strcmp(curr_arr, new_arr) != 0)
    //     return false;


    // return true;
}