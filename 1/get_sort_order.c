#include "header.h"

char get_sort_order(void) {

    char sort_order, inp_char;
    int num_of_letters;

    // Used to control printing the prompt if user inputs the sort letter incorrectly
    bool first_time = true; 
    printf("Print character strings in Ascending or Descending order: ");

    do {
        sort_order = ' ';
        num_of_letters = 0;

        if (! first_time)
            printf("Please enter either \'A\' or \'D\': ");

        // deals with user entering ' A' or 'A '
        // assuming this is still a correct input, but the user accidently hit the space bar
        while ((inp_char = getchar()) != '\n') {
            if (inp_char == ' ')
                continue;
            else {
                sort_order = inp_char;
                num_of_letters++;
            }
        }

        first_time = false;

    // need num_of_letters because if user enters jghA inp_char would
    // be set to 'A'; however, this is incorrect based on the problem
    // specification since we can only allow the user to enter 'A' or 'D'
    } while (num_of_letters != 1 || (sort_order != 'A' && sort_order != 'D'));

    return sort_order;
}
