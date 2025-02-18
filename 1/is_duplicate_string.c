#include "header.h"

bool checkDuplicate(int num_of_strings, char** all_strings, char *curr_string) {

    // if the loop completes and no duplicates are found 
    // the value has defaulted to false 
    bool is_duplicate = false;
    bool is_curr_duplicate;

    for (int i = 0; i < num_of_strings; i++) {
        is_curr_duplicate = strcmp(all_strings[i], curr_string);

        if (is_curr_duplicate == 0) {
            printf("Error: duplicate string - please re-enter\n");
            is_duplicate = true;
            break;
        }
    }

    return is_duplicate;
}
