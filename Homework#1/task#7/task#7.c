#include <stdio.h>
#include <string.h>
char morse[36][10];




void arg_to_morse(char *);
int main(int argc,char *argv[])
{
	
	strcpy(morse[0],"o -");
	strcpy(morse[1],"- o o o");
	strcpy(morse[2],"- o - o");
	strcpy(morse[3],"- o o");
	strcpy(morse[4],"o");
	strcpy(morse[5],"o o - o");
	strcpy(morse[6],"- - o");
	strcpy(morse[7],"o o o o");
	strcpy(morse[8],"o o");
	strcpy(morse[9],"o - - -");
	strcpy(morse[10],"- o -");
	strcpy(morse[11],"o - o o");
	strcpy(morse[12],"- -");
	strcpy(morse[13],"- o");
	strcpy(morse[14],"- - -");
	strcpy(morse[15],"o - - o");
	strcpy(morse[16],"- - o -");
	strcpy(morse[17],"o - o");
	strcpy(morse[18],"o o o");
	strcpy(morse[19],"-");
	strcpy(morse[20],"o o -");
	strcpy(morse[21],"o o o -");
	strcpy(morse[22],"o - -");
	strcpy(morse[23],"- o o -");
	strcpy(morse[24],"- o - -");
	strcpy(morse[25],"- - o o");
	strcpy(morse[26],"- - - - -");
	strcpy(morse[27],"o - - - -");
	strcpy(morse[28],"o o - - -");
	strcpy(morse[29],"o o o - -");
	strcpy(morse[30],"o o o o -");
	strcpy(morse[31],"o o o o o");
	strcpy(morse[32],"- o o o o");
	strcpy(morse[33],"- - o o o");
	strcpy(morse[34],"- - - o o");
	strcpy(morse[35],"- - - - o");
	
	
	printf("\n");
	for(int i=1;i<argc;i++)
	{
		arg_to_morse(argv[i]);
		printf("       ");
		
	}
	printf("\n");





	return 0;
}


void arg_to_morse(char str[])
{
	for(int i=0;i<strlen(str);i++)
	{
		if(str[i]>='a'&&str[i]<='z')
		{
			printf("%s",morse[str[i]-'a']);
		}
		if(str[i]>='A'&&str[i]<='Z')
		{
			printf("%s",morse['A'-str[i]]);
		}
		if(str[i]>='0'&&str[i]<='9')
		{
			printf("%s",morse[26+(str[i]-'0')]);
		}
		if(i!=strlen(str)-1)printf("   ");
	}
}	






































