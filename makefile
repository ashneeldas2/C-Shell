all: shell.o main.o parse.o
	gcc -o shell shell.o main.o parse.o

shell.o:
	gcc -c shell.c

main.o:
	gcc -c main.c

parse.o:
	gcc -c parse.c

clean:
	rm *.o
	rm shell

run: all
	./shell
