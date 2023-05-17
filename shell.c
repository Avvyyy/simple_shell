#include "main.h"

int main(void)
{
    char *input;
    pid_t pid;

    while (1)
    {
        input = get_line();

        if (str_cmp(input, "exit\n") == 0)
        {
            free(input);
            exit(EXIT_SUCCESS);
        }

        pid = fork();

        if (pid == -1)
        {
            perror("fork");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
            execute_command(input);
        else
        {
            wait(NULL);
            free(input);
        }
    }

    return (0);
}
