#include "shell.h"

char** tokenized_input(char *input_cpy)
{
	char *delim = "\n";
	char *token;
	char **argv;
	int i;
	int j;
	int noftokens = 0;

	token = strtok(input_cpy, delim);
	while (token != NULL)
	{
	noftokens++;
	token = strtok(NULL, delim);
	}

	argv = malloc(sizeof(char *) * (noftokens + 1));
	if (argv == NULL)
	{
	perror("memory allocation error");
	return NULL;
	}
	token = strtok(input_cpy, delim);
	for (i = 0; token != NULL; i++)
	{
	argv[i] = malloc(sizeof(char) * (strlen(token) + 1));
	if (argv[i] == NULL)
	{
	perror("memory allocation error");
	for (j = 0; j < i; j++)
	{
	free(argv[j]);
	}
	free(argv);
	return NULL;
	}
	strcpy(argv[i], token);
	token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	return argv;
}
