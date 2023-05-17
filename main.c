#include "main.h"

int main(void)
{
    char *input;

    while (1)
    {
        input = get_line();

        if (strcmp(input, "exit\n") == 0)
        {
            free(input);
            exit(EXIT_SUCCESS);
        }

        execute_command(input);

        free(input);
    }

    return 0;
}
