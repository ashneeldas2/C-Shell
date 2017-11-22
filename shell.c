#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

char** parse_args(char* line){
    int i = 0; 
    char * temp = line;
    while (temp) {
        temp = strsep(&temp, " ");
        i++;
    }
    char** args = (char**) calloc(i, sizeof(char*));
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
        execvp(args);
    }
    else {
        int status;
        wait(&status);
    }
}