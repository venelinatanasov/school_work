#include <stdio.h>
#include <string.h>
char num[1000000000];
void make_bits(int);
void print_bits(int);
void print_bits(int);
int count_ones(int);






int main()
{
	print_bits(-1);
	
	return 0;
}















void print_bits(int n)
{
	make_bits(n);
	putchar('\n');
	for(int i=strlen(num)-1;i>=0;i--)
	{
		printf("%c",num[i]);
	}
	
	printf("(%d)",count_ones(n));
	putchar('\n');
}

void make_bits(int n)
{	
	
	char cp[100];
	strcpy(num,cp);
	int k;
		
	
	if(n==0)
	{	
		for(int i=0;i<8;i++)
		{
			num[i]='0';
		}
	}
	for(int i=0;n>0;i++)
	{
		k=n>>1;
		if(2*k!=n)
		{
			num[i]='1';
		}
		else num[i]='0';
		n=n>>1;
	}

	
	if(strlen(num)<16)
	{
		int i=strlen(num);
		while(i<16)
		{
			num[i]='0';
			i++;
		}
	}

}

int count_ones(int n)
{	
	make_bits(n);
	n=0;
	for(int i=0;i<strlen(num);i++)
	{
		if(num[i]=='1')
		{
			n++;
		}
	}
	return n;
}
	
	
