#include <stdio.h>
#include <string.h>

void swap(int *a, int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
}



void sort(int *arr, int size)
{

	for(int i=0;i<size-1;i++)
	{
		for(int z=0;z<size-1;z++)
		{
			if(arr[z]<arr[z+1])
			{
				swap(&arr[z],&arr[z+1]);
			}
		}
	}
}




int vowel_count(char *ch)
{	int k=0;
	for(int i=0;i<strlen(ch);i++)
	{
		if(*(ch+i)=='a'||*(ch+i)=='A'||*(ch+i)=='e'||*(ch+i)=='E'||*(ch+i)=='i'||*(ch+i)=='I'||*(ch+i)=='o'||*(ch+i)=='O'||*(ch+i)=='u'||*(ch+i)=='U'||*(ch+i)=='y'||*(ch+i)=='Y')
		{
			k++;
		}
	}
	return k;
}
			
			
void count_numbers(int *arr, int *even,int *odd,int size)
{
	for(int i=0;i<size;i++)
	{
		if(!(arr[i]%2))
		{
			(*even)++;
			printf("\n%d\n",*even);
		}
		else
		{
			(*odd)++;
		}
	}
}
			



int str_in_str(char *srch, char *main)
{
	int h;
	if(strlen(srch)>strlen(main))
	{
		return -1;
	}
	for(int i=0;i<strlen(main)-strlen(srch)+1;i++)
	{
		h=i;
		for(int z=0;z<strlen(srch);z++)
		{	
			if(*(srch+z)!=*(main+h))
			{
				break;
			}
			if(z==strlen(srch)-1)
			{
				return 1;
			}
			h++;
		}
		
	}
	return 0;
}
			
		
void print_arr(char arr[10][10])
{
	putchar('\n');
	for(int i=0;i<10;i++)
	{
		for(int z=0;z<10;z++)
		{
			putchar(arr[i][z]);
		}
		putchar('\n');
	}
}
	

void draw_square(char arr[10][10], int x, int y,int s)
{
	if(x+s>10||y+s>10)
	{
		return;
	}
	for(int i=0;i<10;i++)
	{
		for(int z=0;z<10;z++)
		{
			arr[i][z]='.';
		}
	}
	for(int i=x;i<x+s;i++)
	{
		for(int z=y;z<y+s;z++)
		{
			arr[z][i]='|';
		}
	}
}













int main()
{
	//int arr[]={1,2,10,9,8,-7,6,4,4,3};
	/*sort(arr,10);
	for(int i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}*/
	//printf("\n%d\n",vowel_count("abcdefghijklmnopqrstuvwxyz"));
	/*int even=0;
	int odd=0;
	count_numbers(arr,&even,&odd,10);
	printf("\nEven: %d\nOdd: %d\n",even,odd);*/
	//printf("\nstrinstr: %d\n",str_in_str("rtitsata","1qqwdfpeshokyrtitsata"));
	char arr[10][10];
	draw_square(arr,1,2,9);
	print_arr(arr);
	
	

	return 0;

}

































