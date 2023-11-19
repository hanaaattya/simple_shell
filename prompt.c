#include "shell.h"

void prompt (void)
{
	char prompt[] = "#cisfun$ ";
	write(STDOUT_FILENO, prompt, sizeof(prompt) - 1);
}
