#include "shell.h"

/**
* _strncmp - compares at most the first n bytes of str1 and str2
* @s1: the first string to be compared
* @s2: the second string to be compared
* @n: the maximun number of character to be compared
* Return: return 0 if the strings are equals
*/

int _strncmp(char *s1, const char *s2, int n)
{
	int i, res = 0;

	for (i = 0; i < n; i++)
	{
		if (s1[i] != s2[i])
		{
			res = s1[i] - s2[i];
			break;
		}
	}
	return (res);
}

/**
* _strcpy - copies the string pointed to, by src to dest
* @dest: the destination array where the content is to be copied
* @src: this is the string to be copied
* Return: this returns a pointer to the destination string dest
*/

char *_strcpy(char *dest, char *src)
{
	int cont;
	int cont2;

	for (cont = 0; src[cont] != '\0'; cont++)
	{
	}
	for (cont2 = 0; cont2 <= cont; cont2++)
	{
		dest[cont2] = src[cont2];
	}
	dest[cont2 + 1] = '\0';
	return (dest);
}

/**
* _getenv - this function returns a PATH list of tokens
* @name: search a global variable
* Return: list of tokens
*/

char **_getenv(const char *name)
{
	int i, j, buffer = 1024;
	char *ptr, *str;
	char *array;
	char **buff;

	str = malloc(buffer * sizeof(char));
	if (str == NULL)
	{
		perror("malloc str");
	}
	buff = malloc(buffer * sizeof(char *));
	if (buff == NULL)
	{
		perror("malloc buff");
	}
	i = 0;
	while (environ[i])
	{
		if (_strncmp(environ[i], name, 4) == 0)
		{
			ptr = environ[i];
			_strcpy(str, ptr);
			array =	strtok(str, ":=");
			j = 0;
			while (array != NULL)
			{
				buff[j] = array;
				array = strtok(NULL, ":=");
				j++;
			}
			buff[j] = NULL;
			return (buff);
		}
		i++;
	}
	perror("variable not found");
	free(buff);
	free(str);
	return (0);
}

/**
* slash - add a / in each position of the array
* Return: return a list with /
*/

char **slash(void)
{
	int i;
	char *path;
	char **ptr;
	char **list = NULL;

	ptr = _getenv("PATH");
	list = _calloc(1024, sizeof(char));
	if (list == NULL)
		return (NULL);
	path = malloc(sizeof(char) * 500);
	if (path == NULL)
		return (NULL);
	i = 0;
	while (ptr[i] != NULL)
	{
		_strcpy(path, ptr[i]);
		_strcat(path, "/");
		list[i] = malloc(sizeof(char) * 1024);
		_strcpy(list[i], path);
	i++;
	}
	free(ptr[0]);
	free(ptr);
	free(path);
	return (list);
}
