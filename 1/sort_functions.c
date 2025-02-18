#include "header.h"

// Both versions of merge sort implemented below 
// are standard textbook definitions 
// with strcmp used to determine whether to
// fill the array from the left or right side

// ascending version of merge sort
void ascendingSort(int length, char** arr) {

    if (length > 1) {
        int add_one = length % 2;
        int left_len = length / 2 + add_one, right_len = length / 2; 


        char *left_arr[left_len], *right_arr[right_len];

        create_arr(0, left_len, arr, left_arr);
        create_arr(left_len, length, arr, right_arr);

        ascendingSort(left_len, left_arr);
        ascendingSort(right_len, right_arr);

        int left_idx = 0, right_idx = 0, overall_idx = 0, comp;

        while (left_idx < left_len && right_idx < right_len) {

            comp = strcmp(left_arr[left_idx], right_arr[right_idx]);

            if (comp <= 0) {
                arr[overall_idx] = left_arr[left_idx];
                left_idx++;
            }
            else {
                arr[overall_idx] = right_arr[right_idx];
                right_idx++;
            }
            overall_idx++;
        }

        while (left_idx < left_len) {
            arr[overall_idx] = left_arr[left_idx];
            left_idx++;
            overall_idx++;
        }

        while (right_idx < right_len) {
            arr[overall_idx] = right_arr[right_idx];
            right_idx++;
            overall_idx++;
        }
    }
}

// descending version of merge sort
void descendingSort(int length, char** arr) {

    if (length > 1) {
        int add_one = length % 2;
        int left_len = length / 2 + add_one, right_len = length / 2; 


        char *left_arr[left_len], *right_arr[right_len];

        create_arr(0, left_len, arr, left_arr);
        create_arr(left_len, length, arr, right_arr);

        descendingSort(left_len, left_arr);
        descendingSort(right_len, right_arr);

        int left_idx = 0, right_idx = 0, overall_idx = 0, comp;

        while (left_idx < left_len && right_idx < right_len) {

            comp = strcmp(left_arr[left_idx], right_arr[right_idx]);

            if (comp >= 0) {
                arr[overall_idx] = left_arr[left_idx];
                left_idx++;
            }
            else {
                arr[overall_idx] = right_arr[right_idx];
                right_idx++;
            }
            overall_idx++;
        }

        while (left_idx < left_len) {
            arr[overall_idx] = left_arr[left_idx];
            left_idx++;
            overall_idx++;
        }

        while (right_idx < right_len) {
            arr[overall_idx] = right_arr[right_idx];
            right_idx++;
            overall_idx++;
        }
    }
}

// creates the new arrays which are recursed in merge sort
void create_arr(int start, int end, char **arr, char **arr_to_fill) {

    int fill_idx = 0;

    for (int i = start; i < end; i++) {
        arr_to_fill[fill_idx++] = arr[i];
    }

}

// allows single function to be called from main() to sort array
void use_sort(char sort_order, int arr_length, char **arr) {
    if (sort_order == 'A')
        ascendingSort(arr_length, arr);
    else
        descendingSort(arr_length, arr);
}
