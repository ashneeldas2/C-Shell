all: shell.o main.o parse.o custom_commands.o
	gcc -o shell shell.o main.o parse.o custom_commands.o

shell.o:
	gcc -c shell.c

main.o:
	gcc -c main.c

parse.o:
	gcc -c parse.c

custom_commands.o:
	gcc -c custom_commands.c

clean:
	rm *.o
	rm shell

run: all
	./shell
	make clean
