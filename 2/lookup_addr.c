#include "header.h"

#define ALIAS_LEN 10
#define IP_LENGTH 4

void lookup_addr(struct address_t *ipv4) {

    char *error_message = "Alias doesn't exixt!\n", 
        *user_prompt = "Please enter an alias: ";

    char user_input[ALIAS_LEN + 1];

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

    int *return_val;

    return_val = search_list(ipv4, user_input);

    if (return_val == NULL)
        printf("%s", error_message);
    else {
        int i;
        for (i = 0; i < IP_LENGTH-1; i++)
            printf("%d.", return_val[i]);
        printf("%d\n", return_val[i]);
    }
    

}

int* search_list(struct address_t *ipv4, char curr_alias[]) {

    if (ipv4 == NULL)
        return NULL;

    struct address_t *temp_ptr = ipv4;

    // printf("FINISHED LOOP\n");
    while (temp_ptr != NULL) {
        // printf("alias: %s, test_alias: %s\n", temp_ptr -> alias, curr_alias);
        if (strcmp(temp_ptr -> alias, curr_alias) == 0) {
            // printf("FINISHED LOOP\n");
            return temp_ptr -> octet;
        }
        else {
            // printf("FINISHED LOOP 2\n");
            temp_ptr = temp_ptr -> next;
        }
    }

    return NULL;

}