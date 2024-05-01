all: task4_2

task4_2: task4_2.o input_char.o que_func.o
	gcc task4_2.o input_char.o que_func.o -o task4_2

task4_2.o: task4_2.c
	gcc -c task4_2.c

que_func.o: que_func.c
	gcc -c que_func.c

input_char.o: input_char.c
	gcc -c input_char.c

clean: 
	rm -f *.o task4_2