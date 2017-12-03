# C-Shell - Ashneel Das and Anish Shenoy
### Systems Project #01 Shelling Out Commands

## Features
1. Forks and executes commands
2. Run multiple commands on one line (seperated by ```;```)
3. Built-In ```cd``` and ```exit``` commands
4. Redirection using ```>``` and ```<```
5. Use simple pipes with ```|```

## Attempted Features
placeholder

## Bugs
1. Using Quotes in a command (such as with ```git commit -m "message"``` causes an error)

## Files & Function Headers

### parse.c
  1. ```char** parse_args()```
      * Inputs: This function takes in a char * (line).
      * Returns: This function returns a char **
      * Desc: This function takes in a char *, separates it by spaces, and returns a char ** that can be used in execvp(). 

  2. ```void trim()```
      * Inputs: This function takes in a char * (line).
      * Returns: None
      * Desc: This function removes leading and trailing white space in line. 

  3. ```char** separate_commands()```
      * Inputs: This function takes in a char * (line) and a char * (delimiter).
      * Returns: This function returns a char **. 
      * Desc: This function takes in a char *, separates it by a given delimiter, and returns a char ** that can be used in execvp(). 

### custom_commands.c
  1. ```int my_cd()```
      * Inputs:
      * Returns:
      * Desc:

  2. ```int my_exit()```
      * Inputs:
      * Returns:
      * Desc:

### shell.c
  1. ```int execute_reg()```
      * Inputs:
      * Returns:
      * Desc:

  2. ```int execute_all()```
      * Inputs:
      * Returns:
      * Desc:

  3. ```int redirect_out()```
      * Inputs:
      * Returns:
      * Desc:

  4. ```int redirect_in()```
      * Inputs:
      * Returns:
      * Desc:

### main.c
  1. ```int main()```
      * Inputs:
      * Returns:
      * Desc:
