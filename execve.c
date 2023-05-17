#include "main.h"

void execute_command(char *command, ...)
{
    va_list args_list;
    va_start(args_list, command);

    int num_args = count_args(command);

    char **args = malloc(sizeof(char *) * (num_args + 1));

    int i = 0;
    char *arg;

    args[i] = command;
    i++;

    while ((arg = va_arg(args_list, char *)) != NULL)
    {
        args[i] = arg;
        i++;
    }

    args[i] = NULL;

    va_end(args_list);

    char *path = getenv("PATH");
    char *path_token = strtok(path, ":");

    char *command_path = args[0];

    while (path_token != NULL)
    {
        char command_full_path[1024];
        snprintf(command_full_path, sizeof(command_full_path), "%s/%s", path_token, command_path);

        if (access(command_full_path, X_OK) == 0)
        {
            if (execve(command_full_path, args, NULL) == -1)
            {
                perror("execve");
                exit(EXIT_FAILURE);
            }
        }
        path_token = strtok(NULL, ":");
    }

    free(args);
}

