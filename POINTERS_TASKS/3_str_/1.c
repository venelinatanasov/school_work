#include <stdio.h>






struct human_t
{
	int is_married;
	float salary;
};
void raise_salary(struct human_t*);
void print_human(struct human_t);


int main()
{
	struct human_t human;
	human.is_married=0;
	human.salary=1000;
	raise_salary(&human);
	print_human(human);
	
	
	human.is_married=1;
	human.salary=1000;
	raise_salary(&human);
	print_human(human);
	






	return 0;
}

void raise_salary(struct human_t *human)
{
	if(!human->is_married)
	{
		human->salary+=0.5*human->salary;
	}
	else
	{
		human->salary+=0.25*human->salary;
	}
}

void print_human(struct human_t human)
{
	printf("\n%d\n%f\n",human.is_married,human.salary);
}



















