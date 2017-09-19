all:program5

program5:vector.o program5.o
	    gcc vector.o program5.o -o program5

vector.o:vector.c vector.h
	    gcc -c vector.c

program5.o:program5.c
	    gcc -c program5.c

clean:
	    rm -f vector.o program5.o program5

checkmem:
	    valgrind -v ./program5

run:
	    ./program5