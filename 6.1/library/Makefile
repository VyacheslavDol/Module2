all: libmy1.a

libmy1.a: contact.o email.o input_char.o list_func.o person.o phone.o
	ar r libmy1.a *.o
	rm -f *.o

contact.o: ./source/contact.c
	gcc -c ./source/contact.c

email.o: ./source/email.c
	gcc -c ./source/email.c

input_char.o: ./source/input_char.c
	gcc -c ./source/input_char.c

list_func.o: ./source/list_func.c
	gcc -c ./source/list_func.c

person.o: ./source/person.c
	gcc -c ./source/person.c

phone.o: ./source/phone.c
	gcc -c ./source/phone.c

clean:
	rm -f *.a