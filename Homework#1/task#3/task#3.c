#include <stdio.h>
#include <string.h>

int is_fingerprint_row_valid(char *);

int main(int argc, char *argv[])
	
{
	printf("\n%s\n",argv[0]);
	printf("\n%s\n",argv[1]);
	
	printf("\n\n\n%ld\n\n\n",strlen(argv[1]));
	int i=1;
	while(i<argc)
	{
		if(is_fingerprint_row_valid(argv[i]))
		{
			printf("Row %d is valid.\n",i);
		}
		else printf("Row %d is invalid!\n",i);
		i++;
	} 
	
	return 0;
}
int is_fingerprint_row_valid(char fingerprint[16])
{	
	int i=0,k;
	char valid_chars[16];
	strcpy(valid_chars,"\\_/~|-");
	
	printf("\n\n\n%ld\n\n\n",strlen(fingerprint));
	if(strlen(fingerprint)!=16){return 0;}
	while(i<16)
	{	
		k=0;
		while(k<6)
		{
			if(fingerprint[i]!=valid_chars[k])
			{
				k++;
				if(k==6){return 0;}
			}
			else break;
		}
		i++;
	}
	return 1;
}
		
				
				
		
	

