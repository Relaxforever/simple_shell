#include "shell.h"

/**
* sighandlerC - handles signals
* @sig: the number of the signal received.
*/

void sighandlerC(int sig)
{
	(void)sig;
	putchar('\n');
	write(STDOUT_FILENO, "$ ", 3);
	fflush(stdout);
}

