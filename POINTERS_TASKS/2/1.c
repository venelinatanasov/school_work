#include <stdio.h>


int main()
{
	
	int arr[10];
	
	for(int i=0;i<10;i++)
	{
		printf("\n%p\n",&arr[i]);
	}	
	printf("\n%ld\n",sizeof(int));
	
	
	
	return 0;
}
