#include <stdio.h>
int is_digit(char digit);
int to_digit(char digit);
int contains(unsigned long number,char digit);
int main()
{
	printf("\nWrong value for is_digit: 'Z'\n%d\n",is_digit('Z'));	
	printf("\nRight value for is_digit: '4'\n%d\n",is_digit('4'));
	printf("\nWrong value for to_digit: 'Z'\n%d\n",to_digit('Z'));
	printf("\nRight value for to_digit: '4'\n%d\n",to_digit('4'));
	printf("\nWrong value for contains: number=123, digit='Q'\n%d\n",contains(123,'Q'));
	printf("\nRight value for contains: number=123, digit='3'\n%d\n",contains(123,'3'));
		
	return 0;
}
int is_digit(char digit)
{
	if(digit>='0'&&digit<='9')
	{
		return 1;
	}
	return 0;
}
int to_digit(char digit)
{
	if(!is_digit(digit)){return -1;}
	return -1*('0'-digit);
}
int contains(unsigned long number,char digit)
{
	if(!is_digit(digit)){return 0;}
	while(number!=0)
	{
		if(to_digit(digit)==number%10)
		{
			return 1;
		}
		number=number/10;
	}
	return -1;
}


	
