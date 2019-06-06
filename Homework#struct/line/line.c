#include <stdio.h>
#include <math.h>
#include <stdlib.h>




struct point_t
{
	float x;
	float y;
};



struct line_t
{
	struct point_t point1;
	struct point_t point2;
};
float slope(struct line_t);
int are_parallel(struct line_t, struct line_t);
int do_they_intersect(struct line_t, struct line_t);



int main()
{
	struct line_t line1;

	
	printf("\nLine 1 point 1 x: ");
	scanf("%f",&line1.point1.x);
	printf("\nLine 1 point 1 y: ");
	scanf("%f",&line1.point1.y);
	printf("\nLine 1 point 2 x: ");
	scanf("%f",&line1.point2.x);
	printf("\nLine 1 point 2 y: ");
	scanf("%f",&line1.point2.y);
	

	struct line_t line2;


	printf("\nLine 2 point 1 x: ");
	scanf("%f",&line2.point1.x);
	printf("\nLine 2 point 1 y: ");
	scanf("%f",&line2.point1.y);
	printf("\nLine 2 point 2 x: ");
	scanf("%f",&line2.point2.x);
	printf("\nLine 2 point 2 y: ");
	scanf("%f",&line2.point2.y);


	if(are_parallel(line1, line2))
	{
		printf("\nParallel!\n");
	}
	else printf("\nNot parallel!\n");
	
	if(do_they_intersect(line1, line2))
	{
		printf("\nThey intersect!\n");
	}
	else printf("\nThey do not intersect!\n");



	return 0;
}




float slope(struct line_t line)
{
	
	float y=abs(line.point1.y-line.point2.y);
	float x=abs(line.point1.x-line.point2.x);
	float m=y/x;
	if(!((line.point1.x>line.point2.x&&line.point1.y>line.point2.y)||(line.point1.x<line.point2.x&&line.point1.y<line.point2.y)))
	{
		m*=-1;
	}
	return m;
	
	
}


int are_parallel(struct line_t line1, struct line_t line2)
{
	if(slope(line1)==slope(line2))
	{
		return 1;
	}
	else return 0;
}


int do_they_intersect(struct line_t line1, struct line_t line2)
{
	if(!are_parallel(line1, line2))
	{
		return 1;
	}
	else return 0;
}



























