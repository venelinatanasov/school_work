#include <stdio.h>
#include <string.h>
int to_integer(char *);



int main(int argc,char *argv[])
{
	int i=1;
	int sum=0;
	while(i<argc)
	{
		sum=sum+to_integer(argv[i]);
		i++;
	}
	printf("\n%d\n",sum);
		
	return 0;
}

int to_integer(char str[])
{
	int num=0;
	for(int i=0;i<strlen(str);i++)
	{
		if(i==0){num=str[i]-'0';continue;};
		num=num*10;
		num+=str[i]-'0';
	}
	
		
	return num;



}
