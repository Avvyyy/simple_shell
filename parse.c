#include "main.h"

char **parse_command(char *command)
{
    char **args = malloc(sizeof(char *) * (MAX_ARGS + 1));
    char *token;
    int i = 0;

    token = strtok(command, " \t\n");
    while (token != NULL && i < MAX_ARGS)
    {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    return args;
}
