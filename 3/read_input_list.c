
#include "header.h"

void read_input_list(struct address_t **addr, MYSQL *conn) {

    char query[255];

    sprintf(query, "SELECT * FROM %s", TABLE_NAME);

    mysql_query(conn, query);
    // printf("Query: %s", query);

    // mysql_query(conn, "SELECT * FROM CS531_Inet");
    
    MYSQL_RES *result = mysql_store_result(conn);

    MYSQL_ROW row;
    while ((row = mysql_fetch_row(result))) {
        struct address_t *new_node = malloc(sizeof(struct address_t));
        char temp_str[75];
        int first, second, third, fourth, total_read_alias, total_read_ip4;

        total_read_ip4 = sscanf(row[0], "%d.%d.%d.%d", &first, &second, &third, &fourth);
        total_read_alias = sscanf(row[1], "%s", temp_str);
        int string_len = strlen(temp_str);

        if (total_read_ip4 != 4 || total_read_alias != 1) {
            printf("Invalid input!\n");
            continue;
        }
        if (! valid_ip(first)) {
            printf("Invalid first IP entry: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
        else if (! valid_ip(second)) {
            printf("Invalid second IP entry: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
        else if (! valid_ip(third)) {
            printf("Invalid third IP entry: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
        else if (! valid_ip(fourth)) {
            printf("Invalid fourth IP entry: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
        else if (string_len == 0 || string_len > 10) {
            printf("Invalid alias: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }


        new_node -> octet[0] = first;
        new_node -> octet[1] = second;
        new_node -> octet[2] = third;
        new_node -> octet[3] = fourth;

        int i = 0;
        for ( ; temp_str[i] != '\0'; i++) {
            new_node -> alias[i] = temp_str[i];
        }

        new_node -> alias[i] = temp_str[i];

        // printf("first: %d\nsecond: %d\nthird: %d\nfourth: %d\nalias: %s\n", 
        //     new_node -> octet[0],
        //     new_node -> octet[1],
        //     new_node -> octet[2],
        //     new_node -> octet[3],
        //     new_node -> alias);

        if (check_duplciates(*addr, new_node)) {
            printf("Already in list: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
    
        new_node -> next = *addr;

        *addr = new_node;
    }
    mysql_free_result(result);

}