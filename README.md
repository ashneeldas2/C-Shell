# C-Shell - Ashneel Das and Anish Shenoy
### Systems Project #01 Shelling Out Commands

## Features
1. Forks and executes commands
2. Run multiple commands on one line (seperated by ```;```)
3. Built-In ```cd``` and ```exit``` commands
4. Redirection using ```>``` and ```<```
5. Use simple pipes with ```|```
6. Redirection using ```>>```

## Attempted Features
1. Redirection using ```<<```

## Bugs
1. Using Quotes in a command (such as with ```git commit -m "message"``` causes an error)

## Files & Function Headers

### parse.c
  1. ```char** parse_args()```
      * Inputs: A char * (line).
      * Returns: A char **.
      * Desc: This function takes in a char *, separates it by spaces, and returns a char ** that can be used in execvp().

  2. ```void trim()```
      * Inputs: A char * (line).
      * Returns: None,
      * Desc: This function removes leading and trailing white space in line.

  3. ```char** separate_commands()```
      * Inputs: A char * (line) and a char * (delimiter).
      * Returns: A char **.
      * Desc: This function takes in a char *, separates it by a given delimiter, and returns a char ** that can be used in execvp().

### custom_commands.c
  1. ```int my_cd()```
      * Inputs: A char ** of commands.
      * Returns: 0 if successful, 1 if not.
      * Desc: This function uses the built in chdir() function to change directories.

  2. ```int my_exit()```
      * Inputs: None.
      * Returns: 0 when exiting.
      * Desc: This function exits the shell using the built in exit() function.

### shell.c
  1. ```int execute_reg()```
      * Inputs: A char **.
      * Returns: 1 if successful.
      * Desc: This function uses execvp() to run the command given in the char **.

  2. ```int execute_all()```
      * Inputs: A char *.
      * Returns: 1 if successful.
      * Desc: This function executes the given single command.

  3. ```int redirect_out()```
      * Inputs: A char **.
      * Returns: 1 if successful.
      * Desc: This function redirects the output of the first given command into the named file.

  4. ```int redirect_in()```
      * Inputs: A char **.
      * Returns: 1 if successful.
      * Desc: This function takes the output of the second command and makes it the input of the first.

   5. double_redir_out()
      * Inputs: A char **.
      * Returns: 1 if successful.
      * Desc: This function redirects the output of the first given command into the named file and appends it.

### main.c
  1. ```int main()```
      * Inputs: None
      * Returns: 0
      * Desc: This function is main! This is where the program is run.
