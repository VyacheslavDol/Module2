all: task6_1

task6_1: task4_1.o
	gcc -o task6_1 *.o -L../library -lmy1
	rm *.o

task4_1.o: task4_1.c
	gcc -c task4_1.c

clean:
	rm -f task6_1