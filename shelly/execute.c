#include "shell.h"

/**
 * output - decide what to do with @args
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void output(char **args, char **av)
{
	if (args[0][0] == '/')
		execute(args, av);
	else
	{
		args = check_path(args);
		if (args != NULL)
			execute(args, av);
	}
}

/**
 * execute - execute a program
 *
 * @args: array of argument strings
 *
 * Return: void
 */
void execute(char **args, char **av)
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == -1)
	{
		perror(av[0]);
		_exit(99);
	}
	if (pid == 0)
	{
		if (execve(args[0], args, environ))
		{
			perror(av[0]);
			free(args);
		}
		exit(1);
	}
	else
		wait(&status);
}
