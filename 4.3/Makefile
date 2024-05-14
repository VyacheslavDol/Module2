all: task4_3

task4_3: main.o contact.o email.o person.o phone.o input_char.o binTreeFunc.o
	gcc -g main.o contact.o email.o person.o phone.o input_char.o binTreeFunc.o -o task4_3

main.o: main.c
	gcc -c -g main.c 

input_char.o: input_char.c
	gcc -c -g input_char.c

binTreeFunc.o: binTreeFunc.c
	gcc -c -g binTreeFunc.c	

contact.o: contact.c
	gcc -c -g contact.c

person.o: person.c
	gcc -c -g person.c

phone.o: phone.c
	gcc -c -g phone.c

email.o: email.c
	gcc -c -g email.c

clean:
	rm -f *.o task4_3	 		