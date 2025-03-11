// header file contains all preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALIAS_LEN 10
#define IP_LENGTH 4
// #define TOTAL_IPV4 3

// global definition for structure used in assignment
struct address_t{
    int octet[4];
    char alias[11];
    struct address_t *next;
} ;

void display_menu(void);
int get_user_input(char *, char *);
bool final_menu(int);

// add_address.c
// struct address_t* add_address(struct address_t *);
void add_address(struct address_t **);
int get_ip_component(char);
void clear_input_stream(void);
bool valid_int_input(char);
char* get_alias_component(void);
bool check_duplciates(struct address_t *, struct address_t *);
bool equal_structures(struct address_t *, struct address_t *);

// lookup_addr.c
void lookup_addr(struct address_t *);
int* search_list(struct address_t *, char[] );

// update_addr.c
void update_addr(struct address_t *);
struct address_t* find_node(struct address_t *, char []);
void update_alias_addr(struct address_t *, struct address_t *);
bool check_duplciate_addr(int [], struct address_t *);
bool equal_addresses(int [], struct address_t *);
int get_last_ip_component(void);

//delete_address.c
void delete_address(struct address_t *);
void remove_node(struct address_t *, char []);
bool confirm_deletion(struct address_t *);
char get_deletion(void);

//display_list.c
void display_list(struct address_t *);
void display_node(struct address_t *);

// display_alias.c
void display_alias(struct address_t *);
int get_second_ip_component(void);
void alias_address_pairs(struct address_t *, int, int);

//save_list.c
void save_list(struct address_t *);
char *get_filename(void);

void quit(void);