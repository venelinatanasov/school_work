#include <stdio.h>


int is_magical_number(int num)
{

	int prod=1;
	int n=num;
	while(n>0)
	{
		prod*=n%10;
		n/=10;
	}
	if(!(num%prod))
	{
		return 1;
	}
	return 0;
}

void process()
{
	int n;int num;
	printf("\nHow many numbers will you input?\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&num);
		
		if(is_magical_number(num))
		{
			printf("\nMagical\n");
		}
		else
		{
			printf("\nNot magical\n");
		}
		getchar();
	}
}
			
		
		




int main()
{
	process();

	return 0;
}
