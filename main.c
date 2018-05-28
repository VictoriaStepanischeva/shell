#include <stdio.h>
#include <stdlib.h>


int main()
{
	char c, prev;
	char *buf, *first, *argv;
	char **commands;
	int len, n, nc, argc, i, pid;
	argc = 0;
	n = 10;
	nc = 10;
	len = 0;
	prev = ' ';

	/* parsing */
	buf = (char*)malloc(n * sizeof(char));
	commands = (char**)malloc(n * sizeof(char*));
	for (i = 0; i < nc; i++)
	{
		commands[i] = malloc(n*sizeof(char*));
	}
	while ((c = getchar()) != EOF)
		if (((c == ' ') || (c =='\n')) && (prev != ' '))
		{
			
			if (argc == nc)
			{
				nc = 2 * nc;
				commands = realloc(commands, nc * sizeof(char*));
				for (i = 0; i <= nc; i++)
				{
					commands[i] = realloc(commands[i], n * sizeof(char*));
				}
			}
			for (i=0; i<len; i++)
			{
				commands[argc][i] = buf[i];
			}
			free(buf);
			argc = argc + 1;
			len = 0;
			buf = malloc(n * sizeof(char));
			prev = ' ';
		}
		else if ((c == ' ') && (prev == ' '))
		{
			prev = ' ';
		}
		else
		{
			buf[len] = c;
			len = len + 1;
			if (len >= n)
			{
				n = 2 * n;
				buf = realloc(buf, n * sizeof(char));
				for (i = 0; i <= nc; i++)
				{
					commands[i] = realloc(commands[i], n * sizeof(char));
				}
			}
			prev = c;
		}
	printf("I've met EOF");
	first
	for (i=0; i<argc; i++)
	{
		printf("%s\n", commands[i]);
	}
	
	/* execution */
	return 0;
	
}
