#include <stdio.h>
int sum();
int asquared();
int iseven();
int mult();
int expon();
int fibonacci();
int main()
{
	printf("\n%d\n",sum(10,3));
	printf("\n%d\n",mult(10,33));
	printf("\n%d\n",expon(9,3));
	printf("\n%d\n",iseven(8));
	printf("\n%d\n",fibonacci(13));
	printf("\n%d\n",asquared(12));
	return 0;
}

int sum(int a,int b)
{
	return a+b;
}
int mult(int a,int b)
{
	int k=0;
	while(b>0)
	{	
		k=sum(k,a);
		b--;			
	}
	return k;
}
int expon(int a,int b)
{
	int k=a;
	while(b>1)
	{
		k=mult(k,a);
		b--;
	}
	return k;
}
int iseven(int a)
{
	return a%2==0;
}
int fibonacci(int n)
{
	if(n==0)
	{
		return 0;
	}
	if(n==1)
	{
		return 1;
	}
	return fibonacci(n-1)+fibonacci(n-2);
}
int asquared(int a)
{
	return a*a;
}



















