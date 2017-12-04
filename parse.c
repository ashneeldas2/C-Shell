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
#include "custom_commands.h"

//REVERSE STRING
void reverse_string(char* str) {
    char temp;
    int len = strlen(str) - 1;
    int i;
    int k = len;

    for(i = 0; i < len; i++) {
        temp = str[k];
        str[k] = str[i];
        str[i] = temp;
        k--;
        if(k == (len / 2)){
            break;
        }
    }
}

//Removes Trailing and leading white space
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

//separates arguments based on spaces
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

//seperates based on delimeter
char ** separate_commands(char * line, char * delimeter) {
  int i = 1;
  char * temp = malloc(sizeof(char*));
  strcpy(temp, line);
  while (temp) {
    strsep(&temp, delimeter);
    i++;
  }
  char** args = (char**) calloc(i, sizeof(char*));
  int counter = 0;
  while(line){
    args[counter] = strsep(&line, delimeter);
    counter++;
  }
  i = 0;
  while (args[i]) {
    trim(args[i]);
    i++;
  }
  return args;
}
