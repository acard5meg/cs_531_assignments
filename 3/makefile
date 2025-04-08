# CC   = gcc
# OBJ  = test_connect.o add_address.o get_connection.o
# SRC = test_connect.c
# TARGET = connect
# HEADER_FILE = header.h
# connect: $(OBJ)
# 	gcc -o connect $(OBJ) $(LIBS)
# test_connect.o: test_connect.c header.h
# 	gcc -c test_connect.c -Wall -I/usr/include/mysql
# add_address.o: add_address.c header.h
# 	gcc -c add_address.c
# get_connection.o: get_connection.c header.h
# 	gcc -c get_connection.c

# objects = HW3.o menu_input.o add_address.o lookup_addr.o update_addr.o \
# delete_address.o display_list.o display_alias.o save_list.o quit.o read_input_list.o

# objects = HW3.o menu_input.o add_address.o read_input_list.o

LIBS = $(shell mysql_config --cflags --libs)

objects = HW3.o get_connection.o read_input_list.o menu_input.o add_address.o \
lookup_addr.o update_addr.o delete_address.o display_list.o display_alias.o save_list.o quit.o


HW3: $(objects)
	gcc -o HW3 $(objects) $(LIBS)
HW3.o: HW3.c header.h
	gcc -c HW3.c
get_connection.o: get_connection.c header.h
	gcc -c get_connection.c -Wall -I/usr/include/mysql 
read_input_list.o: read_input_list.c header.h
	gcc -c read_input_list.c
menu_input.o: menu_input.c header.h
	gcc -c menu_input.c
add_address.o: add_address.c header.h
	gcc -c add_address.c
lookup_addr.o: lookup_addr.c header.h
	gcc -c lookup_addr.c
update_addr.o: update_addr.c header.h
	gcc -c update_addr.c
delete_address.o: delete_address.c header.h
	gcc -c delete_address.c
display_list.o: display_list.c header.h
	gcc -c display_list.c
display_alias.o: display_alias.c header.h
	gcc -c display_alias.c
save_list.o: save_list.c header.h
	gcc -c save_list.c
quit.o: quit.c header.h
	gcc -c quit.c

clean:
	rm *.o
	rm -rf core
	rm HW3