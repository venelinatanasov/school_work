#include <stdio.h>



void sum(int *arr, int size, int *sum)
{
	*sum=0;
	for(int i=0;i<size;i++)
	{
		*sum=*sum+arr[i];
	}
}
		



int main()
{
	int sum1;
	int arr[10]={1,1,1,1,1,10,1,1,1,1};
	sum(arr,10,&sum1);
	printf("\n%d\n",sum1);	
		
	
	
	
	return 0;
}
