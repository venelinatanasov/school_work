#include <stdio.h>
#include <string.h>


char S[2][16];



char F(char);
void encrypt(char, char, char*);
void decrypt(char, char, char*);
void init_boxes(char*);
void perform_encryption(char *, char *, char *);
void perform_decryption(char *, char *);


int main(int argc, char * argv[])
{
	char text[64];
	char decrypted[64];
	char encrypted[64];
	char key[50];
	
	strcpy(key,argv[2]);
	
	strcpy(text,argv[1]);
	
	printf("\nOriginal text:%s\n",text);

	perform_encryption(text, key, encrypted);

	printf("\nEncrypted text:%s\n",encrypted);

	perform_decryption(encrypted,decrypted);
	printf("\nDecrypted text:%s\n",decrypted);
	
	 
	return 0;
}

char 
F(char x)
{
	return S[0][x>>6]+S[1][x>>4];
}


void
encrypt(char L, char R, char* out)
{	
	char c;
	for(int i=0;i<16;i++)
	{
		R=R^F(L);
		L=L^F(R);
	}
	c=R;
	R=L;
	L=c;

		
	out[0]=L;
	out[1]=R;
}
void 
decrypt(char L, char R, char* out)
{
	for(int i=0;i<16;i++)
	{
		R=R^F(L);
		L=L^F(R);
	}
	char c=R;
	R=L;
	L=c;	
	out[0]=L;
	out[1]=R;
}
void 
init_boxes(char* key)
{
	int c;
	int z;
	for(int k=0;k<=1;k++)
	{	z=0;	
		while(z<15)
		{	
			c=0;
			while(key[c]!='\0'&&z<15)
			{
				S[k][z]=key[c];
				z++;
				
				c++;
			}
			
		}
		S[k][z]='\0';
		
	}

}
			
			
			
			
		
void 
perform_encryption(char * text, char * key, char * encrypted)
{
	char save[2];
	init_boxes(key);
	int i=0;
	while(i<strlen(text))
	{
		encrypt(text[i], text[i+1],save);
		encrypted[i]=save[0];
		encrypted[i+1]=save[1];
		i+=2;
	}	
	
		encrypted[i]='\0';
	
	
}
void 
perform_decryption(char* encrypted, char* decrypted)
{	int i=0;
	char save[2];
	while(i<strlen(encrypted))
	{
		decrypt(encrypted[i],encrypted[i+1],save);
		decrypted[i]=save[0];
		decrypted[i+1]=save[1];
		i+=2;
	}

		decrypted[i]='\0';
	
}
		
	
			
			
	






















	







	

