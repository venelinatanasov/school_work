#include <stdio.h>
int my_len(char *);
void concatenation(char *,char *);
int main()
{
	char str1[33],str2[33];
	printf("\nstring 1:\n");
	fgets(str1,32,stdin);
	printf("\nstring 2:\n");
	fgets(str2,32,stdin);
	if((my_len(str1)+my_len(str2))>32){printf("\nError\n");return 0;}
	concatenation(str1,str2);
	printf("%s",str1);
	
}
void concatenation(char str1[],char str2[])
{
	int i=0,k=0;
	
	i=my_len(str1);
	while(k!=my_len(str2))
	{
		str1[i]=str2[k];
		k++;
		i++;
	}
}
	
int my_len(char str[])
{	
	int i=0;
	while(str[i]!='\0')
	{
		i++;
	}
	i--;
	return i;
}
		

	

	
	
