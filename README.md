0x16. C - Simple Shell

This project is an implementation of the shell created for the C code sprint at ALX Africa.
It is a simple UNIX command interpreter that replicates functionalities of the simple shell (sh) and more other functions are also included. It is based on the Thompson Shell.

Installation:
All your files were compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89.

Testing:
After compilation using gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh, the resulting program can run stand-alone, either in interactive or non-interactive mode.

AUTHORS:
This file contails details of all the contributors to this shell project.

Feature Tasks:
Write a UNIX command line interpreter.

Usage: simple_shell
Your Shell should:

Display a prompt and wait for the user to type a command. A command line always ends with a new line.
The prompt is displayed again each time a command has been executed.
The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
The command lines are made only of one word. No arguments will be passed to programs.
If an executable cannot be found, print an error message and display the prompt again.
Handle errors.
You have to handle the “end of file” condition (Ctrl+D)

You don’t have to:

use the PATH
implement built-ins
handle special characters : ", ', `, \, *, &, #
be able to move the cursor
handle commands with arguments


