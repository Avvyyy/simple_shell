#ifndef MAIN_H
#define MAIN_H

/**Header files**/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdarg.h>

int main(void);
char *get_line(void);
int str_cmp(const char *s1, const char *s2);
void execute_command(char *command);

#endif
