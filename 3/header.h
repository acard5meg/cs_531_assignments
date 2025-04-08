// connect mySQL: mysql -h helios.vse.gmu.edu -u acard -p

// password for SQL is: []

/**  structure for table used in assignment
CREATE TABLE CS531_Inet (IPv4 varchar(255),alias varchar(255));
*/
// header file contains all preprocessor directives

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

// to connect to SQL database
#include <mysql/mysql.h>


#define ALIAS_LEN 10
#define IP_LENGTH 4
#define IP_COMPONENT_LENTH 3
// Without guidance assuming an arbitrarty file size length of 260
#define MAX_FILENAME_LENGTH 260
#define DBNAME "acard"
#define TABLE_NAME "CS531_Inet"
// #define TOTAL_IPV4 3

// global definition for structure used in assignment
struct address_t{
    int octet[4];
    char alias[11];
    struct address_t *next;
} ;

// get_connection.c
// returns pointer to SQL connection
MYSQL* get_connection(void);

//read_input_list.c <- CHANGED TO ACCOUNT FOR MY SQL
void read_input_list(struct address_t **, MYSQL *);

// menu_input.c <- LOOKS TO ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void display_menu(void);
int get_user_input(char *, char *);

// add_address.c <- LOOKS TO ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void add_address(struct address_t **);
bool check_duplciates(struct address_t *, struct address_t *);
bool equal_structures(struct address_t *, struct address_t *);
bool equal_ip(struct address_t *, struct address_t *);
bool equal_name(struct address_t *, struct address_t *);
bool valid_ip(int );

// lookup_addr.c <- LOOKS ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void lookup_addr(struct address_t *);

// update_addr.c <- LOOKS ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void update_addr(struct address_t *);
struct address_t* find_node(struct address_t *, char []);
void update_alias_addr(struct address_t *, struct address_t *);
bool check_duplciate_addr(int [], struct address_t *);
bool equal_addresses(int [], struct address_t *);
bool equal_name2(char [], char []);

//delete_address.c <- LOOKS ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void delete_address(struct address_t **);
void remove_node(struct address_t **, char []);
bool confirm_deletion(struct address_t *);
char get_deletion(void);

//display_list.c <- LOOKS ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void display_list(struct address_t *);
void display_node(struct address_t *);

// display_alias.c <- LOOKS ONLY AFFECT LL, THEREFORE NO UPDATE FOR SQL
void display_alias(struct address_t *);
void alias_address_pairs(struct address_t *, int, int);

//save_list.c <- CHANGED TO ACCOUNT FOR MY SQL
void save_list(struct address_t *, MYSQL *);
char *ip_to_string(int , int , int , int );
// char *get_filename(void);

//quit.c <- CHANGED TO ACCOUNT FOR MY SQL
void quit(MYSQL *);