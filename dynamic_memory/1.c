#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{	int i=0;
	char *ptr=(char *)malloc(sizeof(char));
	ptr[i]=getchar();
	while(ptr[i]!=EOF)
	{
		
		i++;
		ptr=realloc(ptr,(i+1)*sizeof(char));
		ptr[i]=getchar();
	}
	ptr[i]='\0';
	while(i>=0)
	{
		putchar(ptr[i]);
		i--;
	}
	putchar('\n');




	free(ptr);
	
	return 0;
}
