all:program4

program4:tournament.o program4.o
	gcc tournament.o program4.o -o program4

tournament.o:tournament.c tournament.h
	gcc -c tournament.c 

program4.o:program4.c 
	gcc -c program4.c

clean:
	rm -f tournament.o program4.o program4

checkmem:	
	valgrind ./program4

run:
	./program4 
