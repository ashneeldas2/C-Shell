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

int redirect(char ** args) {
	int i = 0;
	char ** parsed1 = parse_args(args[0]);
	char ** parsed2 = parse_args(args[1]);
	int fd = open(parsed2[0], O_CREAT|O_WRONLY, 0644);
	int stdout = dup(STDOUT_FILENO);
	int before = dup2(fd, STDOUT_FILENO);
	execute(parsed1);
	dup2(stdout, before);
	return 1;
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
