ebola: main.o child.o random.o header.h
	gcc main.o child.o random.o -o ebola -lpthread

main.o: main.c 
	gcc -c main.c

child.o: child.c
	gcc -c child.c

random.o: random.o
	gcc -c random.c

