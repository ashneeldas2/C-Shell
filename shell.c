#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include "shell.h"

void trim(char * line) {
    int i;
    int front = 0;
    int end = strlen(line) - 1;
    while (line[front] == ' ')
        front++;
    while ((end >= front) && line[end] == ' ')
        end--;
    for (i = front; i <= end; i++)
        line[i - front] = line[i];
    line[i - front] = 0;
}

int my_cd(char** args){
  if(chdir(args[1])){
      strerror(errno);
      return 0;
  }
  else{
      return 1;
  }
}

int my_exit(char** args){
  exit(0);
}

char ** parse_args(char* line){
    int i = 1;
    char * temp = malloc(sizeof(char*));
    strcpy(temp, line);
    while (temp) {
        strsep(&temp, " ");
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

char ** separate_commands(char * line) {
    int i = 1;
    char * temp = malloc(sizeof(char*));
    strcpy(temp, line);
    while (temp) {
        strsep(&temp, ";");
        i++;
    }
    char** args = (char**) calloc(i, sizeof(char*));
    int counter = 0;
    while(line){
        args[counter] = strsep(&line, ";");
        counter++;
    }
    i = 0;
    while (args[i]) {
        trim(args[i]);
        i++;
    }
    return args;
}

int execute(char ** args) {
    if (!strcmp(args[0], "cd")){
        return my_cd(args);
    }
    if (!strcmp(args[0], "exit")){
        return my_exit(args);
    }
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
        char ** args = separate_commands(line);
        int i = 0;
        while (args[i]) {
            printf("[%s]\n", args[i]);
            char ** parsed = parse_args(args[i]);
            execute(parsed);
            i++;
        }
    }
}
