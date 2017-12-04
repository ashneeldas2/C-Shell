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

int redirect_out(char ** args) {
	//char ** parsed1 = parse_args(args[0]);
	char ** parsed2 = parse_args(args[1]);
	int fd = open(parsed2[0], O_CREAT|O_WRONLY, 0644);
	printf("args[0]: %s\n", args[0]);
	int stdout = dup(STDOUT_FILENO);
	int before = dup2(fd, STDOUT_FILENO);
	execute_all(args[0]);
	dup2(stdout, before);
	return 1;
}

int redirect_in(char ** args) {
	//char ** parsed1 = parse_args(args[0]);
	char ** parsed2 = parse_args(args[1]);
	//printf("args[1]: %s\n", args[1]);
	int fd = open(parsed2[0], O_CREAT|O_RDONLY, 0644);
	int stdin = dup(STDIN_FILENO);
	int before = dup2(fd, STDIN_FILENO);
	execute_all(args[0]);
	dup2(stdin, before);
	return 1;
}

int double_redir_out(char ** args) {
	char ** parsed1 = parse_args(args[0]);
	char ** parsed2 = parse_args(++args[1]);
	printf("parsed1[0]: %s\n", parsed1[0]);
	printf("parsed2[0]: %s\n", parsed2[0]);
	int fd = open(parsed2[0], O_CREAT|O_WRONLY|O_APPEND, 0644);
	printf("%s\n", strerror(errno));
	int stdout = dup(STDOUT_FILENO);
	int before = dup2(fd, STDOUT_FILENO);
	execute_reg(parsed1);
	dup2(stdout, before);
	return 1;
}

int piper(char ** args) {
	char ** parsed1 = parse_args(args[0]);
	char ** parsed2 = parse_args(args[1]);
	FILE *fp = popen(args[0],"r");
	int stdin = dup(STDIN_FILENO);
	int before = dup2(fileno(fp), STDIN_FILENO);
	execute_reg(parsed2);
	dup2(stdin, before);
	pclose(fp);
	return 1;
}

int execute_all(char* args){
	char ** parsed;
	if (!strcmp(args, "exit")) {
		return my_exit();
	}
	if (strstr(args, ">>")) {
		parsed = separate_commands(args, ">");
		return double_redir_out(parsed);
	}
	if (strstr(args, ">")) {
		parsed = separate_commands(args, ">");
		return redirect_out(parsed);
	}
	if (strstr(args, "<")){
		parsed = separate_commands(args, "<");
		return redirect_in(parsed);
	}
	if (strstr(args, "|")) {
		parsed = separate_commands(args, "|");
		return piper(parsed);
	}
	else {
		parsed = parse_args(args);
		return execute_reg(parsed);
	}
}

int execute_reg(char ** args) {
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
