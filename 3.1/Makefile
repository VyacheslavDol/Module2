all: task3_1

task3_1: task3_1.o bin_func.o
	gcc task3_1.o bin_func.o -o task3_1

task1.o: task3_1.c
	gcc -c task3_1.c

bin_func.o: bin_func.c
	gcc -c bin_func.c

clean:
	rm -rf *.o task3_1