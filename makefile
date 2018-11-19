all: fork.o
	gcc -o fork fork.o

fork.o: fork.c
	gcc -c fork.c

run:
	./fork

clean:
	rm fork
	rm *.o
