#include <stdio.h>


void swap(int *,int *);

int main()
{

	int a=1;
	int b=5;
	swap(&a,&b);
	printf("\n%d\n",a);
	printf("\n%d\n",b);


	return 0;
}


void swap(int *a, int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
