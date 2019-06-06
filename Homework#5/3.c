#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int get_size(FILE *);
void read_from_file(FILE *, int,int [][1000]);
void print_matr(int,int [][1000]);
int find_smallest_dist(int ,int,int,int [][1000]);
int is_connected_to(int,int [][1000], int, int);
int find_way_1(int, int[][1000], int, int);
int find_way_2(int, int[][1000], int, int);
int find_way(int, int[][1000], int, int);


int way1=0,way2=0;
int main()
{
	
	
	//char num[1];//char num[2];
	//fgets(num,1,f);
	//printf("%d",atoi(num));
	
	FILE *f=fopen("in.txt","r");
       	int n=get_size(f);
	int matr[n][n];
	read_from_file(f,n,matr);
	fclose(f);
	int x,y;
	//print_matr(n,matr);
	scanf("%d",&x);
	scanf("%d",&y);
	printf("%d\n",find_way(n,matr,x,y));





	//putchar('\n');



	return 0;
}




int get_size(FILE *f)
{char a;
	a=fgetc(f);
	int n=a-'0';
	a=fgetc(f);
	return n;
}

void read_from_file(FILE *f,int n,int matr[n][n])
{
	
	
	//a=fgetc(f);
	/*char num[2]*/;int y=0;int x=0;
	char a;
	while((y<n))
	{
		a=fgetc(f);
		if(a>='0'&&a<='9')
		{
			matr[y][x]=a-'0';
			x++;
		}
		if(a=='-')
		{
			matr[y][x]=-1;
			a=fgetc(f);
			x++;
		}
		


		if(a=='\n')
		{
			y++;
			x=0;
		}
		
	}
}

void print_matr(int n, int matr[n][n])
{	
	for(int y=0;y<n;y++)
	{
		for(int x=0;x<n;x++)
		{
			printf("%d",matr[y][x]);
		}
		putchar('\n');
	}
}






int is_connected_to(int n, int matr[n][n], int x, int y)
{
	
	if(matr[y][x]>0)
	{
		return matr[y][x];
	}
	else return 0;
}

int find_way_1(int n, int matr[n][n], int x, int y)
{
	
	int i=x;//0
	if(is_connected_to(n,matr,x,y/*2*/))
	{
		way1+=is_connected_to(n,matr,x,y);
		return 0;
	}
	else
	{
		
		while((!is_connected_to(n,matr,i,x)))
		{
			
			i++;
			if(i==n)
			{
				i=0;
			}
		}
		way1+=is_connected_to(n,matr,i,x);		//1
			
			
				find_way_1(n,matr,i,y);
			
					
			
	}
	return 0;
}


int find_way(int n, int matr[n][n], int x, int y)
{
	find_way_1(n,matr,x,y);
	//find_way_2(4,matr,x,y);
	/*if(way1!=0&&way2!=0)
	{
		if(way1>way2)
		{
			return way2;
		}
		return way1;
	}
	else 
	{
		if(way1)
		{
			return way1;
		}
		if(way2)
		{
			return way2;
		}
	}*/
	return way1;

}
		




























