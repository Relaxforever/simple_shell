#include "shell.h"

/**
* sh_execve - funciton that execute the command
* @args: argument the user
* Return: 1
*/

int sh_execve(char **args)
{
	pid_t pid;
	int status;
	char *tmp = NULL, **bin = NULL;

	bin = slash();
	tmp = auxi(bin, args, tmp);
	switch (pid = fork())
	{
		case -1:
			free_double(bin);
			free(args);
			perror("Error fork");
			break;
		case 0:
			aux(args, bin);
			if (tmp == NULL)
			{
				free_double(bin);
				free_double(args);
				 exit(0);
			}
			if (execve(tmp, args, environ) == -1)
			{
				perror("Error execve");
				free_double(args);
				free(tmp);
				free_double(bin);
				exit(0);
			}
			free(args);
			free_double(bin);
			break;
		default:
			free_double(bin);
			wait(&status);
			break;
	}
	return (1);
}
