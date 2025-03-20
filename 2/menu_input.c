#include "header.h"

void display_menu(void) {
    printf("\n\t\tMenu\n");
    printf("1) Add address\n");
    printf("2) Look up address\n");
    printf("3) Update address\n");
    printf("4) Delete address\n");
    printf("5) Display list\n");
    printf("6) Display aliases for location\n");
    printf("7) Save to file\n");
    printf("8) Quit\n");
}

int get_user_input(char *message_to_user, char *error_message) {

    // temp is a dummy variable that will end with a '\n'
    // value and end the loop
    char user_input, temp;
    int num_inputs = 0, int_user_input;
    bool finished = false;

    printf("%s", message_to_user);

    while (! finished) {

        while ((temp = getchar()) != '\n') {
            user_input = temp;
            num_inputs++;
        }

        // val will be called repeatedly in main
        // if the value is 0 this will indicate a bad input
        if (num_inputs != 1) {
            printf("%s ", error_message);
            num_inputs = 0;
            continue;
        }

        // convert the user input to an integer to allow
        // a simple bound check and return
        int_user_input = user_input - '0';
        
        if (int_user_input >= 1 && int_user_input <= 8)
            finished = true;
        else 
            printf("%s", error_message);

        num_inputs = 0;
    }

    return int_user_input;
}
