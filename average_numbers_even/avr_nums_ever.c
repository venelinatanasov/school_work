#include <stdio.h>
#include <stdlib.h>


float avr(int);

int main(int argc, char* argv[])
{
	
	for(int i=1;i<argc;i++)
	{
		printf("\n%f\n",avr(atoi(argv[i])));
	}
	
	return 0;
}

float avr(int num)
{	float avr=0;
	int i=0;
	while(num>0)
	{
		if((num%10)%2!=0)
		{
			avr+=num%10;
			i++;
		}
		num/=10;
	}
	avr=avr/i;
	return avr;
}
