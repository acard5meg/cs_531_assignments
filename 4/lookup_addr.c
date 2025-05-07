// This file contains the code to execute menu option
// 2) Look up address
#include "header.h"

// Receives user alias then checks the linked list if it exists
// If so print IPv4 address
void lookup_addr(struct address_t *ipv4) {

    if (ipv4 == NULL) {
        printf("The list is empty!\n");
        return;
    }

    char *error_message = "Alias doesn't exixt!\n", 
        *user_prompt = "Please enter an alias: ";

    char user_input[ALIAS_LEN + 1];

    printf("%s", user_prompt);

    char temp_inp;
    int num_inps = 0;

    while ((temp_inp = getchar()) != '\n' && num_inps < ALIAS_LEN) {
        user_input[num_inps++] = temp_inp;
    }

    // If we hit the length limit for an alias and we haven't encountered a 
    // newline the alias is too long and isn't included in the list
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
        int i;
        for (i = 0; i < IP_LENGTH-1; i++)
            printf("%d.", return_val -> octet[i]);
        printf("%d\n", return_val -> octet[i]);
    }
    

}