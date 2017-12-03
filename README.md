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
1. Running C-SHELL from C-SHELL and exiting the second shell with "Ctrl-D" causes an infinite loop
2. Using Quotes in a command (such as with ```git commit -m "message"``` causes an error)

## Files & Function Headers

### parse.c
  1. ```char** parse_args()```
      * Inputs:
      * Returns:
      * Desc:
  
  2. ```void trim()```
      * Inputs:
      * Returns:
      * Desc:

  3. ```char** separate_commands()```
      * Inputs:
      * Returns:
      * Desc:

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
