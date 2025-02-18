#include "header.h"

void inputStings(int num_of_strings) {

    printf("Enter %d character strings:\n\n", num_of_strings);

}

void sort_type_print(char sort_type, int arr_length, char **arr) {

    // arr is a sorted array in either ascending or descending
    // order based on sort_type

    if (sort_type == 'A')
        printf("Ascending ");
    else
        printf("Descending ");

    printf("order:\n\n");

    for (int i = 0; i < arr_length; i++) {
        printf("%s\n", arr[i]);
    }
    printf("\n");

    // Based off assumption that input arr is already sorted so
    // the strings with the lowest and highest ascii values
    // are the first and last characters
    if (sort_type == 'A') {
        printf("String with lowest ascii value: %s\n", arr[0]);
        printf("String with highest ascii value: %s\n", arr[arr_length-1]);
    }
    else {
        printf("String with lowest ascii value: %s\n", arr[arr_length-1]);
        printf("String with highest ascii value: %s\n", arr[0]);
    }

}
