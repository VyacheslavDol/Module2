all: task2_3

task2_3: task2_3.o mymaths.o
	gcc task2_3.o mymaths.o -o task2_3
	
task2_3.o: task2_3.c
	gcc -c task2_3.c

mymaths.o: mymaths.c
	gcc -c mymaths.c

clean:
	rm -f *.o task2_3