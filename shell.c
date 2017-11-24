#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "shell.h"

char ** parse_args(char* line){
    int i = 1; 
    char * temp = malloc(sizeof(char*)); 
    strcpy(temp, line);
    while (temp) {
        strsep(&temp, " ");
        i++;
    } 
    char** args = (char**) calloc(3, sizeof(char*));
    int counter = 0;
    while(line){
      args[counter] = strsep(&line, " ");
      counter++;
    }
    return args;
}  

int execute(char ** args) {
    int f = fork();
    if ( !f ) {
        execvp(args[0], args);
    }
    else {
        int status;
        wait(&status);
    }
    return 1;
}

int main() {
    char line [100];
    while (1) {
        printf("Enter a command: ");
        fgets(line, sizeof(line), stdin);
        int len = strlen(line) - 1;
        if (line[len] == '\n') {
            line[len] = 0;
        }
        char ** args = parse_args(line);
        execute(args);
    }
}