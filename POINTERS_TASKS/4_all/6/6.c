#include <stdio.h>

void get_min_max(int *arr, int *min, int *max, int size)
{
	*min=arr[0];
	*max=arr[0];
	for(int i=0;i<size;i++)
	{
		if(arr[i]>*max)
		{
			*max=arr[i];
		}
		if(arr[i]<*min)
		{
			*min=arr[i];
		}
	}
}
		










int main()
{
	
	int arr[]={1,20,3,5,4};
	int max, min;
	get_min_max(arr, &min, &max, 5);
	printf("\n%d\n%d\n",max, min);





	return 0;
}
