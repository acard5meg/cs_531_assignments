#include "header.h"

void display_alias(struct address_t *ip4) {

    if (ip4 == NULL) {
        printf("List is empty!\n");
        return;
    }

    printf("Please enter the address location in the following format: ");
    printf("X X, where X is between 0 and 255\n");

    int first, second;
    first = get_ip_component(' ');

    while (first < 0) {
        printf("Invalid input, please re-enter: ");
        first = get_ip_component(' ');
    }

    second = get_second_ip_component();
    while (second < 0) {
        printf("Invalid input, please re-enter: ");
        second = get_second_ip_component();
    }

    alias_address_pairs(ip4, first, second);

    
}

void alias_address_pairs(struct address_t *curr_list, int first, int second) {

    struct address_t *temp_ptr = curr_list;

    while (temp_ptr != NULL) {
        if (temp_ptr -> octet[0] == first && temp_ptr -> octet[1] == second)
            printf("Address: %d. %d. %d. %d. Alias: %s\n", temp_ptr -> octet[0],
                temp_ptr -> octet[1], temp_ptr -> octet[2], temp_ptr -> octet[3],
                temp_ptr -> alias);
        temp_ptr = temp_ptr -> next;
    }

    free(temp_ptr);
}

int get_second_ip_component(void) {
    // has to check the value is [0, 255] and only contains digits
    // go up to the period, ASCII 46

    char temp_inp, curr_inp[IP_LENGTH+1];
    int num_inps = 0;

    temp_inp = getchar();

    while (temp_inp == ' ')
        temp_inp = getchar();

    // the period checks for the end of the ip component and 
    // we know the value is bounded by 255 so there can't be more than 
    // 3 digits in this component
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n' && num_inps < 3) {
    // while (((temp_inp = getchar()) != '.' ) && temp_inp != '\n') {
    while (temp_inp != '\n') {
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

        temp_inp = getchar();
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

