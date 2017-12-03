# ifndef PARSE_H
  # define PARSE_H
  char ** parse_args(char * line);
  void trim(char * line);
  char ** separate_commands(char * line, char * delimeter);
#endif
