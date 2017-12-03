#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "shell.h"
#include "parse.h"
#include "custom_commands.h"

int redirect(char* line1, char* line2){
  char** parsed1 = parse_args(line1);
  char** parsed2 = parse_args(line2);
  int fd = open(parsed2[0], O_CREAT|O_WRONLY, 0644);
  int stdout = dup(STDOUT_FILENO);
  dup2(fd, STDOUT_FILENO);
  execute(parsed1);
  return dup2(stdout, STDOUT_FILENO);
}

int execute(char ** args) {
  int f = fork();
  if (f && !strcmp(args[0], "cd")){
    int status;
    wait(&status);
    return my_cd(args);
  }
  else if ( !f ) {
    execvp(args[0], args);
    printf("%s\n",strerror(errno));
    exit(0);
  }
  else {
    int status;
    wait(&status);
  }
  return 1;
}
