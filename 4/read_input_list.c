
#include "header.h"

void read_input_list(struct address_t **addr) {

    char *filename;
    FILE *f;
    bool bad_filename = true;

    while (bad_filename) {
        filename = get_filename();

        f = fopen(filename, "r");

        if (f == NULL) 
            printf("Invalid filename. Please re-enter\n");
        else
            bad_filename = false;
    }
    // arbitrary, but no guidance
    char file_line[100];

    struct address_t *temp = *addr;
    
    while (fgets(file_line, 100, f))
    {
        struct address_t *new_node = malloc(sizeof(struct address_t));
        if( new_node == NULL ) {
            puts("Can't allocate memory!");
            exit(0);
        }
        int first, second, third, fourth, total_read;
        char temp_str[75];
        total_read = sscanf(file_line, "%d.%d.%d.%d %s", &first, &second, &third, &fourth, temp_str);

        int string_len = strlen(temp_str);

        if (total_read != 5) {
            printf("Invalid input!\n");
            continue;
        }
    
        // Checks each IPv4 entry is within 8 bit range or stops execution and 
        // returns to main
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

        // printf("ABOVE\nNEW NODE: %s\n", new_node -> alias);
        // if (*addr != NULL)
        //     printf("CURRENT NODE: %s\n", (*addr) -> alias);

        // printf("Current comp: %s\n\n", new_node->alias);

        if (check_duplciates(*addr, new_node)) {
            printf("Already in list: %d.%d.%d.%d %s\n", first, second, third, fourth, temp_str);
            continue;
        }
        
        // printf("BELOW\nNEW NODE: %s\n", new_node -> alias);
        
        new_node -> leftChild = NULL;
        new_node -> rightChild = NULL;
        
        // printf("NEW COMP\n\n");
        
        add_node(addr, new_node);

        // printf("NEW COMP\n\n");
        // if (*addr != NULL)
        // printf("CURRENT NODE: %s\n", (*addr) -> alias);
        // new_node -> next = *addr;

        // *addr = new_node;
    }

    fclose(f);

}