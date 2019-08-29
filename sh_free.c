#include "shell.h"

/**
* free_double - function that free double pointers
* @ptr: double pointer to free
*/

void free_double(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i] != NULL)
	{
		free(ptr[i]);
		i++;
	}
free(ptr);
}

/**
* _calloc - function that allocates memory for an array.
* @nmemb: number of elements to be allocated.
* @size: size of elements
* Return: something
*/

void *_calloc(unsigned int nmemb, unsigned int size)
{
	char *ptr;
	unsigned int i = 0, hey;

	hey = size * nmemb;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(hey * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < hey)
	{
		ptr[i] = 0;
		i++;
	}
return (ptr);
}

/**
* aux - function that help in execve function
* @args: arguments the user
* @bin: list
*/

void aux(char **args, char **bin)
{
	int i;

	i = 0;
	while (args[0][i])
	{
		if (args[0][i] == '/')
		{
			free_double(bin);
			if (execve(args[0], args, environ) == -1)
			{
				perror("./hsh");
				free_double(args);
				exit(0);
			}
			free(args);
		}
		i++;
	}
}
/**
* auxi - a cycle to check the if we have only like ls and it concatenates it
* @bin: the path broken in different things
* @args: the argument given
* @tmp: the value changed
* Return: the vale changed if it works
*/
char *auxi(char **bin, char **args, char *tmp)
{
	int i;

	i = 1;
	while (bin[i] != NULL)
	{
		_strcat(bin[i], args[0]);
		if (access(bin[i], X_OK) != -1)
		{
			tmp = bin[i];
			return (tmp);
		}
	i++;
	}
return (NULL);
}
