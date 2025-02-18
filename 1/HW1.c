
#include "header.h"

// problem defined limits. If the problem changes the 
// length limits or the number of strings change
// definition of macros
#define NUMBER_OF_STRINGS 10
#define MAX_SIZE 25
#define MIN_SIZE 2

int main() {

    char* strs[NUMBER_OF_STRINGS];

    int curr_string = 0;
    char *temp_str;
    char sort_order;

    inputStings(NUMBER_OF_STRINGS);

    while (curr_string < NUMBER_OF_STRINGS){

        // If there is an invalid input the function returns NULL
        temp_str = get_string(curr_string+1, MAX_SIZE, MIN_SIZE);

        // Check the function didn't return NULL
        if (temp_str != NULL) {
            if (! checkDuplicate(curr_string, strs, temp_str)) {
                strs[curr_string] = temp_str;
                curr_string++;
            }
        }
    }

    sort_order = get_sort_order();

    use_sort(sort_order, NUMBER_OF_STRINGS, strs);

    sort_type_print(sort_order, NUMBER_OF_STRINGS, strs);

    return 0;

}
