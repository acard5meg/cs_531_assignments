// This file contains the code to execute menu option
// 7) Save to file

#include "header.h"

void save_list(struct address_t *ll, MYSQL *conn) {

    if (ll == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct address_t *temp = ll;

    bool is_duplicate;

    char *temp_ip4 = NULL;
    char query[255];

    // delete all tables contents
    sprintf(query, "TRUNCATE TABLE %s", TABLE_NAME);

    mysql_query(conn, query);

    while (temp != NULL) {
        temp_ip4 = ip_to_string(temp -> octet[0], temp -> octet[1],
                temp -> octet[2], temp -> octet[3] );

            sprintf(query, "INSERT INTO %s VALUES('%s','%s')", TABLE_NAME, temp_ip4, temp->alias);
            mysql_query(conn, query);

        temp = temp -> next;
    }

    // HAVE TO CHECK THAT IPV4 AND ALIAS ARE NOT DUPLICATED
    // while (temp != NULL) {
        
        
    //     is_duplicate = false;

    //     sprintf(query, "SELECT * FROM %s", TABLE_NAME);

    //     mysql_query(conn, query);
        
    //     MYSQL_RES *result = mysql_store_result(conn);

    //     MYSQL_ROW row;

    //     while ((row = mysql_fetch_row(result))) {
    //         struct address_t *new_node = malloc(sizeof(struct address_t));
    //         char temp_str[75];
    //         int first, second, third, fourth;

    //         sscanf(row[0], "%d.%d.%d.%d", &first, &second, &third, &fourth);
    //         sscanf(row[1], "%s", temp_str);

    //         new_node -> octet[0] = first;
    //         new_node -> octet[1] = second;
    //         new_node -> octet[2] = third;
    //         new_node -> octet[3] = fourth;

    //         int i = 0;
    //         for ( ; temp_str[i] != '\0'; i++) {
    //             new_node -> alias[i] = temp_str[i];
    //         }

    //         new_node -> alias[i] = temp_str[i];

    //         bool temp_ip = equal_ip(temp, new_node);
    //         bool temp_name = equal_name(temp, new_node);

    //         if (temp_ip || temp_name) {
    //             is_duplicate = true;
    //             free(new_node);
    //             break;
    //         }

    //         free(new_node);

    //     }


    //     mysql_free_result(result);

    //     if (! is_duplicate) {
    //         temp_ip4 = ip_to_string(temp -> octet[0], temp -> octet[1],
    //             temp -> octet[2], temp -> octet[3] );

    //         sprintf(query, "INSERT INTO %s VALUES('%s','%s')", TABLE_NAME, temp_ip4, temp->alias);
    //         mysql_query(conn, query);
    //     }

    //     temp = temp -> next;
    // }

}

char *ip_to_string(int first, int second, int third, int fourth) {
    char first_str[4], second_str[4], third_str[4], fourth_str[4];

    int one_write, two_write, three_write, four_write;

    one_write = sprintf(first_str, "%d", first) + 1;
    two_write = sprintf(second_str, "%d", second) + 1;
    three_write = sprintf(third_str, "%d", third) + 1;
    four_write = sprintf(fourth_str, "%d", fourth);

    int to_ret_len = one_write + two_write + three_write + four_write;

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
