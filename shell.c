#include "shell.h"

int main(int argc, char **argv)
{
	char *input = NULL;
	size_t input_size = 0;
	char *input_cpy = NULL;
	ssize_t bytes_read;
	char **tokenized;

	(void)argc;
	(void)argv;
	while(1)
		{
		prompt();
		bytes_read = getline(&input, &input_size, stdin);

		if (bytes_read == -1)
			{
				fprintf(stdout, "exiting\n");
				return (-1);
			}
		get_path(input);
		input_cpy = malloc(sizeof(char) * bytes_read);
			if (input_cpy == NULL)
				{
					perror("memory allocation error");
					return (-1);
				}
	strcpy(input_cpy, input);
	tokenized = tokenized_input(input_cpy);
	executed(tokenized);
		}
	free(input_cpy);
	free(input);
	return (0);
}
