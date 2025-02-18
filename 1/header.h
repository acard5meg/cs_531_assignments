#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

char* get_string(int, int, int);
void clear_input_stream(void);
bool checkLegalCharacters(char);
void inputStings(int);
bool checkDuplicate(int, char **, char *);
char get_sort_order(void);
void ascendingSort(int, char **);
void descendingSort(int, char **);
void create_arr(int, int, char **, char **);
void sort_type_print(char, int, char **);
void use_sort(char, int, char **);
int checkStringLen(char *, int);