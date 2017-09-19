all:program7

program7:bst.o program7.o
	    gcc bst.o program7.o -o program7

bst.o:bst.c bst.h
	    gcc -c bst.c

program7.o:program7.c
	    gcc -c program7.c

clean:
	    rm -f bst.o program7.o program7

checkmem:
	    valgrind -v ./program7

run:
	    ./program7
