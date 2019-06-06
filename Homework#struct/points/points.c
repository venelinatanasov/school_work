#include <stdio.h>


struct point_t
{
	float x;
	float y;
};




int are_on_one_line(struct point_t, struct point_t, struct point_t);
struct point_t sum_of_points(struct point_t, struct point_t);
int main()
{
	struct point_t a;
	a.x=-7;
	a.y=-2;
	struct point_t b;
	b.x=-1;
	b.y=-1;
	struct point_t c;
	c.x=-7;
	c.y=-2;

	printf("\n%d\n",are_on_one_line(a,b,c));


	c=sum_of_points(a,b);
	printf("\n%f\n",c.x);
	printf("\n%f\n",c.y);
	
	
	return 0;
}

int
are_on_one_line(struct point_t a, struct point_t b, struct point_t c)
{
	
	return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y)==0;
}




struct point_t 
sum_of_points(struct point_t a,struct point_t b)
{
	float x,y;
	if(a.x>=b.x)
	{
		x=a.x-b.x;
	}
	else x=b.x-a.x;
	if(a.y>=b.y)
	{
		y=a.y-b.y;
	}
	else y=b.y-a.y;
	
	struct point_t c;
	c.x=x;
	c.y=y;
	return c;
}




















