all:
	gcc program2.c -o project2

checkmem:program2.c
	gcc program2.c -o program2
	valgrind ./program2 

defuseTheBomb:bomb.c defuseMe.c hidden.o
	gcc -g bomb.c defuseMe.c hidden.o -o -lm defuseTheBomb

out:defuseTheBomb
	./defuseTheBomb 

clean:
	rm ! (hidden.o)

