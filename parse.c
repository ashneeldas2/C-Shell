#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "parse.h"

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
