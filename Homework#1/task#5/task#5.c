#include <stdio.h>
#include <string.h>
int string_compare(char *,char *);
int main()
{
	printf("\nstring_compare(“asd”, “asc”) -> %d",string_compare("asd", "asc"));
	printf("\nstring_compare(“qwe”, “qwt”) -> %d",string_compare("qwe", "qwt"));
	printf("\nstring_compare(“asd”, “asd”) -> %d\n",string_compare("asd", "asd"));
return 0;
}
int string_compare(char str1[],char str2[])
{
	if(strlen(str1)!=strlen(str2)){printf("\nError!\n");return -2;}
	
	for(int i=0;i<strlen(str1);i++)
	{
		if(str1[i]==str2[i])continue;
		if(str1[i]<str2[i])return -1;
		if(str1[i]>str2[i])return 1;
	}
	return 0;
}

