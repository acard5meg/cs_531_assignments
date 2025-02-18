#include "header.h"

char* get_string(int curr_string_num, int MAX_SIZE, int MIN_SIZE) {

    // We may not use all the size allocated for inp_string but we 
    // need somewhere to store the characters until we finish reading 
    // input. We'll return a pointer to a string array with the exact size
    // of the input string to save space once we determine the input
    // string length
    char inp_string[MAX_SIZE];
    int str_len = 0;
    char c;

    printf("Enter string %d: ", curr_string_num);

    while ((c = getchar()) != '\n') {

        // If there is an legal character this returns true
        if (! checkLegalCharacters(c)) {
            printf("Error: %c Is an illegal character - please re-enter\n", c);
            // If there is an invalid character we break the loop, but need to clear 
            // the input stream to prevent any spillover from the current
            // input when the user re-enters 
            clear_input_stream();
            return NULL;
        }

        // the input string is allowed to be within length [MIN_SIZE, MAX_SIZE]
        // this corresponds to str_len [MIN_SIZE-1, MAX_SIZE-1]
        // if str_len == MAX_SIZE and the loop hasn't broken the user has entered
        // too many characters
        else if (str_len == MAX_SIZE) {
            printf("Error: This string is too long - please re-enter\n");
            clear_input_stream();
            return NULL;
        }
        else {
            inp_string[str_len] = c;
            str_len++;
        }
    }
    
    // Error checking for short string
    // Unlike the error checks above we don't clear the input stream
    // because if the user only enters '\n' clear_input_stream would 
    // get stuck in an infinite loop. Otherwise, we've already cleared
    // the input stream for the user to enter the next word when prompted
    if (str_len < MIN_SIZE) {
        printf("Error: %d is too short of a string - please re-enter\n", str_len);
        return NULL;
    }

    // Final check on the length of the string to ensure it complies 
    // with the problem specifications
    int final_length_check = checkStringLen(inp_string, str_len);

    if (final_length_check < MIN_SIZE) {
        printf("Error: %d is too short of a string - please re-enter\n", str_len);
        return NULL;
    } else if (final_length_check > MAX_SIZE) {
        printf("%d", final_length_check);
        printf("Error: This string is too long - please re-enter\n");
        return NULL;
    }


    char *return_pointer = (char *) malloc(sizeof(char) * ( str_len + 1 ));

    if( return_pointer == NULL ) {
        puts("Can't allocate memory!");
        exit(0);
    }

    char *temp_pointer = return_pointer;

    for (int i = 0; i < str_len; i++, temp_pointer++)
        *temp_pointer = inp_string[i];

    *temp_pointer = '\0';

    return return_pointer;

}

int checkStringLen(char* arr, int str_len) {
    // We know arr is a string so it ends in a null character '\0'

    int str_check = 0;

    for ( ; *arr != '\0' && str_check < str_len; arr++) {
        // printf("%d. %c ", str_len, *arr);
        str_check++;
    }

    return str_check;
}
