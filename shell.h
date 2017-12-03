#ifndef SHELL_H
  #define SHELL_H
  int execute(char ** args);
  int my_cd(char ** args);
  int redirect(char* line1, char* line2);
  int my_exit();
#endif
