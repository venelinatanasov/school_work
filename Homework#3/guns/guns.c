#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>



struct guns_t
{
	char model[128];
	int accuracy;
	int ammo_capacity;
};




int get_score(int, int);
void test_gun(struct guns_t, int);




int 
main()
{
	srand(time(NULL));
	

	
	struct guns_t ak_47;
	strcpy(ak_47.model,"AK-47");
	ak_47.accuracy=40;
	ak_47.ammo_capacity=30;


	test_gun(ak_47,50);
	
	
	return 0;
	
}



int 
get_score(int gun_accuracy, int shot_accuracy)
{
	
	if(shot_accuracy>=0&&shot_accuracy<=gun_accuracy)
	{
		return 10;
	}
	int i=0;
	double shot=shot_accuracy;
	double acc=gun_accuracy;
	double step=(100.0-acc)/10;
	
	double k=100;
	while(1)
	{	
				
		if(shot>k)
		{
			return i-1;
		}
		
		i++;
		k=k-step;
		
	}
	return -1;
}



void 
test_gun(struct guns_t gun, int shot_count)
{	
	int shot_accuracy;
	int score;
	float scoreall=0;
	
	for(int i=0;i<shot_count;i++)
	{


		do
		{
			shot_accuracy=rand()%101;
		}while(shot_accuracy==0);
		score=get_score(gun.accuracy, shot_accuracy);
		scoreall+=score;
		printf("\nAccuracy: %d  Score: %d\n",shot_accuracy, score);
	}
	
	printf("\nTotal score: %f  Average score: %f\n", scoreall, scoreall/shot_count);
}
			

















