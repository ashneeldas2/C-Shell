all: shell.o main.o
	gcc -o shell shell.o main.o

shell.o:
	gcc -c shell.c

main.o:
	gcc -c main.c

clean:
	rm *.o

run: all
	./shell
