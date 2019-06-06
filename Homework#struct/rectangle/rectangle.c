#include <stdio.h>
#include <stdlib.h>


struct rect_t
{
	int left;
	int top;
	int bot;
	int right;
};


int contains(struct rect_t, struct rect_t);
void print_rect(struct rect_t);
struct rect_t union2(struct rect_t, struct rect_t);
struct rect_t offset_to(struct rect_t, int, int);


int main()
{
	struct rect_t rect1;
	rect1.left=0;
	rect1.right=6;
	rect1.bot=0;
	rect1.top=6;
	
	struct rect_t rect2;
	rect2.left=-20;
	rect2.right=6;
	rect2.top=5;
	rect2.bot=1;
	

	struct rect_t rect3;
	

	rect1=offset_to(rect1, 10,7);
	print_rect(rect1);
	//rect3=union2(rect1,rect2);
	//print_rect(rect3);
	//printf("\n%d\n",contains(rect1, rect2)); 	


	return 0;
}

int contains(struct rect_t rect, struct rect_t rect2)
{
													
	if(rect2.left>=rect.left&&rect2.right<=rect.right&&rect2.top<=rect.top&&rect2.bot>=rect.bot)
	{
		return 1;
	}
	return 0;
}

struct rect_t union2(struct rect_t rect1, struct rect_t rect2)
{
	struct rect_t retrect;
	retrect.left=rect1.left+rect2.left;
	retrect.right=rect1.right+rect2.right;
	retrect.top=rect1.top+rect2.top;
	retrect.bot=rect1.bot+rect2.bot;
	return retrect;
}	



void 
print_rect(struct rect_t rect)
{
	printf("\nTop: %d, Left: %d, Right: %d, Bot: %d\n",rect.top,rect.left,rect.right,rect.bot);
}
	


struct rect_t
offset_to(struct rect_t rect, int new_left, int new_top)
{

	rect.bot=rect.bot+(new_top-rect.top);
	rect.right=rect.right+(new_left-rect.left);
	rect.left=new_left;
	rect.top=new_top;
	return rect;	
}











































