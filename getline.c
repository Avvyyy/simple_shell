#include "main.h"

char *get_line(void)
{
    char *buffer = NULL;
    size_t buffer_len = 0;

    printf("$ ");
    fflush(stdout);

    if(getline(&buffer, &buffer_len, stdin) == -1)
    {
        perror("getline");
        exit(EXIT_FAILURE);
    }

    return (buffer);
}
