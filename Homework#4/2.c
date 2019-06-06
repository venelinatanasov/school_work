#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Venelin Atanasov 10g N8

struct prod_t
{
	int product;
	int first_num_x;
	int first_num_y;
	char dir[20];
};



void exec();
void print_struct(struct prod_t);
void matr_input(int arr[15][15]);
int main()
{


	exec();

	return 0;
}
void matr_input(int arr[15][15])
{
	for(int y=0;y<15;y++)
	{
		for(int x=0;x<15;x++)
		{
			printf("Input %d %d\n",y,x);
			scanf("%d",&arr[y][x]);
		}
	}
}




void exec()
{
	/*int arr[15][15]=
	{
		{8, 02, 22, 97, 38, 15, 00, 40, 00, 75, 04, 05,  07, 78,52},
		{49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69},
		{81, 49, 31, 73, 55, 79, 14, 29, 93, 71, 40, 67, 53 , 88, 30},
		{52, 70, 95, 23, 04, 60, 11, 42, 69, 24, 68, 56,01, 32, 56},
		{22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 36, 54, 22, 40, 40},
		{24, 47, 32, 60, 99, 03, 45, 02, 44, 75, 33, 53, 78, 36, 84},
		{32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 40, 67, 59, 54, 70},
		{67, 26, 20, 68, 02, 62, 12, 20, 95, 63, 94, 39, 63, 8, 40},
		{24, 55, 58, 05, 66, 73, 99, 26, 97, 17, 78, 78, 96, 83, 14},
		{21, 36, 23, 9, 75, 50, 76, 44, 20, 45, 35, 14, 00, 61, 33},
		{78, 17, 53, 28, 22, 75, 31, 67, 15, 94, 03, 80, 04, 62, 16},
		{16, 39, 05, 42, 96, 35, 31, 47, 55, 58, 88, 24, 00, 17, 54},
		{86, 56, 00, 48, 35, 71, 89, 07, 05, 44, 44, 37, 44, 60, 21},
		{19, 80, 81, 68, 05, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17},
		{04, 52, 8, 83, 97, 35, 99, 16, 07, 97, 57, 32, 16, 26, 26},
	};*/
	int arr[15][15];

	matr_input(arr);

	int x,y;
	struct prod_t prod;
	prod.product=0;
	int curr;
	for(y=0;y<15;y++)
	{
		for(x=0;x<12;x++)
		{	
			curr=1;
			for(int i=0;i<4;i++)
			{
				curr*=arr[y][x+i];
			}
			if(curr>prod.product)
			{
				prod.product=curr;
				strcpy(prod.dir,"Horizontal");
				prod.first_num_x=x;
				prod.first_num_y=y;
			}
		}
		if(y<12)
		{
			
			for(x=0;x<15;x++)
			{
				curr=1;
				for(int i=0;i<4;i++)
				{
					curr*=arr[y+i][x];
				}
				if(curr>prod.product)
				{
					prod.product=curr;
					strcpy(prod.dir,"Vertical");
					prod.first_num_x=x;
					prod.first_num_y=y;
				}
			}
			for(x=0;x<12;x++)
			{
				curr=1;
				for(int i=0;i<4;i++)
				{
					curr*=arr[y+i][x+i];
				}
				if(curr>prod.product)
				{
					prod.product=curr;
					strcpy(prod.dir,"Diagonal");
					prod.first_num_x=x;
					prod.first_num_y=y;
				}
			}
			for(x=3;x<15;x++)
			{	curr=1;
				for(int i=0;i<4;i++)
				{
					curr*=arr[y+i][x-i];
				}
				if(curr>prod.product)
				{
					prod.product=curr;
					strcpy(prod.dir,"Diagonal");
					prod.first_num_x=x;
					prod.first_num_y=y;
				}
			}

		}
	}
		
					
				
	
				
	print_struct(prod);
				
			
		






}



void print_struct(struct prod_t prod)
{
	printf("%d %d %d %s\n",prod.product, prod.first_num_x, prod.first_num_y, prod.dir );
}
	
























