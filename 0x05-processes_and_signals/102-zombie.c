#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
/**
* infinite_while - An infinite while loop.
*
* Return: Always 0.
*/
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}
/**
* main - creates 5 zombie processes
*
* Return: 0 on success.
*/
int main(void)
{
	int i;
	pid_t pid;

	i = 0;
	while (i < 5)
	{
		pid = fork();
		if (pid > 0)
		{
			printf("Zombie process created, PID: %d\n", pid);
			sleep(1);
			i++;
		}
		else
			exit(0);
	}

	infinite_while();
	return (0);
}
