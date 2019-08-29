#include "shell.h"

/**
* sh_strok - function that breaks string into a series of tokens
* @line: the content
* Return: return a serie of tokens
*/

char **sh_strok(char *line)
{
	int i, buf;
	char *tok;
	char **tokens;

	buf = 64;
	tokens = malloc(buf * sizeof(char *));
	if (tokens == NULL)
	{
		perror("Error to allocate size");
		free(tokens);
		exit(1);
	}
	tok = strtok(line, "\t\r\n ");
	i = 0;
	while (tok != NULL)
	{
		tokens[i] = tok;
		i++;
		tok = strtok(NULL, "\t\r\n ");
	}
	tokens[i] = NULL;
	return (tokens);
}
