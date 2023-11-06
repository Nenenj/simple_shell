#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct info
{
    int readfd;
} info_t;

/* Function prototypes */
int check_interactive_mode(info_t *info);
int is_delimiter(char c, char *delimiters);
int is_alpha(int c);
int string_to_integer(char *s);

#endif