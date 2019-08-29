#include "shell.h"
/**
* sh_readline - get a line from the user
* Return: returns the text of the line readed
*/

char *sh_readline(void)
{
	char *line = NULL;
	size_t len = 0;

	if (getline(&line, &len, stdin) == EOF)
	{
		free(line);
		exit(0);
	}
return (line);
}
