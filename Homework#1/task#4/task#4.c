#include <stdio.h>
#include <string.h>
int is_valid_mac(char *);
int is_valid_char(char);

int main(int argc,char *argv[])
{	
	int i=1;
	/*printf("\n%d\n",is_valid_char('a'));
	printf("\n%d\n",is_valid_char('3'));
	printf("\n%d\n",is_valid_char('z'));*/	
	while(i<argc)
	{
		if(is_valid_mac(argv[i]))
		{
			printf("\nMAC adress %d is valid\n",i);
		}
		else printf("\nMAC adress %d is invalid\n",i);
		i++;
	}


}
int is_valid_mac(char charmac[20])
{	
	int i=0,k;
	if(strlen(charmac)!=17)
	{
		return 0;
	}
	while(i<17)
	{
		k=0;
		while(k<3)
		{	k++;
			if(k==1)
			{
				if(is_valid_char(charmac[i]))
				{
					continue;
				}
				else return 0;
			}
			if(k==2)
			{
				if(is_valid_char(charmac[i+1]))
				{
					continue;
				}
				else return 0;
			}
			if(k==3)
			{
				if(charmac[i+2]==':'||charmac[i+2]=='\0')
				{
					break;
				}
				else return 0;
			}
			
		}
		i=i+3;
	}
	return 1;
}
			
		
		
	
int is_valid_char(char c)
{
	int i=0;		
	char valid[17];
	strcpy(valid,"0123456789abcdef");
	
	while(i<18)
	{
		
		if(valid[i]==c)
		{
			return 1;
		}
		i++;
	}
	return 0;
}
	
