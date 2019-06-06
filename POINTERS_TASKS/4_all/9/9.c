#include <stdio.h>


struct card_t
{
	int number;
	float availability;
};

struct human_t 
{
	char name[200];
	struct card_t card;
};




int pay_with(struct human_t *, float);
void print_card(struct card_t card);
int main()
{
	
	struct human_t human;
	human.card.number=12345;
	human.card.availability=59;	
	
	if(pay_with(&human,20.0))
	{
		print_card(human.card);
	}




	return 0;
}


int pay_with(struct human_t *human, float pay)
{
	if(human->card.availability>=pay)
	{
		human->card.availability-=pay;
		return 1;
	}
	return 0;
}

void print_card(struct card_t card)
{
	printf("\nCard number: %d",card.number);
	printf("\nAvailability: %f\n",card.availability);
}
