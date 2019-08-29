
#ifndef _SHELLLIST_H_
#define _SHELLLIST_H_
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
void sh_prompt(void);
char *sh_readline(void);
char **sh_strok(char *line);
int sh_execve(char **args);
int sh_help(char **args);
int sh_cd(char **args);
int sh_exit(char **args);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int sh_num_builtins(void);
int _strcmp(char *s1, char *s2);
int sh_cmp(char **args);
char *_strstr(char *haystack, char *needle);
extern char **environ;
char **_getenv(const char *name);
char *_strcpy(char *dest, char *src);
char **slash(void);
void sighandlerC(int sig);
void free_double(char **ptr);
void *_calloc(unsigned int nmemb, unsigned int size);
void aux(char **args, char **bin);
char *auxi(char **bin, char **args, char *tmp);
#endif
