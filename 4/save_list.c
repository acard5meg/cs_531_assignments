// This file contains the code to execute menu option
// 7) Save to file

#include "header.h"

void save_list(struct address_t *ll) {

    if (ll == NULL) {
        printf("List is empty!\n");
        return;
    }

    char *filename = get_filename();

    struct address_t *temp = ll;

    FILE *f = fopen(filename, "w");

    if (f == NULL) {
        printf("Couldn't open file!");
        return;
    }

    inorder_save(f, temp);

    fclose(f);

    free(filename);

}

char *get_filename(void) {

    char filename[MAX_FILENAME_LENGTH + 1], user_inp;

    // for now assume the user enters a proper filename
    // Including no invalid characters and proper file extension

    printf("Enter filename.extension for file to save BST to: ");

    int curr_let = 0;

    while ((user_inp = getchar()) != '\n') {
        filename[curr_let++] = user_inp;
    }

    char *return_pointer = (char *) malloc(sizeof(char) * ( curr_let + 1 ));

    if( return_pointer == NULL ) {
        puts("Can't allocate memory!");
        exit(0);
    }

    char *temp_pointer = return_pointer;

    for (int i = 0; i < curr_let; i++, temp_pointer++)
        *temp_pointer = filename[i];

    *temp_pointer = '\0';

    return return_pointer;
}

void inorder_save(FILE *f, struct address_t *node) {
    
    if (node -> leftChild != NULL) {
        inorder_save(f, node -> leftChild);
    }

    if (node != NULL) {
        // display_node(node);
        fprintf(f, "%d.%d.%d.%d %s\n", node -> octet[0], node -> octet[1],
            node -> octet[2], node -> octet[3], node -> alias);
    }

    if (node -> rightChild != NULL) {
        inorder_save(f, node -> rightChild);
    }
}
