CS 531 HW2
IPv4 Addresses
Author: Alexandyr Card
G#: G01275535
Date: March 21, 2025
Platform: Zeus using gcc
Last Modified: March 8, 2025

Description

Files
The project contains [X] C source files, one header file, and a Makefile.

header.h: This header file contains the function declarations for all functions used throughout the programs. It also includes the preprocessor directives for standard libraries.

menu_input.c: This file contains the functions display_menu and get_user_input.

add_address.c: This file contains all functions to receive and parse IPv4 addresses.
               add_address, get_first_ip_component, clear_input_stream, valid_int_input,
               get_alias_component, check_duplicates, equal_structures
lookup_addr.c: This file contains all functions to find address for an alias entered
               lookup_addr, search_list
update_addr.c: The file contains all functions to update the address of a specific alias
               update_addr, find_node, update_alias_addr, check_duplicate_addr, equal_addresses,
               get_last_ip_component.
delete_addr.c: This file contains all functions related to deleting a node based on an alias.
               delete_address, remove_node, confirm_deletion, get_deletion
display_list: This file contains all functinos related to displaying the list.
              display_list and display_node
display_alias: Prompts user for network address and displays any IPv4 within the network.
               display_alias, alias_address_pairs, get_second_ip_component
save_list: Contains functions required to save linked list to file designated by user
           save_list, get_filename  
quit: Quits the program           

Makefile: This file automates the compilation and linking of the program. It specifies the compiler to use, compiler flags, and libraries to link.

Program Struction and Design

### WORDS HERE

Functions
The program includes the following functions:

display_menu: void input and void return value. Displays the menu to the user.
get_user_input: string input, int return value. Gets user input and does error checking.
                returns 0-8 inclusive, a 0 return value is an error. String inputs are 
                messages to user displayed to screen.
add_address: address of structure address_t input and void return.Takes the linked list as input
             adds IPv4 address and alias to the list in unsorted order by appending to
            the head of the list.
get_first_ip_component: void input and int return value. Accepts user input and does error
                  checking that that value entered is a number. Returns -1 if the 
                  value is incorrect or out of bounds. Used for first 3 IP components
clear_input_stream: void input and void output. Used to clear I/O buffer.
valid_int_input: char input and bool output. Used to test values entered for IPv4 address
get_alias_component: void input and string output. Used to read IPv4 alias
check_duplicates: 2 address_t structures input and bool output.
                  determines whether the IPv4 address/alias entered is a duplicate
equal_structures: 2 address_t structures input and bool output.
                    determines whether 2 structures are equivalent
lookup_addr: struct address_t pointer input and void output. Prompts user for input alias and returns
             whether the alias exists. If so, display the IPv4 otherwise display error
search_list: struct address_t and char array input, bool output. Check the ipv4 LL to
             whether the alias exists
update_addr: struct address_t input, void output. Updates address for an alias if the 
             alias exists and the new address isn't a duplicate
find_node: struct address_t, character array input and struct address_t ooutput.
           looks for node with specific alias
update_alias_addr: 2 struct address_t input, void output. Updates the address for
                   the specified alias if the address isn't a duplicate
check_duplicate_addr: struct address_t, character array input and bool ooutput.
                      checks if new address is a duplicate.
equal_addresses: struct address_t, character array input and bool ooutput.
                 helper function for checking if new address is a duplicate.
get_last_ip_component: void input, int return. Returns the last IPv4 component
delete_address: struct address_t input and void output. GEt's user input for possible
                deletion then deletes the node if the user wants the node gone
remove_node: struct address_t, char array input , void output. Does the deletion
confirm_deletion: struct address_t input, bool output. Confirms user wants to delete node
get_deletion: void input and output. Error checking user input.
display_list: struct address_t input, void output. Displays the linked list, node by node.
display_node: struct address_t input, void output. Displays single node.
display_alias: struct address_t input, void output. Gets user input of network then
               displays and IPv4/alias combos within the network.
alias_address_pairs: struct address_t, 2 int inputs, void output. Searches LL for 
                     computers within the network and prints out the matching pairs.
get_second_ip_component: viod input, int output. Gets 2nd component of IPv4 address.
save_list: struct address_t input, void output. Saves linked list input to file designated
           by user
get_filename: void input, char pointer return. Gets filename from user.
quit: void input and output. Exits the program with code of 0.


The program is compiled on Zeus on the CS Department Linux Server using gcc. 
The Makefile provided automates the compilation and linking of the program.
First unzip the file to see the files. 
Copy/Move the files to your user space on Zeus. 

To compile the program, navigate to the directory containing the program files and run the following command:

make

This will create an executable file: HW1. 

Usage:
To run the program, enter the following command: ./HW2

Clean up: To remove all generated files, run the following command: make clean
