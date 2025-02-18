objects = HW1.o read_word.o clear_input_stream.o not_valid_character.o \
print_functions.o is_duplicate_string.o sort_functions.o get_sort_order.o

HW1: $(objects)
	gcc -o HW1 $(objects)
HW1.o: HW1.c header.h
	gcc -c HW1.c
read_word.o: read_word.c header.h
	gcc -c read_word.c
clear_input_stream.o: clear_input_stream.c header.h
	gcc -c clear_input_stream.c
not_valid_character.o: not_valid_character.c header.h
	gcc -c not_valid_character.c
print_functions.o: print_functions.c header.h
	gcc -c print_functions.c
is_duplicate_string.o: is_duplicate_string.c header.h
	gcc -c is_duplicate_string.c
sort_functions.o: sort_functions.c header.h
	gcc -c sort_functions.c
get_sort_order.o: get_sort_order.c header.h
	gcc -c get_sort_order.c
clean:
	rm *.o
	rm -rf core
	rm HW1