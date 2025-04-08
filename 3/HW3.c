#include "header.h"

int main(void) {

    // connect to SQL server and return pointer to connection to 
    // pass into each function
    MYSQL *conn = get_connection();

    // struct address_t *ip4_addr = NULL, *temp_ptr = NULL;
    struct address_t *ip4_addr = NULL;
    struct address_t *temp_ptr = NULL;

    // reads initial list
    read_input_list(&ip4_addr, conn);


    // int num_addresses = 0;
    int curr_inp;
    char *user_prompt, *error_prompt, *duplicate_input;
    user_prompt = "Please choose a menu option: ";
    error_prompt = "Incorrect option, please enter again: ";
    duplicate_input = "Duplicate input, please enter again\n";

    while (true) {
        display_menu();
        curr_inp = get_user_input(user_prompt, error_prompt);

        switch(curr_inp) {
        //     // case 1: add_address(&ip4_addr); num_addresses++; break;
            case 1: add_address(&ip4_addr); break;
            case 2: lookup_addr(ip4_addr); break;
            case 3: update_addr(ip4_addr); break;
            case 4: delete_address(&ip4_addr); break;
            case 5: display_list(ip4_addr); break;
            case 6: display_alias(ip4_addr); break;
            case 7: save_list(ip4_addr, conn); break;
            case 8: quit(conn); break;
            // NO DEFAULT CASE BECAUSE get_user_input() DOES ERROR CHECKING
        }
    }

    return 0;
}
