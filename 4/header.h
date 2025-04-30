// header file contains all preprocessor directives
// LESS THAN EQUAL TO IS LEFT <- DONT HAVE DUPLICATES SHOULDNT HAVE EQUALS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define ALIAS_LEN 10
#define IP_LENGTH 4
#define IP_COMPONENT_LENTH 3
// Without guidance assuming an arbitrarty file size length of 260
#define MAX_FILENAME_LENGTH 260
// #define TOTAL_IPV4 3

// global definition for structure used in assignment
struct address_t{
    int octet[4];
    char alias[11];
    struct address_t *leftChild, *rightChild;
} ;

// bst_functions.c // NEW
void add_node(struct address_t **, struct address_t *);
int size(struct address_t *);
struct address_t* delete_node(struct address_t *, char[] );
struct address_t *find_smallest_node(struct address_t *);

//read_input_list.c
void read_input_list(struct address_t **); // CHANGES

// menu_input.c <- FILE UNCHANGED
void display_menu(void); // no changes
int get_user_input(char *, char *); // no changes

// add_address.c
void add_address(struct address_t **); // CHANGES
bool check_duplciates(struct address_t *, struct address_t *); // CHANGES
bool equal_structures(struct address_t *, struct address_t *); // CHANGES
bool equal_ip(struct address_t *, struct address_t *); // no changes
int equal_name(struct address_t *, struct address_t *); // CHANGES
bool valid_ip(int ); // no changes

// lookup_addr.c // NO CHANGES
void lookup_addr(struct address_t *); // no changes

// update_addr.c
void update_addr(struct address_t *); // no changes
struct address_t* find_node(struct address_t *, char []); // CHANGES
void update_alias_addr(struct address_t *, struct address_t *); // no changes
bool check_duplciate_addr(int [], struct address_t *); //CHANGES
bool equal_addresses(int [], struct address_t *); // no changes
int equal_name2(char [], char []); //CHANGES
int duplicate_addr_check(int [], struct address_t *); // NEW

//delete_address.c
void delete_address(struct address_t **); // CHANGES
// void remove_node(struct address_t **, char []);
bool confirm_deletion(struct address_t *); // no changes
char get_deletion(void); // no changes

//display_list.c
void display_list(struct address_t *); // CHANGED
void display_node(struct address_t *); // no change
void inorder_traversal(struct address_t *); // NEW

// display_alias.c
void display_alias(struct address_t *); // no changes
void alias_address_pairs(struct address_t *, int, int); // CHANGES
void print_pairs(struct address_t *, int, int); // NEW
int check_in_list(struct address_t *, int, int); // NEW

//save_list.c
void save_list(struct address_t *); // CHANGES
char *get_filename(void); // no change
void inorder_save(FILE *, struct address_t *); //NEW

void quit(void);