#include <stdio.h>
#include <stdlib.h>
#include <list.h>


int main()
{
	char c;
	char *buf;
	int len, n;
	List *list;
	n = 10;
	len = 0;
	buf = malloc(n * sizeof(char));
	while ((c = getchar()) != EOF)
		if ((c == ' ') || (c == '\n'))
		{
			
			printf("%s\n", buf);
			free(buf);
			len = 0;
			buf = malloc(n * sizeof(char));
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
		}
		printf("%c", c);
	printf("I've met EOF");
	return 0;
	
}
