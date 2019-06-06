#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct card_t
{
	int category;
	int type;
};

struct player_t
{
	char name[50];
	int wins;
	int loses;
	struct card_t cards[26];
};


int fight(struct card_t, struct card_t);
struct player_t generate_deck(struct player_t);
void fight_p(struct player_t, struct player_t);
int main()
{	
	srand(time(NULL));
	/*struct card_t card1;
	card1.category=3;
	card1.type=0;
	struct card_t card2;
	card2.category=2;
	card2.type=0;

	struct card_t card_win;
	card_win=fight(card1, card2);
	printf("\n%d %d\n",card_win.category, card_win.type);*/



	struct player_t player1;
	printf("\nInput name of player 1: ");
	fgets(player1.name, 50, stdin);
	player1.wins=0;
	player1.loses=0;
	player1=generate_deck(player1);	

	struct player_t player2;
	printf("\nInput name of player 2: ");
	fgets(player2.name, 50, stdin);
	player2.wins=0;
	player2.loses=0;
	player2=generate_deck(player2);

	fight_p(player1, player2);
	
	





return 0;
}


int
fight(struct card_t card1, struct card_t card2)
{
	if(card1.type==card2.type)
	{
		if(card1.category<=card2.category)
		{
			return 1;
		}
		else return 0;
	}
	if(card1.type>card2.type)
	{
		return 0;
	}
	return 1;
}


struct player_t
generate_deck(struct player_t player)
{
	for(int i=0;i<26;i++)
	{
		
		
		player.cards[i].category=rand()%4;
		player.cards[i].type=rand()%13;
	}
	return player;
}


void fight_p(struct player_t player1, struct player_t player2)
{int p1=0;int p2=0;
	for(int i=0;i<26;i++)
	{
		if(fight(player1.cards[i],player2.cards[i]))
		{
			p2++;
		}
		else p1++;
	}
	if(p2>p1)
	{
		printf("\nPlayer 2 wins\n");
	}
	if(p2<p1)
	{
		printf("\nPlayer 1 wins!\n");
	}
	if(p2==p1)
	{
		printf("\nTie\n");
	}
}
	
		
	






























	

	
