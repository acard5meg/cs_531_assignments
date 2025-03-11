#include "header.h"

int main(void) {

    struct address_t *ip4_addr = NULL, *temp_ptr = NULL;
    // struct address_t *struct_ptr = &ip4_addr;

    int num_addresses = 0;
    int curr_inp;
    char *user_prompt, *error_prompt, *duplicate_input;
    user_prompt = "Please choose a menu option: ";
    error_prompt = "Incorrect option, please enter again: ";
    duplicate_input = "Duplicate input, please enter again\n";

    while (true) {
        display_menu();
        curr_inp = get_user_input(user_prompt, error_prompt);
        // printf("%d %c", curr_inp, curr_inp);

        switch(curr_inp) {
            case 1: add_address(&ip4_addr); num_addresses++; break;
            case 2: lookup_addr(ip4_addr); break;
            case 3: update_addr(ip4_addr); break;
            case 4: delete_address(ip4_addr); break;
            case 5: display_list(ip4_addr); break;
            case 6: display_alias(ip4_addr); break;
            case 7: save_list(ip4_addr); break;
            case 8: quit(); break;
            // NO DEFAULT CASE BECAUSE get_user_input() DOES ERROR CHECKING
        }
        // int temp = get_ip_component();
        // printf("Return value from function: %d\n", temp);
        // add_address(ip4_addr);
        // if (add_address(struct_ptr))


        // add_address(&ip4_addr);
        // num_addresses++;
        // display_list(ip4_addr);
        /**
        if ((temp_ptr = add_address(ip4_addr)) != NULL) {
            ip4_addr = temp_ptr;
            // if (ip4_addr == NULL)
            //     ip4_addr = temp_ptr;
            // else
            //     temp_ptr = ip4_addr;
            num_addresses++;
        }
        else
            printf("%s", duplicate_input);
        */


        // display_menu();
        // curr_inp =  get_user_input(user_prompt, error_prompt);
        // num_addresses++;
    }

    // lookup_addr(ip4_addr);
    // update_addr(ip4_addr);
    // delete_address(ip4_addr);
    // display_list(ip4_addr);
    // delete_address(ip4_addr);
    // display_list(ip4_addr);
    // display_alias(ip4_addr);
    // save_list(ip4_addr);
    // quit();
    
    

    return 0;
}
