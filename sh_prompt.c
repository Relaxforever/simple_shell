#include "shell.h"

/**
* sh_prompt - function that call others function to init the shell
*/

void sh_prompt(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, sighandlerC);
	if (!isatty(STDIN_FILENO))
	{
		while (1)
		{
			line = sh_readline();
			args = sh_strok(line);
			status = sh_cmp(args);
		}
	}
	else
	{
		do {
			write(STDOUT_FILENO, "$ ", 2);
			line = sh_readline();
			args = sh_strok(line);
			status = sh_cmp(args);
			free(line);
			free(args);
		}
	while (status);
	}
}
