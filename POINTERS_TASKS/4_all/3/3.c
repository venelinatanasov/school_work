#include <stdio.h>

void rotl(int *a, int *b, int *c)
{
	int buff;
	buff=*a;
	*a=*b;
	*b=*c;
	*c=buff;
}




int main()
{
	
	int a=1,b=2,c=3;
	printf("\n%d\n%d\n%d\n\n",a,b,c);
	rotl(&a,&b,&c);
	printf("\n%d\n%d\n%d\n\n",a,b,c);
	rotl(&a,&b,&c);
	printf("\n%d\n%d\n%d\n\n",a,b,c);		
	
	
	
	
	
	return 0;
}
