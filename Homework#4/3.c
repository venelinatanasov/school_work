#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//Venelin Atanasov 10g N8

struct packet_t
{
	char content[256];
	char source[50];
	char destination[50];
};


void input_packet(struct packet_t *);
void print_pack(struct packet_t);
void input_buff(struct packet_t *);
void print_buff(struct packet_t *);
void sort_buff(struct packet_t *);
void empty(struct packet_t *);
void exec();


int main()
{
	exec();	
	
	
	
	return 0;
}
void exec()
{
	struct packet_t buff[10];
	input_buff(buff);
	printf("sending out packets....\n");
	sort_buff(buff);
	print_buff(buff);
	empty(buff);

}






void input_packet(struct packet_t *pack)
{
	scanf("%s",pack->source);
	scanf("%s",pack->destination);
	getchar();
	fgets(pack->content,255,stdin);
}


void print_pack(struct packet_t pack)
{
	printf("From: %s ",pack.source);
	printf("To: %s ",pack.destination);
	printf("Content: %s\n",pack.content);
}

void input_buff(struct packet_t *buff)
{
	for(int i=0;i<10;i++)
	{
		input_packet(&buff[i]);
	}
}

void print_buff(struct packet_t *buff)
{
	for(int i=0;i<10;i++)
	{
		print_pack(buff[i]);
	}
}

void sort_buff(struct packet_t *buff)
{
	struct packet_t pack;
	for(int i=0;i<9;i++)
	{
		for(int z=0;z<9;z++)
		{
			if(strlen(buff[z].content)>strlen(buff[z+1].content))
			{
				pack=buff[z];
				buff[z]=buff[z+1];
				buff[z+1]=pack;
			}
		}
	}
}
				
void empty(struct packet_t *buff)
{
	struct packet_t empty;
	for(int i=0;i<10;i++)
	{
		buff[i]=empty;
	}
	
}






























