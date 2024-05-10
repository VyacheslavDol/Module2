all: so

so: o
	gcc -shared -o libdiv.so mydiv.o
	gcc -shared -o libmult.so mymult.o
	gcc -shared -o libsum.so mysum.o
	gcc -shared -o libsubstr.so mysubstr.o
	rm -f *.o

o: ./source/mysum.c ./source/mydiv.c ./source/mymult.c ./source/mysubstr.c
	gcc -c -fPIC ./source/mysum.c
	gcc -c -fPIC ./source/mydiv.c
	gcc -c -fPIC ./source/mymult.c
	gcc -c -fPIC ./source/mysubstr.c
	
clean:
	rm -f *.so