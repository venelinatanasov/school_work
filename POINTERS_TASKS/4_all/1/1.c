#include <stdio.h>


int main()
{
	int arr[];


	for(int i=0;i<10;i++)
	{
		scanf("%d",(arr+i));
	}
	for(int i=0;i<10;i++)
	{
		printf("\n%d\n",*(arr+i));
	}


return 0;
}
