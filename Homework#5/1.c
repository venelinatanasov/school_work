#include <stdio.h>
#include <stdlib.h>





int is_valid(char);
int count_longest(char *);
void input();





int main()
{

	char str[200];
	input(str);
	//printf("%s",str);
	printf("\nNumber of longest VALID words: %d\n",count_longest(str));
	


	return 0;
}

void input(char *str)
{
	fgets(str,200,stdin);
}
	



int count_longest(char str[200])
{
	int i=0;int pi=-1;int z=0,pz=0,c=0;
	while(1)
	{

		if(!is_valid(str[i]))
		{

			if(str[i]==' '||str[i]=='\0')
			{
				
				z=i-pi-1;
				pi=i;
				if(str[i]=='\0'){z--;}
				if(z>pz)
				{
					c=1;
					pz=z;
				}
				else
				{
					if(z==pz)
					{
						c++;//printf("c++");
					}
				}				
				if(str[i]=='\0')
				{
					
					return c;
				}
			}
			else
			{
				if(str[i]=='\n'){i++;continue;}
				//printf("\n\nWRIN\n\n");printf("\nwr %c\n",str[i]);
				while(str[i]!=' '&&str[i]!='\0')
				{
					i++;
				}
				pi=i;
				
			}

			
		}
						
			
		i++;

	}
	
}

			
										



int is_valid(char letter)
{


	
		if(((letter>='a'&&letter<='z')||(letter>='A'&&letter<='Z'))||letter=='\''||letter=='-')
		{
			return 1;
		}
	
		
	return 0;
}








