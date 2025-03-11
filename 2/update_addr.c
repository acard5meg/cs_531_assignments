#include "header.h"

#define ALIAS_LEN 10
#define IP_LENGTH 4

void update_addr(struct address_t *ipv4) {
    char *error_message = "Alias doesn't exixt!\n", 
    *user_prompt = "Please enter an alias: ";

    char user_input[ALIAS_LEN + 1];

    // list is empty
    if (ipv4 == NULL)
        return;

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

struct address_t* find_node(struct address_t *ipv4, char curr_alias[]) {

    if (ipv4 == NULL)
        return NULL;

    struct address_t *temp_ptr = ipv4;

    // printf("FINISHED LOOP\n");
    while (temp_ptr != NULL) {
        // printf("alias: %s, test_alias: %s\n", temp_ptr -> alias, curr_alias);
        if (strcmp(temp_ptr -> alias, curr_alias) == 0) {
            // printf("FINISHED LOOP\n");
            return temp_ptr;
        }
        else {
            // printf("FINISHED LOOP 2\n");
            temp_ptr = temp_ptr -> next;
        }
    }

    return NULL;

}

void update_alias_addr(struct address_t *curr_node, struct address_t *whole_list) {
    int i;
    for (i = 0; i < IP_LENGTH-1; i++)
        printf("%d.", curr_node -> octet[i]);
    printf("%d\n", curr_node -> octet[i]);

    printf("Please enter the new address for the alias: ");

    bool not_valid_address = true;
    int address[IP_LENGTH];

    while (not_valid_address) {

        // new_node = malloc(sizeof(struct address_t));

        // if( new_node == NULL ) {
        //     puts("Can't allocate memory!");
        //     exit(0);
        // }

        int curr_ip_pos = 0, temp;

        while (curr_ip_pos < IP_LENGTH) {
            // MAKE A SECOND get_ip_component for the last piece and the alias
            if (curr_ip_pos < IP_LENGTH - 1) {
                // printf("HERE");
                temp = get_ip_component('.');
            }
            else {
                // printf("HERE 2");
                temp = get_last_ip_component();
                // temp = 1;
                // clear_input_stream();
            }
            
            printf("%d \n", temp);
            // error code for get_ip_component
            if (temp == -1) {
                printf("Invalid input, please re-enter: ");
                // free(new_node);
                not_valid_address = true;
                break;
            }
            // new_node -> octet[curr_ip_pos] = temp;
            address[curr_ip_pos] = temp;
            // printf("FINSIHED WITH COMPONENT: %d\n", curr_ip_pos);
            curr_ip_pos++;
            not_valid_address = false;
            
        }
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
            // printf("FINISHED LOOP\n");
            return true;
        }
        else {
            // printf("FINISHED LOOP 2\n");
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

int get_last_ip_component() {
    // has to check the value is [0, 255] and only contains digits
    // go up to the period, ASCII 46

    char temp_inp, curr_inp[IP_LENGTH+1];
    int num_inps = 0;


    // the period checks for the end of the ip component and 
    // we know the value is bounded by 255 so there can't be more than 
    // 3 digits in this component
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n' && num_inps < 3) {
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n') {
    while ((temp_inp = getchar()) != '\n') {
        // printf("CURRENT CHAR: %c\n", temp_inp);

        if (num_inps == 3) {
            clear_input_stream();
            return -1;
        }

        if (valid_int_input(temp_inp))
            curr_inp[num_inps++] = temp_inp;
        // else if (temp_inp == '\n')
        //     return -1;
        else {
            clear_input_stream();
            return -1;
        }
    }

    curr_inp[num_inps] = '\0';

    // if user enters weird stuff
    if (num_inps == 0) {
        if (temp_inp != '\n')
            clear_input_stream();
        return -1;
    }
    // if (num_inps == 0)
    //     return -1;

    
    // if (temp_inp != '.' && num_inps == 3 && temp_inp != '\n') {
    // if (temp_inp != '.'  && temp_inp != '\n') {
    if (temp_inp != '\n') {
        clear_input_stream();
        return -1;
    }
    // else if (num_inps <= 3 && temp_inp == '\n')
    //     return -1;
    // else if (temp_inp == '\n')
    //     return -1;

    // printf("HERE: %s\t", curr_inp);
    int to_return = (int) strtol(curr_inp, NULL, 10);

    // printf("INTEGER VALUE: %d\n", to_return);
    // strtol

    if (to_return < 0 || to_return > 255) {
        clear_input_stream();
        return -1;
    }
    return to_return;

}

