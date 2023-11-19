#ifndef SHELL_H
#define SHELL_H
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
void executed(char **argv);
char *get_path(char *command);
void prompt (void);
char** tokenized_input(char *input_cpy);
#endif
