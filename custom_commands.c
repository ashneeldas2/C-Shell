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

//Custom CD
int my_cd(char** args){
  if(chdir(args[1])){
    return 0;
  }
  else{
    return 1;
  }
}

//Custom exit
int my_exit(){
  exit(0);
}
