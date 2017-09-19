all:program6

program6:list.o program6.o
	    gcc list.o program6.o -o program6

list.o:list.c list.h
	    gcc -c list.c

program6.o:program6.c
	    gcc -c program6.c

clean:
	    rm -f list.o program6.o program6

checkmem:
	    valgrind -v ./program6

run:
	    ./program6
