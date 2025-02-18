CS 531 HW1
String Input and Sort
Author: Alexandyr Card
G#: G01275535
Date: February 20, 2025
Platform: Zeus using gcc
Last Modified: February 17, 2025

Description
This project is a program that provides an interface and prompting system for the user to enter 10 unique character strings. The strings must be between 2 and 25 characters in length and not contain illegal characters as specified by the problem. Once the input is received, the user is asked to determine the sort order of the strings. Afterwards, the program displays the 10 strings sorted in the user specified order and the strings with the lowest and highest ascii values are listed.

Files
The project contains eight C source files, one header file, and a Makefile.

header.h: This header file contains the function declarations for all functions used throughout the programs. It also includes the preprocessor directives for standard libraries.

HW1.c: This is the main c program. It includes the macro definitions for the problem specifics, e.g. number of strings and string length. The program uses various user-defined functions to read in the strings, sort the strings, and print out the strings in sorted order.

get_sort_order.c: This contains the function get_sort_order. This function prompts the user for an input to determine the sort order (ascending, descending) of the string array. It also does input validation to confirm the user entered a proper command, otherwise it re-prompts the user to enter the sort order command again.

is_duplicate_string.c: This contains the function checkDuplicate. The function takes a string and an array of strings as input and checks whether the string is contained within the array of strings, returning a boolean value.

not_valid_character.c: This contains the function checkLegalCharacters. The function takes a character as input and returns a boolean value whether the character is invalid based on the problem specifications. For example, checkLegalCharacters('!') returns false.

read_word.c: This contains the functions get_string and checkStringLen. The get_string function prompts the user for a string input, then checks whether the string contains invalid characters, is too long, or is too short. If the input string is valid it returns a pointer to the string or returns NULL which indicates the string input was invalid. The checkStringLen function is a helper function that is used within get_string to check the length of the string is correct.

clear_input_stream.c: This contains the function clear_input_stream. The function is used to flush the input buffer of any remaining characters if the user entered an invalid string.

sort_functions.c: This contains the functions ascendingSort, descendingSort, create_arr, and use_sort. The ascendingSort and descendingSort functions implement the merge sort algorithm and sort the characters in ascending or descending order based on the function that is called, e.g. ascendingSort is ascending sort order. create_arr is a helper function in merge sort to create arrays when we split the input array into a left and right half before recursing on each half. use_sort takes the sort order character and array of strings as input and calls the corresponding merge sort function.

print_functions.c: This contains the functions inputStings and sort_type_print. inputStings is a function used to prompt the user to enter the number of strings as specified in the problem. sort_type_print prints the sorted array of strings and displays the strings with the lowest and highest ascii values.

Makefile: This file automates the compilation and linking of the program. It specifies the compiler to use, compiler flags, and libraries to link.

Program Struction and Design
The program is structured as follows:

The user is prompted to enter 10 character strings. The user must press enter each time they finish entering a string. If the user enters an invalid string the program will issue a warning with the reason for the string being rejected, then the user will be prompted to re-enter the string. Once the user enters the correct number of strings, they'll be asked whether they want to sort the strings in ascending or descending order by entering the letter 'A' or 'D'. If the user enters an incorrect sort letter they'll be prompted to re-enter. Then the 10 strings will be displayed in the correct sorted order and the program will display the strings with the highest and lowest ascii values.

Functions
The program includes the following functions:

get_sort_order: Prompts the user to enter the order they want the input strings to be sorted. Uses error checking to ensure the user enters a correct input; otherwise, it reprompts them. Returns the char value 'A' or 'D' for the ascending or descending sort order.

checkDuplicate: Is used to determine whether the user entered string is a duplicate. Loops through the array of already valid strings and checks each string whether it matches the user entered one.

checkLegalCharacters: This is used to check whether the characters entered by the user are acceptable based on the problem statement. If the problem specifications change the types of excluded characters only this program needs to change.

get_string: This prompts the user to enter a string then performs error checking on the entered string to ensure it complies with the problem specifications. It uses the function checkLegelCharacters to ensure each character is valid and checks the length of the string is within the program specified lengths. This returns a pointer to a valid string or NULL to alert the calling program the string isn't valid.

checkStringLen: This is a helper function used in get_string to check the length of the string by counting the number of characters.

clear_input_stream: This is a helper function used in get_string to clear the input buffer if a word has invalid characters or is too long.

ascendingSort: This function sorts an array of strings using merge sort in ascending order. 

descendingSort: This function sorts an array of strings using merge sort in descending order.

create_arr: This is a helper function used in ascendingSort and descendingSort to create the left and right arrays that are then inputs to the recursively called sort function.

use_sort: This function allows the main program to call a single function to select the sort algorithm they want to apply to the array of strings.

inputStrings: This function prompts the user to enter the total number of strings specified by the problem.

sort_type_print: This function prints the sorted array of strings and displays the strings with the lowest and highest ascii values based on the assumption the input array is sorted in either ascending or descending order. 

The program is compiled on Zeus on the CS Department Linux Server using gcc. The Makefile provided automates the compilation and linking of the program.First unzip the file to see the files. Copy/Move the files to your user space on Zeus. To compile the program, navigate to the directory containing the program files and run the following command:

make

This will create an executable file: HW1. 

Usage:
To run the program, enter the following command: ./HW1

Clean up: To remove all generated files, run the following command: make clean
