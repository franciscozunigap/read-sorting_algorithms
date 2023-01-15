CC=gcc
FLAGS= -Wall 
FLAGS1= -lm -lrt 

TEST: main.o sorting.o 

	$(CC) -o $@ main.o sorting.o  $(FLAGS)
	
	
main.o: main.c
	$(CC) -c main.c $(FLAGS)

sorting.o: sorting.c
	$(CC) -c sorting.c $(FLAGS)
	


main.c: head.h
sorting.c: head.h
