/*prompt is displayed again when executed */

void display_prompt(void)
{

    char *prompt = "shell";
    char *line;
    size_t bufsize = 0;

    while (1)
    {
        printf("%s$ ", prompt);
        getline(&line, &bufsize, stdin);
        printf("%s\n", line);

        /* free up allocated memory */
        free(line);
    }

    return 0;
}