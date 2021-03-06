#include "parse.h"
#include "shell.h"
#include "custom_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>

int main() {
  printf("\nWelcome To Ashneel And Anish's C-SHELL\n\n");
  char line [100];
  while (1) {
    printf("Enter a command: ");
    if(!fgets(line, sizeof(line), stdin)){
      printf("exit\n");
      return my_exit();
    }
    
    int len = strlen(line) - 1;
    if (line[len] == '\n') {
      line[len] = 0;
    }
    char ** args = separate_commands(line, ";");
    int i = 0;
    while (args[i]) {
      execute_all(args[i]);
      i++;
    }
  }
  return 0;
}
