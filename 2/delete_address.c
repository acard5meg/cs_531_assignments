#include "header.h"

void delete_address(struct address_t *curr_ip4) {

    char *error_message = "Alias doesn't exixt!\n";

    if (curr_ip4 == NULL) {
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

    return_val = find_node(curr_ip4, user_input);

    if (return_val == NULL) {
        printf("%s", error_message);
    }
    else {
        bool delete = confirm_deletion(return_val);

        if (delete)
            remove_node(curr_ip4, user_input);

    }


}

// We've prevented a situation where the alias DNE in the list
void remove_node(struct address_t *ipv4, char curr_alias[]) {

    struct address_t *fast = ipv4;
    struct address_t *slow = NULL;

    while (strcmp(fast -> alias, curr_alias) != 0) {
        slow = fast;
        fast = fast -> next;
    }

    slow -> next = fast -> next;
}

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
