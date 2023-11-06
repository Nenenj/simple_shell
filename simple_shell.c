#include "shell.h"
#include <unistd.h>

#define STDIN_FILENO 0

/**
 * check_interactive_mode - checks if the shell is in interactive mode
 * @info: pointer to the shell's information struct
 *
 * Returns: 1 if interactive mode, 0 if not
 */
int check_interactive_mode(info_t *info)
{
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delimiter - checks if a character is a delimiter
 * @c: the character to check
 * @delimiters: the delimiter string
 * Returns: 1 if it's a delimiter, 0 if not
 */
int is_delimiter(char c, char *delimiters)
{
    while (*delimiters)
    {
        if (*delimiters++ == c)
        {
            return 1;
        }
    }
    return 0;
}

/**
 * is_alpha - checks if a character is alphabetic
 * @c: the character to check
 * Returns: 1 if it's alphabetic, 0 if not
 */
int is_alpha(int c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

/**
 * string_to_integer - converts a string to an integer
 * @s: the string to be converted
 * Returns: 0 if no numbers in the string, the converted number otherwise
 */
int string_to_integer(char *s)
{
    int i, sign = 1, flag = 0, output;
    unsigned int result = 0;

    for (i = 0; s[i] != '\0' && flag != 2; i++)
    {
        if (s[i] == '-')
        {
            sign *= -1;
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            flag = 1;
            result *= 10;
            result += (s[i] - '0');
        }
        else if (flag == 1)
        {
            flag = 2;
        }
    }

    if (sign == -1)
    {
        output = -result;
    }
    else
    {
        output = result;
    }

    return output;
}