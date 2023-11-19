#include "shell.h"

char *get_path(char *command)
{
	char *path;
	char *path_cpy;
	char *path_token;
	char *path_mlocated;
	int command_len;
	int directory_len;
	struct stat buffer;

	path = getenv("PATH");
	if (path)
	{
		path_cpy = strdup(path);
		command_len = strlen(command);
		path_token = strtok(path_cpy, ":");
			while (path_token != NULL)
				{
					directory_len = strlen(path_token);
					path_mlocated = malloc(command_len + directory_len + 2);
					strcpy(path_mlocated, path_token);
					strcat(path_mlocated, "/");
					strcat(path_mlocated, command);
					strcat(path_mlocated, "\0");
					if (stat(path_mlocated, &buffer) == 0)
						{
							free(path_cpy);
							return (path_mlocated);
						}
					else
						{
							free(path_mlocated);
							path_token = strtok(NULL, ":");
						}
				}
	free(path_cpy);
						if (stat(command, &buffer) == 0)
							{
								return (command);
							}
						return NULL;
	}
	return NULL;
}
