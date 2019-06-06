#include <stdio.h>

int main()
{

	int a;
	scanf("%d",&a);
	int *ptr = a;
	int b;
	scanf("%d",&b);
	
	printf("%d",*ptr);
	return 0;
}
