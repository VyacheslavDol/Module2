all: task4_1

task4_1: task4_1.o contact.o email.o person.o phone.o input_char.o list_func.o
	gcc task4_1.o contact.o email.o person.o phone.o input_char.o list_func.o -o task4_1

task4_1.o: task4_1.c
	gcc -c task4_1.c 

input_char.o: input_char.c
	gcc -c input_char.c

list_func.o: list_func.c
	gcc -c list_func.c	

contact.o: contact.c
	gcc -c contact.c

person.o: person.c
	gcc -c person.c

phone.o: phone.c
	gcc -c phone.c

email.o: email.c
	gcc -c email.c

clean:
	rm -f *.o task4_1	 		