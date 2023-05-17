#include "main.h"

void execute_command(char *command)
{
    char **args = parse_command(command);

    char *path = getenv("PATH");
    char *path_token = strtok(path, ":");

    char command_full_path[1024];

    while (path_token != NULL)
    {
        snprintf(command_full_path, sizeof(command_full_path), "%s/%s", path_token, args[0]);

        if (access(command_full_path, X_OK) == 0)
        {
            pid_t pid = fork();
            if (pid == -1)
            {
                perror("fork");
                exit(EXIT_FAILURE);
            }
            else if (pid == 0)
            {
                char *envp[] = { NULL };
                execve(command_full_path, args, envp);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            else
            {
                int status;
                waitpid(pid, &status, 0);
                if (WIFEXITED(status))
                {
                    int exit_status = WEXITSTATUS(status);
                    if (exit_status == 0)
                    {
                        free(args);
                        return;
                    }
                }
            }
        }
        path_token = strtok(NULL, ":");
    }

    printf("Command not found: %s\n", args[0]);
    free(args);
}
