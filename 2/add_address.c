// This file contains the code to execute menu option
// 1) Add address

#include "header.h"

#define IP_LENGTH 4
#define IP_COMPONENT_LENTH 3
#define ALIAS_LENGTH 10

// struct address_t* add_address(struct address_t *addr) {
void add_address(struct address_t **addr) {
    printf("Please enter the IPv4 address and an alias ");

    // TTHIS WILL BE THE FINAL SUBMISSION TEXT
    // printf("Please enter the IPv4 address and an alias ");
    // printf("in the format X.X.X.X alias. The values X must ");
    // printf("be between 0 and 255 inclusive and the alias ");
    // printf("less than or equal to 10 characters: ");

    // initialize node
    bool not_valid_address = true;

    struct address_t *new_node = malloc(sizeof(struct address_t));

    while (not_valid_address) {

        new_node = malloc(sizeof(struct address_t));

        if( new_node == NULL ) {
            puts("Can't allocate memory!");
            exit(0);
        }

        int curr_ip_pos = 0, temp;

        while (curr_ip_pos < IP_LENGTH) {
            // MAKE A SECOND get_ip_component for the last piece and the alias
            if (curr_ip_pos < IP_LENGTH - 1)
                // temp = get_first_ip_component();
                temp = get_ip_component('.');
            else {
                temp = get_ip_component(' ');
                // temp = 1;
                // clear_input_stream();
            }

            // error code for get_ip_component
            if (temp == -1) {
                printf("Invalid input, please re-enter: ");
                free(new_node);
                not_valid_address = true;
                break;
            }
            new_node -> octet[curr_ip_pos] = temp;
            // printf("FINSIHED WITH COMPONENT: %d\n", curr_ip_pos);
            curr_ip_pos++;
            not_valid_address = false;
            
        }
    }

    // char* temp_str = get_alias_component();
    // char* temp_str = malloc(ALIAS_LENGTH * sizeof(char));
    char *temp_str = NULL;

    while (temp_str == NULL) {
        temp_str = get_alias_component();
        // printf("RETURN FROM FUNCT: %s\n", temp_str);
    }

    int i = 0;
    for ( ; *temp_str != '\0'; temp_str++, i++) {
        // printf("CURRENT CHAR: %c\n", *temp_str);
        new_node -> alias[i] = *temp_str;
        // new_node -> alias[i] = *temp_str;
    }
    // new_node -> alias = strcpy(new_node -> alias, temp_str);

    // new_node -> alias[i] = '\0';

    // printf("alias: %s, pointer: %s\n", new_node -> alias, temp_str );
    // *new_node -> alias = "DOUG";

    // struct address_t *temp_ptr = addr;

    // free(temp_str);

    // if (check_duplciates(addr, new_node))
    if (check_duplciates(*addr, new_node)) {
        printf("Already in list!\n");
        return;
    }
        // return NULL;

    

    // new_node -> next = addr;
    new_node -> next = *addr;

    // struct address_t *temp_ptr = new_node;

    *addr = new_node;

    // return new_node;

    // printf("FINISHED LOOP\n");
    // while (temp_ptr != NULL) {
    //     // printf("alias: %s\n", temp_ptr -> alias);
    //     temp_ptr = temp_ptr -> next;
    // }

    

    // if (addr == NULL)
    //     addr = new_node;
    // else
    //     addr -> next = new_node;
    // printf("FINISHED LOOP\n");
        
    // printf("FINISHED LOOP\n");
    // return true;

    // deals with a hanging newline character once we get a good string
    // printf("AT THE END");
    // clear_input_stream();
    // printf("AT THE END2");
}


// int get_first_ip_component(void) {
int get_ip_component(char delimiter) {
    // has to check the value is [0, 255] and only contains digits
    // go up to the period, ASCII 46

    char temp_inp, curr_inp[IP_COMPONENT_LENTH+1];
    int num_inps = 0;


    // the period checks for the end of the ip component and 
    // we know the value is bounded by 255 so there can't be more than 
    // 3 digits in this component
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n' && num_inps < 3) {
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n') {
    while (((temp_inp = getchar()) != delimiter) && temp_inp != '\n') {
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
    if (temp_inp != delimiter  && temp_inp != '\n') {
        clear_input_stream();
        return -1;
    }
    // else if (num_inps <= 3 && temp_inp == '\n')
    //     return -1;
    else if (temp_inp == '\n')
        return -1;

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

char* get_alias_component(void) {
    char temp, alias[ALIAS_LENGTH];

    // removes any spaces between end of IPv4 addr and start of alias
    // while ((temp = getchar()) != ' ') {
    //     ;
    // }
    temp = getchar();

    if (temp == ' ') {
        while (temp == ' ') {
            temp = getchar();
        }
    }

    int alias_pos = 0;

    // assuming any character is a valid character for alias
    while (temp != '\n' && alias_pos < ALIAS_LENGTH) {
        alias[alias_pos++] = temp;
        temp = getchar();
    }

    // user entered \n which is invalid
    if (alias_pos == 0)
        return NULL;

    // more than 10 characters used for alias
    if (alias_pos == ALIAS_LENGTH && temp != '\n') {
        clear_input_stream();
        return NULL;
    }

    // alias[alias_pos] = '\0';

    // create return pointer
    char *return_pointer = (char *) malloc(sizeof(char) * ( alias_pos + 1 ));

    if( return_pointer == NULL ) {
        puts("Can't allocate memory!");
        exit(0);
    }

    char *temp_pointer = return_pointer;

    for (int i = 0; i < alias_pos; i++, temp_pointer++)
        *temp_pointer = alias[i];

    *temp_pointer = '\0';

    // printf("IN FuncTION : %s\n", return_pointer);

    return return_pointer;

}

void clear_input_stream(void) {
    char c;

    while ((c = getchar()) != '\n')
        ;   
}

bool check_duplciates(struct address_t *curr_ip4, struct address_t *new_ip4) {

    if (curr_ip4 == NULL)
        return false;

    struct address_t *temp_ptr = curr_ip4;
    
    while (temp_ptr != NULL) {
        if (equal_structures(temp_ptr, new_ip4)) {
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

bool equal_structures(struct address_t *curr_ip4, struct address_t *new_ip4) {
    if (curr_ip4 -> octet[0] != new_ip4 -> octet[0])
        return false;
    if (curr_ip4 -> octet[1] != new_ip4 -> octet[1])
        return false;
    if (curr_ip4 -> octet[2] != new_ip4 -> octet[2])
        return false;
    if (curr_ip4 -> octet[3] != new_ip4 -> octet[3])
        return false;
    if (strcmp(curr_ip4 -> alias, new_ip4 -> alias) != 0)
        return false;

    return true;
}

bool valid_int_input(char val_to_test) {
    switch (val_to_test) {
        case '0': return true; break;
        case '1': return true; break;
        case '2': return true; break;
        case '3': return true; break;
        case '4': return true; break;
        case '5': return true; break;
        case '6': return true; break;
        case '7': return true; break;
        case '8': return true; break;
        case '9': return true; break;
        default: return false;
    }
}