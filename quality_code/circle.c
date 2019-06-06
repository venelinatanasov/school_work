#include <stdio.h>
#define pi 3.14159265
#include <math.h>
#include <stdlib.h>
struct point_t
{
	float x;
	float y;
};

struct circle_t
{
	float rad;
	struct point_t center;
};
float perimeter(float);

float area(float);

void in_quad(struct circle_t);
int point_in_quad(struct point_t);
int in(int *,int);
int main()
{
	struct circle_t circle;
	circle.rad=6;
	circle.center.x=-6;
	circle.center.y=6;
	in_quad(circle);
	return 0;
}




float 
perimeter(float rad)
{
	return 2*pi*rad;
}

float 
area(float rad)
{
	return pi*rad*rad;
}
void in_quad(struct circle_t circle)
{	
	int quad;
	if(circle.center.x>0)
	{
		if(circle.center.y>0)
		{
			quad= 1;
		}
		if(circle.center.y<0)
		{
			quad=4;
		}
	}
	if(circle.center.x<0)
	{
		if(circle.center.y>0)
		{
			quad=2;
		}
		if(circle.center.y<0)
		{
			quad=3;
		}		
	}
	while(1)
	{
		if(hypot(abs(circle.center.x),abs(circle.center.y))-circle.rad<0)
		{	
			printf("\nALL\n");
			break;
		}
		if(abs(circle.center.x)-circle.rad<=0||abs(circle.center.y)-circle.rad<=0)
		{
			printf("\n%d\n",quad);
			if(abs(circle.center.x)-circle.rad<0)			
			{
				if(quad==1)
				{
					printf("\n2\n");
				}
				if(quad==2)
				{
					printf("\n1\n");
				}
				if(quad==3)
				{
					printf("\n4\n");
				}
				if(quad==4)
				{
					printf("\n3\n");
				}
			}
			if(abs(circle.center.y)-circle.rad<0)
			{
				if(quad==1)
				{
					printf("\n4\n");
				}
				if(quad==2)
				{
					printf("\n3\n");
				}
				if(quad==3)
				{
					printf("\n2\n");
				}
				if(quad==4)
				{
					printf("\n1\n");
				}
			}
			break;
		}
		else 
		{
			printf("\n%d\n",quad);
			break;
		}
	}
}
					











			
















	
	



















	
