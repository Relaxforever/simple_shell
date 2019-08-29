#include "shell.h"

/**
* sh_cmp - start the builint cases
* @args: compare the args is a builint
* Return: the builint or sh_execve if is not a builint
*/

int sh_cmp(char **args)
{
	char *arrayBuilint[] = {
	"exit",
	"help",
	"cd"
	};
	int (*built_intFunc[]) (char **) = {
	&sh_exit,
	&sh_help,
	&sh_cd
	};
	int i = 0;
	int sh_num_builtins = 0;

	sh_num_builtins = sizeof(built_intFunc) / sizeof(char *);

	if (args[0] == NULL)
	{
		return (1);
	}
	while (i < sh_num_builtins)
	{
		if (_strcmp(args[0], arrayBuilint[i]) == 0)
		{
			return (built_intFunc[i](args));
		}
		i++;
	}
	return (sh_execve(args));
}
