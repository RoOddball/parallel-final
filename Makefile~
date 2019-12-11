ebola: main.o child.o random.o header.h
	gcc main.o child.o random.o -o ebola

main.o: main.c header.h
	gcc -c main.c

child.o: child.c header.h
	gcc -c child.c

random.o: random.o header.h
	gcc -c random.c
