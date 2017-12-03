#ifndef SHELL_H
  #define SHELL_H
  int execute_reg(char ** args);
  int redirect_out(char ** args);
  int redirect_in(char ** args);
  int execute_all(char * args);
  int double_redir_out(char ** args);
#endif
