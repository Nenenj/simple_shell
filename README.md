##0x16. C - Simple Shell
#Introduction
This project involves creating a simple UNIX command-line interpreter, or shell, which mimics some basic functionalities of a shell like Bash. The shell will support interactive mode where it displays a prompt and waits for user input, as well as non-interactive mode where it can read commands from a file.

#List of Allowed Functions and System Calls
The following functions and system calls are allowed for use in this project:
•	access
•	chdir
•	close
•	closedir
•	execve
•	exit
•	_exit
•	fflush
•	fork
•	free
•	getcwd
•	getline
•	getpid
•	isatty
•	kill
•	malloc
•	open
•	opendir
•	perror
•	read
•	readdir
•	signal
•	stat (__xstat)
•	lstat (__lxstat)
•	fstat (__fxstat)
•	strtok
•	wait
•	waitpid
•	wait3
•	wait4
•	write

##Compilation
To compile your shell, use the following command:
bashCopy code
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh 

##Testing
You can test your shell in both interactive and non-interactive modes.

##Interactive Mode
In interactive mode, the shell will display a prompt and wait for user input.

##Non-Interactive Mode
In non-interactive mode, you can use input redirection or pipe commands to your shell.  

##Tasks
The project consists of multiple tasks, and each task builds upon the previous ones. Here is a brief overview of the tasks:
#Task 0: Betty Would Be Proud
•	Ensure your code adheres to the Betty coding style.

#Task 1: Simple Shell 0.1
•	Create a basic shell that handles user input and executes simple one-word commands.

#Task 2: Simple Shell 0.2
•	Extend the shell to handle command lines with arguments.

#Task 3: Simple Shell 0.3
•	Implement PATH handling and avoid calling fork if the command doesn't exist.

#Task 4: Simple Shell 0.4
•	Implement the exit built-in command.

#Task 5: Simple Shell 1.0
•	Implement the env built-in command to print the current environment.

#Task 6: Simple Shell 0.1.1 (Advanced)
•	Write your own getline function to read input efficiently.

#Task 7: Simple Shell 0.2.1 (Advanced)
•	Avoid using strtok and implement your own way to parse input.

#Task 8: Simple Shell 0.4.1 (Advanced)
•	Handle arguments for the exit built-in command.

#Task 9: setenv, unsetenv (Advanced)
•	Implement the setenv and unsetenv built-in commands.

#Task 10: cd (Advanced)
•	Implement the cd built-in command to change the current directory.

#Task 11: ; (Advanced)
•	Handle commands separated by semicolons.

#Task 12: && and || (Advanced)
•	Handle logical operators && and || for command execution.

#Task 13: alias (Advanced)
•	Implement the alias built-in command.

#Task 14: Variables (Advanced)
•	Handle variable replacement including $? and $$.

#Task 15: Comments (Advanced)
•	Handle comments in commands using #.

#Task 16: File as Input (Advanced)
•	Allow the shell to read and execute commands from a file.

##Conclusion
This README provides an overview of the project requirements and tasks for the Simple Shell project (0x16). It outlines the allowed functions and system calls, compilation instructions, testing procedures, and an overview of the tasks to be completed.

For detailed information and implementation guidelines, please refer to the specific task descriptions in this README and the provided GitHub repository: [simple_shell](https://github.com/Nenenj/simple_shell.git).
