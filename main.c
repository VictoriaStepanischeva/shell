#include <stdio.h>
#include <stdlib.h>


int main()
{
	char c, prev;
	char *buf;
	int len, n;
	n = 10;
	len = 0;
	prev = ' ';
	buf = malloc(n * sizeof(char));
	while ((c = getchar()) != EOF)
		if (((c == ' ') || (c =='\n')) && (prev != ' '))
		{
			
			printf("%s\n", buf);
			free(buf);
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
			}
			prev = c;
		}
		printf("%c", c);
	printf("I've met EOF");
	return 0;
	
}
