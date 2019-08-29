#include "shell.h"
/**
 *_strstr -function that searches a string f
 *@needle: string inlet
 *@haystack: match statement string
 *Return: s
**/
char *_strstr(char *haystack, char *needle)
{
	int i, j;
	int flag;

	for (j = 0; haystack[j] != '\0'; j++)
	{
		for (i = 0; needle[i] != '\0'; i++)
		{
			flag = 0;
			if (haystack[j + i] != needle[i])
			{
				flag = 1;
			break;
			}

		}
		if (needle[i] == '\0' && flag == 0)
		{
			return ((haystack + j));
		}
	}
	return (0);
}

/**
* *_strcat - concatenates two strins.
* @dest: destiny.
* @src: source.
* Return: the concatenates string.
*/

char *_strcat(char *dest, char *src)
{
	char *start = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (start);
}

/**
* _strlen - function that counts the long of a strin
* @s: the string to count
* Return: the long of a string
*/

int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

return (i);
}
/**
 * _strcmp - compare two strings and print the difference between the two
 *@s1: get the first string
 *@s2: get the second string
 * Return: return the diference between the two strings
 */
int _strcmp(char *s1, char *s2)
{
	int len;

	for (len = 0; s1[len] != '\0' || s2[len] != '\0'; len++)
	{
		if (s1[len] != s2[len])
		{
			return (s1[len] - s2[len]);
		}
	}
	return (*s1 - *s2);
}
