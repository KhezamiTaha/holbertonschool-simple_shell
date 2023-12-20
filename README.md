# Simple Shell Implementation in C

This is a basic implementation of a simple shell in C, adhering to the specifications outlined in the Holberton project requirements.

## Table of Contents

- [Description](#description)
- [Features](#features)
- [Files](#files)
- [Requirements](#requirements)
- [Compilation](#compilation)
- [Testing](#testing)
- [Documentation](#documentation)
- [Final Checks](#final-checks)

## Description

This project implements a simple shell in C that supports basic command execution, environment variable display, and shell exit functionality.

## Features

- **Command Execution:** Executes commands using fork and execve.
- **Environment Variables:** Displays current environment variables.
- **Exit Command:** Exits the shell.

## Files

- **hsh.h:** Header file containing function prototypes and necessary includes.
- **main.c:** The main file containing the entry point and the main loop of the shell.
- **get_line.c:** Implementation of the function to read a line of input.
- **execute.c:** Implementation of the function to execute commands.
- **get_path.c:** Implementation of the function to find the full path of a command.
- **print_env.c:** Implementation of the function to print environment variables.
- **exit.c:** Implementation of the function to exit the shell.

## Requirements

- Allowed editors: vi, vim, emacs
- Compiled on Ubuntu 20.04 LTS using gcc with options `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Follows the Betty style using `betty-style.pl` and `betty-doc.pl`
- No memory leaks
- No more than 5 functions per file
- All header files include guarded
- Uses system calls only when necessary

## Compilation

Compile the shell using the following command:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
Testing
Run the shell in interactive mode:

bash
Copy code
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
Run the shell in non-interactive mode:

bash
Copy code
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
Documentation
A detailed README is available at the root of the project folder, providing information on how to compile, test, and use the shell.

Final Checks
Ensure compliance with the Betty style and system call usage.
Use the provided Checker for additional checks and testing.





