CS 531 HW4
IPv4 Addresses
Author: Alexandyr Card
G#: G01275535
Date: May 9, 2025
Platform: Zeus using gcc
Last Modified: May 7, 2025

Description

Files
The project contains 12 C source files, one header file, and a Makefile.

header.h: This header file contains the function declarations for all functions used throughout the programs. It also includes the preprocessor directives for standard libraries.
		  And contains the definition of the nodes used in the binary search tree structure

HW4.c: This is the main file which builds the BST and utilizes all the user-defined functions

menu_input.c: This file contains the functions display_menu and get_user_input.

add_address.c: This file contains all functions to receive and parse IPv4 addresses then add them to the BST.
               add_address, valid_ip, check_duplicates, equal_structures, equal_ip, equal_name

lookup_addr.c: This file contains all functions to find address for an alias entered
               lookup_addr

update_addr.c: The file contains all functions to update the address of a specific alias
               update_addr, find_node, equal_name2, update_alias_addr, check_duplicate_addr, equal_addresses, duplicate_addr_check

delete_addr.c: This file contains all functions related to deleting a node based on an alias.
               delete_address, remove_node, confirm_deletion, get_deletion

display_list: This file contains all functions related to displaying the list.
              display_list and display_node, inorder_traversal

display_alias: Prompts user for network address and displays any IPv4 within the network.
               display_alias and alias_address_pairs, print pairs, check_in_list

save_list: Contains functions required to save linked list to file designated by user
           save_list, get_filename, inorder_save 

quit: Quits the program

read_input_list: Contains function required to read initial list of IPv4 address/alias pairs
                 and do error checking for invalid address/alias/duplciates

bst_functions: Contains functions used for operations on the binary search tree
			   add_node, size, delete_node, find_smallest_node, check_all_node_dups

Makefile: This file automates the compilation and linking the program. It specifies the compiler to use, compiler flags, and libraries to link.

Program Structure and Design

Functions
The program includes the following functions:

menu_input.c
display_menu: void input and void return value. Displays the menu to the user.
get_user_input: string input, int return value. Gets user input and does error checking.
                returns 0-8 inclusive, a 0 return value is an error. String inputs are 
                messages to user displayed to screen.

add_address.c
add_address: address of structure address_t input and void return.Takes the linked list as input
             adds IPv4 address and alias to the list in unsorted order by appending to
            the head of the list.
valid_ip: int input and bool output. Checks the alias is within the range of alias values

check_duplicates: 2 address_t structures input and bool output.
                  determines whether either the IPv4 address/alias entered is a duplicate
equal_structures: 2 address_t structures input and bool output.
                    determines whether 2 structures are equivalent
equal_ip: 2 address_t structures input bool output. Compares the IPv4 addresses of the 2 structures
		  to determine if they were equivalent
equal_name: 2 address_t structures input, bool output. Compares the IPv4 aliases of the 2 structures and avoids
			makes it not case sensitive.



lookup_addr.c
lookup_addr: struct address_t pointer input and void output. Prompts user for input alias and returns
             whether the alias exists. If so, display the IPv4 otherwise display error




update_addr.c
update_addr: struct address_t input, void output. Updates address for an alias if the 
             alias exists and the new address isn't a duplicate

find_node: struct address_t, character array input and struct address_t output.
           looks for node with specific alias

equal_name2: 2 char arrays input and bool output. Compares aliases of inputs and 
			 checks whether they are equivalent, not case sensitive

update_alias_addr: 2 struct address_t input, void output. Updates the address for
                   the specified alias if the address isn't a duplicate

check_duplicate_addr: struct address_t, character array input and bool output.
                      checks if new address is a duplicate.

equal_addresses: struct address_t, character array input and bool output.
                 helper function for checking if new address is a duplicate.
duplicate_addr_check: int array and struct address_t pointer input, int output. Checks if any nodes 
					  in BST have equal IP addresses


delete_address.c
delete_address: struct address_t double pointer input and void output. Get's user input for alias
                deletion then deletes the node if the user wants the node gones
confirm_deletion: struct address_t input, bool output. Confirms user wants to delete node
get_deletion: void input and char output. Error checking user input for confirmation of node to delete



display_list.c
display_list: struct address_t input, void output. Displays the linked list, node by node.
display_node: struct address_t input, void output. Displays single node.
inorder_traversal: struct address_t pointer input, void output. Performs inorder traversal and prints node contents


display_alias.c
display_alias: struct address_t input, void output. Gets user input of network then
               displays and IPv4/alias combos within the network.
alias_address_pairs: struct address_t, 2 int inputs, void output. Searches LL for 
                     computers within the network and prints out the matching pairs.
print_pairs: struct address_t pointer and 2 int inputs, void output. Checks all nodes in BST for matches to 
			 first two numbers of IPv4 address and prints out matches
check_in_list: struct address_t pointer and 2 int inputs, int output. Checks if node is in list based on IPv4 address



save_list.c
save_list: struct address_t input, void output. Saves linked list input to file designated
           by user
get_filename: void input, char pointer return. Gets filename from user.
inorder_save: File pointer, struct address_t node input, void output. Saves BST to file specified by user

quit.c
quit: void input and output. Exits the program with code of 0.

read_input_list.c
read_input_list: struct adress_t double pointer input, void output. Prompts user for 
                 file name to read and reads file line by line parsing input for 
                 IPv4 address components and alias. Does error checking while reading file

bst_functions.c
add_node: struct adress_t double pointer and struct address_t pointer input, void output. Adds node to BST
size: struct address_t pointer input, int output. Returns number of nodes in BST
delete_node: struct address_t pointer and char array input, struct address_t output. Deletes node with matching
			 alias
find_smallest_node: struct address_t pointer input, struct address_t pointer output. HElper function to find inorder successor 
					when deleting node
check_all_node_dup: 2 struct address_t pointer input, int output. Checks every node of BST if there is a match. Returns a
					positive integer if so, otherwise 0


The program is compiled on Zeus on the CS Department Linux Server using gcc. 
The Makefile provided automates the compilation and linking of the program.
First unzip the file to see the files. 
Copy/Move the files to your user space on Zeus. 

To compile the program, navigate to the directory containing the program files and run the following command:

make

This will create an executable file: HW4. 

Usage:
To run the program, enter the following command: ./HW4

Clean up: To remove all generated files, run the following command: make clean
