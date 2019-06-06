#include <stdio.h>
#include <string.h>

//declarations
void input_URI();
void divide_URI();
int check_URI();
void print_path_parts(char *);


//global
char URI[2000];

typedef struct URI_parts {
	char scheme[2000];
	char userinfo[2000];
	char host[2000];
	char port[2000];
	char path[2000];
	char query[2000];
	char fragment[2000];
}uriparts;

uriparts parts;







//main
int main()
{
	input_URI();	
	divide_URI();
	if(check_URI()){printf("\nValid URI\n");}else printf("\nInvalid URI\n");
	printf("\nScheme: %s\n",parts.scheme);
	printf("\nUserinfo: %s\n",parts.userinfo);
	printf("\nHost: %s\n",parts.host);
	printf("\nPort: %s\n",parts.port);
	printf("\nPath: %s\n",parts.path);
	printf("\nQuery: %s\n",parts.query);
	printf("\nFragment: %s\n",parts.fragment);
	parts.path[strlen(parts.path)]='\0';
	
	print_path_parts(parts.path);
	return 0;
}








//functions

void input_URI()
{
	fgets(URI,2000,stdin);
}

void divide_URI()
{
	
	int i=0,k=0,z=0,c,c1=0;
	while(URI[i]!=':')
	{//get the scheme
		parts.scheme[i]=URI[i];
		i++;
	}
	parts.scheme[i]='\0';
	if(URI[i+1]=='/'&&URI[i+2]=='/')
	{	
		i=i+2;		
		k=i+1;
		
		while(1)
		{
			if(URI[k]=='/')
			{
				break;
			}	
			
			if(URI[k]=='@')
			{//get userinfo
				c=0;
				i++;
				while(URI[i]!='@')
				{
					parts.userinfo[c]=URI[i];
					c++;
					i++;
				}
				
				parts.userinfo[c]='\0';
			}
			c=0;
			
			if(URI[k]==':')
			{//get the port
				z=k+1,c=0;
				while(URI[z]!='/')
				{
					parts.port[c]=URI[z];
					c++;
					z++;
				}
				c1=c+1;
				parts.port[c]='\0';
				
								
			}
			k++;
		}
	
		z=0;
		i++;
		while(URI[i]!=':'&&URI[i]!='/')
		{//get host
			parts.host[z]=URI[i];
			z++;
			i++;
		}
		i=i+c1;
	}

	c=0;
	
	while(URI[i]!='\0'&&URI[i]!='?'&&URI[i]!='#')
	{//get path
		parts.path[c]=URI[i];
		c++;
		i++;
	}
	c=0;
	if(URI[i]=='?')
	{//get query
		i++;
		while(URI[i]!='\0'&&URI[i]!='#')
		{
			parts.query[c]=URI[i];
			c++;
			i++;
		}
		parts.query[c]='\0';
	}
	c=0;
	if(URI[i]=='#')
	{//get fragment
		i++;
		while(URI[i]!='\0')
		{
			parts.fragment[c]=URI[i];
			i++;
			c++;
		}
		parts.fragment[c]='\0';
	}
}


int check_URI()
{
	if(strlen(parts.scheme)==0||strlen(parts.path)==0)
	{
		return 0;
	}
	if((strlen(parts.userinfo)>0||strlen(parts.port)>0)&&strlen(parts.host)==0)
	{
		return 0;
	}
	if(!(URI[0]>='a'&&URI[0]<='z')&&!(URI[0]>='A'&&URI[0]<='Z')){return 0;}
	return 1;
	
}
	
void print_path_parts(char path[])
{	path[strlen(path)]='\0';
	char part[50];
	int i=0,c,p=1;
	while(path[i]!='\0')
	{	c=0;i++;
		
		while(path[i]!='/')
		{
			part[c]=path[i];
			i++;
			c++;
		}
		
		part[c]='\0';
		if(i>=strlen(path)){break;};
		printf("\nPart %d of path.: %s\n",p,part);
		
		p++;
		
		
		
		
	}
}
			
			
		
	


		
		
		
		
		
		







































