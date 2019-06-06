#include <stdio.h>
void reverse(int *arr, int size)
{	int buff;
	for(int i=0;i<size-i-1;i++)
	{
		buff=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=buff;
	}
}

void sort(int *arr, int size, int direction)
{
	int buff;
	for(int i=0;i<size-1;i++)
	{
		for(int z=0;z<size-1;z++)
		{
			if(arr[z]>arr[z+1])
			{
				buff=arr[z];
				arr[z]=arr[z+1];
				arr[z+1]=buff;
			}
		}
	}
	if(direction<0)
	{
		reverse(arr,size);
	}
		
	
	
}


		
					

int main()
{
	int arr[]={10,9,7,8,4,6,5,3,2,1};
	for(int i=0;i<10;i++)
	{
		printf("%d",arr[i]);
	}	
	printf("\n");

	sort(arr,10,23); 


	for(int i=0;i<10;i++)
	{
		printf("%d",arr[i]);
	}	
	printf("\n");





	return 0;
}
