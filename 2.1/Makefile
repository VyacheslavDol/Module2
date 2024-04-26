all: task2_1

task2_1: task2_1.o contact.o email.o person.o phone.o input_char.o
	gcc task2_1.o contact.o email.o person.o phone.o input_char.o -o task2_1

task2_1.o: task2_1.c
	gcc -c task2_1.c 

input_char.o: input_char.c
	gcc -c input_char.c

contact.o: contact.c
	gcc -c contact.c

person.o: person.c
	gcc -c person.c

phone.o: phone.c
	gcc -c phone.c

email.o: email.c
	gcc -c email.c

clean:
	rm -f *.o task2_1	 		