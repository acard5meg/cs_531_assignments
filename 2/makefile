objects = HW2.o menu_input.o add_address.o lookup_addr.o update_addr.o \
delete_address.o display_list.o display_alias.o save_list.o quit.o read_input_list.o

HW2: $(objects)
	gcc -o HW2 $(objects)
HW2.o: HW2.c header.h
	gcc -c HW2.c
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
read_input_list.o: read_input_list.c header.h
	gcc -c read_input_list.c

clean:
	rm *.o
	rm -rf core
	rm HW2