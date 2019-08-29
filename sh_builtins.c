#include "shell.h"

/**
* sh_cd - functio that changes the current directory
* @args: argument to compare with cd
* Return: 1
*/

int sh_cd(char **args)
{
	if (args[1] == NULL)
		perror("expected argument to \"cd\"\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("Error to chdir");
	}
return (1);
}

/**
* sh_help - function that introduce the user
* @args: argument to compare with the word help
* Return: 1
*/

int sh_help(char **args)
{
	(void) args;
	write(1, "Welcome to our own shell, We are the Caicedo's Brother's\n", 59);
	write(1, "Our current Built-ins are \n cd \n exit \n help\n", 45);
return (1);
}

/**
* sh_exit - exits from the shell
* @args: the argument written in the shell.
* Return: 1
*/
int sh_exit(char **args)
{
	(void) args;
	return (0);
}
