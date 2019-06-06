#include <stdio.h>


struct time_t
{
	int hour;
	int minutes;
};

struct datetime_t
{
	int year;
	int month;
	int date;
	struct time_t time;
};




int 
is_before(struct time_t, struct time_t);
int
is_lunch_break(struct time_t);
int season(struct datetime_t);



int main()
{
	/*struct time_t time1;
	printf("\nTime 1 hour: \n");
	scanf("%d",&time1.hour);
	printf("\nTime 1 minutes: \n");
	scanf("%d",&time1.minutes);*/
	struct datetime_t date;
	date.year=2018;
	date.month=2;
	date.date=23;
	date.time.hour=18;
	date.time.minutes=20;
		

	
	/*struct time_t time2;
	printf("\nTime 2 hour: \n");
	scanf("%d",&time2.hour);
	printf("\nTime 2 minutes: \n");
	scanf("%d",&time2.minutes);
		
	
			
	printf("\n%d\n",is_before(time1, time2));*/
	/*if(is_lunch_break(time1))
	{
		printf("\nLunch break!\n");
	}
	else printf("\nWork!!!!\n");*/
	printf("\nSeason: %d\n",season(date));
				
	
	return 0;
}


int 
is_before(struct time_t time1, struct time_t time2)
{
	if(time1.hour<time2.hour)
	{
		return 1;
	}
	if(time1.hour==time2.hour)
	{
		if(time1.minutes<time2.minutes)
		{
			return 1;
		}
	}
	return 0;
}
	

int is_lunch_break(struct time_t time)
{
	if(time.hour==13)
	{
		return 1;
	}
	if(time.hour==12)
	{
		if(time.minutes>=15)
		{
			return 1;
		}
	}
	if(time.hour==14)
	{
		if(time.minutes<=23)
		{
			return 1;
		}
	}
	return 0;
}
		


int season(struct datetime_t date)
{
	if(date.month>3&&date.month<6)
	{
		return 0;
	}
	if(date.month>6&&date.month<9)
	{
		return 1;
	}
	if(date.month>9&&date.month<12)
	{
		return 2;
	}
	if(date.month<3)
	{
		return 3;
	}
	if(date.month==3)
	{
		if(date.date>20)
		{
			return 0;
		}
		if(date.date<20)
		{
			return 3;
		}
		if(date.date==20)
		{
			if(date.time.hour>18)
			{
				return 0;
			}
			if(date.time.hour<18)
			{
				return 3;
			}
			if(date.time.hour==18)
			{
				if(date.time.minutes>=15)
				{
					return 0;
				}
				else return 3;
			}
		}
	}
	if(date.month==6)
	{
		if(date.date<21)
		{
			return 0;
		}
		if(date.date>21)
		{
			return 1;
		}
		if(date.date==21)
		{
			if(date.time.hour<13)
			{
				return 0;
			}
			if(date.time.hour>13)
			{
				return 1;
			}
			if(date.time.hour==13)
			{
				if(date.time.minutes<=7)
				{
					return 0;
				}
				else return 1;
			}
		}
	}
	if(date.month==9)
	{
		if(date.date<23)
		{
			return 1;
		}
		if(date.date>23)
		{
			return 2;
		}	
		if(date.date==23)
		{
			if(date.time.hour<4)
			{
				return 1;
			}
			if(date.time.hour>4)
			{
				return 2;
			}
			if(date.time.hour==4)
			{
				if(date.time.minutes<54)
				{
					return 1;
				}
				else return 2;
			}
		}
	}
	if(date.month==12)
	{
		if(date.date<22)
		{
			return 2;
		}
		if(date.date>22)
		{
			return 3;
		}
		if(date.date==22)
		{
			if(date.time.hour>0)
			{
				return 3;
			}
			if(date.time.hour==0)
			{
				if(date.time.minutes<22)
				{
					return 2;				
				}
				else return 3;
			}
		}
	}
	return -1;
}























































