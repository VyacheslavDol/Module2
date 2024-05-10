all: task6_3

task6_3: task2_3.o
	gcc -o task6_3 *.o -L../library -lsum -ldiv -lmult -lsubstr -Wl,-rpath,../library/
	rm *.o

task4_1.o: task2_3.c
	gcc -c task2_3.c

clean:
	rm -f task6_3