// This file contains the code to execute menu option
// 4) Delete address
#include "header.h"

void delete_address(struct address_t **curr_ip4) {

    char *error_message = "Alias doesn't exixt!\n";

    // if (curr_ip4 == NULL) {
    if (*curr_ip4 == NULL) {
        printf("List is empty, alias not present!\n");
        return;
    }

    char user_input[ALIAS_LEN + 1];

    printf("Please enter an alias: ");

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

    return_val = find_node(*curr_ip4, user_input);

    if (return_val == NULL) {
        printf("%s", error_message);
    }
    // else if (size(*curr_ip4) == 1) {
    //     *curr_ip4 = NULL;
    // }
    else {
        bool delete = confirm_deletion(return_val);

        if (delete)
            // remove_node(curr_ip4, user_input);
            *curr_ip4 = delete_node(*curr_ip4, user_input);
    }


}

// We've prevented a situation where the alias DNE in the list
// Pointer to a pointer to allow the function to update the 
// linked list inside the function and not return something
// void remove_node(struct address_t **ipv4, char curr_alias[]) {

//     if (equal_name2((*ipv4) -> alias, curr_alias)) {
//         *ipv4 = (*ipv4) -> next;
//         return;
//     }

//     struct address_t *fast = (*ipv4) -> next;
//     struct address_t *slow = (*ipv4);

//     while (fast != NULL && ! equal_name2(fast -> alias, curr_alias)) {
//         slow = fast;
//         fast = fast -> next;
//     }

//     slow -> next = fast -> next;
// }

// The get_deletion() function ensures we'll either have a Y or N
// so the return statement doesn't need to be inside a loop
bool confirm_deletion(struct address_t *curr_node) {
    int i;
    for (i = 0; i < IP_LENGTH-1; i++)
        printf("%d.", curr_node -> octet[i]);
    printf("%d\n", curr_node -> octet[i]);

    char to_delete = get_deletion();

    return (to_delete == 'Y') ? true : false;

}

char get_deletion(void) {

    char delete_confirm, inp_char;
    int num_of_letters;

    // Used to control printing the prompt if user inputs the sort letter incorrectly
    bool first_time = true; 
    printf("Please confirm you wish to delete this node Y/N: ");

    do {
        delete_confirm = ' ';
        num_of_letters = 0;

        if (! first_time)
            printf("Please enter either \'Y\' or \'N\': ");

        // deals with user entering ' A' or 'A '
        // assuming this is still a correct input, but the user accidently hit the space bar
        while ((inp_char = getchar()) != '\n') {
            if (inp_char == ' ')
                continue;
            else {
                delete_confirm = inp_char;
                num_of_letters++;
            }
        }

        first_time = false;

    // need num_of_letters because if user enters jghA inp_char would
    // be set to 'A'; however, this is incorrect based on the problem
    // specification since we can only allow the user to enter 'A' or 'D'
    } while (num_of_letters != 1 || (delete_confirm != 'Y' && delete_confirm != 'N'));

    return delete_confirm;
}
