#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

/* Define the structure info_t */
typedef struct
{
	int readfd;
} info_t;

void execmd(char **cmdargs);
char *get_location(char *command);
int execute_command(char *command);

/* Declaration of the execute_env function */
void execute_env(void);

/* Declaration of the interactive function */
int isInteractiveMode(info_t *info);

/* Declaration of the is_delim function */
int isDelimiter(char c, char *delim);

/* Declaration of the _isalpha function */
int isAlphabetic(int c);

/* Declaration of the _atoi function */
int _atoi(char *s);

/* Declaration of the shell function */
int shell(void);

#endif /* SHELL_H */
