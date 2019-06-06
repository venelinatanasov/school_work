#include <stdio.h>
#include <stdlib.h>
//Venelin Atanasov 10g N8



int is_prime(int);
int sum_of_digits(int);
void find_prime_dig_sum();


int main()
{
//	for(int i=0;i<10000;i++)
//	{


//	printf("\n%d\n",is_prime(1));
	
//	printf("\n%d\n",is_prime(2));		

//	printf("\n%d\n",sum_of_digits(737345));
	find_prime_dig_sum();
	return 0;
}


void find_prime_dig_sum()
{
	for(int i=1;i<10000;i++)
	{
		if(is_prime(sum_of_digits(i)))
		{
			printf("\n%d",i);
		}
	}
	putchar('\n');
}









int is_prime(int i)
{
	if(i==1)
	{
		return 0;
	}
	for(int x=2;x<i;x++)
	{
		if(i%x)
		{
			continue;
		}
		else
		{
			return 0;
		}
	}
	return 1;
}

int sum_of_digits(int num)
{
	int sum=0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
		
























