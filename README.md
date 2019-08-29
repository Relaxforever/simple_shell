# The Shell Project.

The shell project is fundamentally a project made to understand how really a shell and implements the juicy stuff of C in it, so we made a basic shell that you can use and check everything about it, This is the climax of everything we had done in C this first trimester.This shell is expected to do:
  - handle basic  commands with basic arguments Ex: /bin/ls
  - Be capable of exiting the shell succesfully.
  - Be awesome.!

# How to Install It.
So this Shell is texted in linux, Using the version of Ubuntu ```14.04 LTS```  will be compiled with gcc 4.8.4 using the flags ``` $ -Wall -Werror -Wextra and -pedantic ```
  - This code has only been tested in this kind of enviroment so we don't know how it will behave in the end.
  - This is a basic shell so don't expect anything out of the extraordinary.

So to start using this basic shell you need to first clone the repository 
```$ git clone https://github.com/Relaxforever/simple_shell.git ```
After you clone it you will find an already working shell called **hsh** but if you want can recompile everything with ```$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh ```
after that you will have an executable file called **hsh**

# How to Execute it and some examples.
So after we have the executable we simply need to execute it .
```bash
ubuntu/trusty64  $./hsh
$
```
So after we are in our own homebrew shell I'm going to show you some examples,it should handle by default the ls command with /bin/ls and without the ls.
```bash
$ /bin/ls
example.txt hello.txt World.txt
$ ls
example.txt hello.txt World.txt
```
we can also use it on non-interactive mode
```bash
$ echo "/bin/ls" | ./hsh
example.txt hello.txt World.txt
ubuntu/trusty64 $
```

You can also:
  - use it with Path direct version or only "ls"
  - Use any variable that is found in PATH of ubuntu 14.04.
 
You can feel to try and report any bug you find in the Shell to me.

# Header File
```C
#ifndef _SHELLLIST_H_
#define _SHELLLIST_H_

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
char *slash(void);
void sighandlerC(int sig);
```
To make the code more easibly readable we put all important macros in the header file so we only included the shell.h in our *.c files
### Usage

This Shell is made in C version C90
Most important function to keep in mid if you find yourself not understanding the code is 
``` Man ```  strtok
``` Man ```  acces
``` Man ```  getline
``` Man ```  isatty  
``` Man ``` signal

### Development

If you want to contribute you can email alafresh16@hotmail.com to ask him for permissions.

### Todos

 - Write MORE Tests
 - make a better ```PATH```
 - apply correctly more advanced functions
 - Create pipes.

License
Free Software except Bjarne Stroustrup

# Authors
Fidel Fernando Caicedo And Juan Guillermo Caicedo Castaño.
**Free Software, Hell Yeah!**
