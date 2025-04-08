// This file contains the code to execute menu option
// 3) Update address
#include "header.h"

void update_addr(struct address_t *ipv4) {
    char *error_message = "Alias doesn't exixt!\n", 
    *user_prompt = "Please enter an alias: ";

    char user_input[ALIAS_LEN + 1];

    // list is empty
    if (ipv4 == NULL) {
        printf("%s", error_message);
        return;
    }
        

    printf("%s", user_prompt);

    char temp_inp;
    int num_inps = 0;

    while ((temp_inp = getchar()) != '\n' && num_inps < ALIAS_LEN) {
        user_input[num_inps++] = temp_inp;
    }

    if (num_inps == ALIAS_LEN && temp_inp != '\n') {
        printf("%s", error_message);
        return ;
    }

    user_input[num_inps] = '\0';

    struct address_t *return_val;

    return_val = find_node(ipv4, user_input);

    if (return_val == NULL)
        printf("%s", error_message);
    else {
        update_alias_addr(return_val, ipv4);
    }

}

// If the node alias is found in the linked list this returns a pointer
// to that node, otherwise returns a NULL value
struct address_t* find_node(struct address_t *ipv4, char curr_alias[]) {

    if (ipv4 == NULL)
        return NULL;

    struct address_t *temp_ptr = ipv4;

    while (temp_ptr != NULL) {
        if (equal_name2(temp_ptr -> alias, curr_alias)) {
            return temp_ptr;
        }
        else {
            temp_ptr = temp_ptr -> next;
        }
    }

    return NULL;

}

// Does case insensitive name checking
bool equal_name2(char curr_ip4[], char new_ip4[]) {
    

    if (strlen(curr_ip4) != strlen(new_ip4))
        return false;

    char curr_arr[11], new_arr[11];
    int i = 0;
    for (; ((curr_ip4[i] != '\0') && (new_ip4[i] != '\0')); i++) {
        curr_arr[i] = tolower(curr_ip4[i]);
        new_arr[i] = tolower(new_ip4[i]);
    }

    curr_arr[i] = '\0';
    new_arr[i] = '\0';

    if (strcmp(curr_arr, new_arr) != 0)
        return false;


    return true;
}

// If user confirms they wish to update the address for the alias this function
// reads in the new address, does error checking for the entry then updates
// the linked list
void update_alias_addr(struct address_t *curr_node, struct address_t *whole_list) {
    int i;
    for (i = 0; i < IP_LENGTH-1; i++)
        printf("%d.", curr_node -> octet[i]);
    printf("%d\n", curr_node -> octet[i]);

    printf("Please enter the new address for the alias: ");

    // bool not_valid_address = true;
    int address[IP_LENGTH];
    int total_read;
    char input_string[100];

    total_read = sscanf(fgets(input_string, 100, stdin), "%d.%d.%d.%d", &address[0], &address[1], &address[2], &address[3]);

    if (total_read != 4) {
        printf("Invalid input!\n");
        return;
    }

    if (! valid_ip(address[0])) {
        printf("Invalid first IP entry.\n");
        return;
    }
    else if (! valid_ip(address[1])) {
        printf("Invalid second IP entry.\n");
        return;
    }
    else if (! valid_ip(address[2])) {
        printf("Invalid third IP entry.\n");
        return;
    }
    else if (! valid_ip(address[3])) {
        printf("Invalid fourth IP entry.\n");
        return;
    }


    if (! check_duplciate_addr(address, whole_list)) {
        for (int i = 0; i < IP_LENGTH; i++)
            curr_node -> octet[i] = address[i];
    }
    else {
        printf("Duplicate address\n");
    }
}

bool check_duplciate_addr(int curr_addr[], struct address_t *all_ipv4) {

    if (all_ipv4 == NULL)
        return false;

    struct address_t *temp_ptr = all_ipv4;
    
    while (temp_ptr != NULL) {
        if (equal_addresses(curr_addr, temp_ptr)) {
            return true;
        }
        else {
            temp_ptr = temp_ptr -> next;
        }
    }
    return false;
}

bool equal_addresses(int curr_addr[], struct address_t *curr_node) {

    for (int i = 0; i < IP_LENGTH; i++) {
        if (curr_addr[i] != curr_node -> octet[i])
            return false;
    }

    return true;
}