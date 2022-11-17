#include "shellyy.h"

/**
 * main - the main function
 * Desription: prints ppid
 * Return: default 0
 */

int main(void)
{
	pid_t myppid;

	myppid = getppid();
	printf("getppid%u\n: ", myppid);

	return (0);
}
