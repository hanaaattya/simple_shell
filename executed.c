#include "shell.h"

void executed(char **argv)

{
	char *command = NULL;
	char *full_command;

	if (argv)
	{
	command = argv[0];
	full_command = get_path(command);
	if (execve(full_command, argv, NULL) == -1)
		{
		perror("Error:");
		}
	}
}
