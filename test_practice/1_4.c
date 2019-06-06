#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int compare_strings(char first[32], char second[32], int ignore_case)
{	int i;
	int shorter;int sh;
	if(strlen(first)<strlen(second))
	{
		shorter=strlen(first);
		sh=1;
	}
	if(strlen(first)==strlen(second))
	{
		sh=0;
		shorter=strlen(first);
	}
	if(strlen(second)<strlen(first))
	{
		shorter=strlen(second);
		sh=2;
	}
	printf("\n%d  %d\n",sh,shorter);

	if(ignore_case)
	{
		for(i=0;i<shorter;i++)
		{
			if(first[i]<='Z'&&first[i]>='A')
			{
				first[i]=first[i]+'a'-'A';
			}
			if(second[i]<='Z'&&second[i]>='A')
			{
				second[i]=second[i]+'a'-'A';
			}
		}
	}
	printf("\n%s   %s\n",first,second);
	for(i=0;i<shorter;i++)
	{
		if(first[i]==second[i])
		{
			continue;
		}
		if(first[i]>second[i])
		{
			return -1;
		}
		else return 1;
	}
	if(!sh)
	{
		return 0;
	}
	if(sh==1)
	{
		return -1;
	}
	return 1;
}
					



int main()
{
	printf("\n%d\n",compare_strings("asd","Asd",1));
	printf("\n%d\n",compare_strings("asd","Asd",0));
	printf("\n%d\n",compare_strings("asdf","asd",0));
	printf("\n%d\n",compare_strings("asd","qwe",0));

	return 0;
}














