// This file contains the code to execute menu option
// 7) Save to file

#include "header.h"

void save_list(struct address_t *ll, MYSQL *conn) {

    if (ll == NULL) {
        printf("List is empty!\n");
        return;
    }

    // char *filename = get_filename();

    struct address_t *temp = ll;

    // FILE *f = fopen(filename, "w");

    // if (f == NULL) {
    //     printf("Couldn't open file!");
    //     return;
    // }

    char *temp_ip4 = NULL;
    while (temp != NULL) {
        temp_ip4 = ip_to_string(temp -> octet[0], temp -> octet[1],
                temp -> octet[2], temp -> octet[3] );
        
        char query[255];

        sprintf(query, "INSERT INTO %s VALUES('%s','%s')", TABLE_NAME, temp_ip4, temp->alias);
        
        printf("%s\n", query);

        if (mysql_query(conn, query));

        temp = temp -> next;
    }

}

char *ip_to_string(int first, int second, int third, int fourth) {
    char first_str[4], second_str[4], third_str[4], fourth_str[4];

    int one_write, two_write, three_write, four_write;

    one_write = sprintf(first_str, "%d", first) + 1;
    two_write = sprintf(second_str, "%d", second) + 1;
    three_write = sprintf(third_str, "%d", third) + 1;
    four_write = sprintf(fourth_str, "%d", fourth);

    int to_ret_len = one_write + two_write + three_write + four_write;
    printf("length: %d\n", to_ret_len);

    char *to_return = (char *) malloc(sizeof(char) * (to_ret_len + 1));

    if( to_return == NULL ) {
        puts("Can't allocate memory!");
        exit(0);
    }

    char *temp_pointer = to_return;

    int i = 0;

    for (i = 0; i < one_write-1; i++, temp_pointer++)
        *temp_pointer = first_str[i];

    *temp_pointer = '.';
    temp_pointer++;

    for (i = 0; i < two_write-1; i++, temp_pointer++)
        *temp_pointer = second_str[i];

    *temp_pointer = '.';
    temp_pointer++;

    for (i = 0; i < three_write-1; i++, temp_pointer++)
        *temp_pointer = third_str[i];

    *temp_pointer = '.';
    temp_pointer++;

    for (i = 0; i < four_write; i++, temp_pointer++)
        *temp_pointer = fourth_str[i];

    *temp_pointer = '\0';

    return to_return;

}

// char *get_filename(void) {

//     char filename[MAX_FILENAME_LENGTH + 1], user_inp;

    // for now assume the user enters a proper filename
    // Including no invalid characters and proper file extension

//     printf("Enter filename.extension to the linked list: ");

//     int curr_let = 0;

//     while ((user_inp = getchar()) != '\n') {
//         filename[curr_let++] = user_inp;
//     }

//     char *return_pointer = (char *) malloc(sizeof(char) * ( curr_let + 1 ));

//     if( return_pointer == NULL ) {
//         puts("Can't allocate memory!");
//         exit(0);
//     }

//     char *temp_pointer = return_pointer;

//     for (int i = 0; i < curr_let; i++, temp_pointer++)
//         *temp_pointer = filename[i];

//     *temp_pointer = '\0';

//     return return_pointer;
// }