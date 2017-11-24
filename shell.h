void trim(char * line);

char ** parse_args(char * line);

char ** separate_commands(char * line);

int execute(char ** args);
