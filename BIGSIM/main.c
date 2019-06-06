#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "struct.h"
#define  size_of_terrain 6
TERRAIN terrain[size_of_terrain][size_of_terrain];





#include "func.h"

//TERRAIN terrain[size_of_terrain][size_of_terrain];

int main()
{
	
	srand(time(0));
	
	generate_terrain();
	print_whole_terrain();
	print_everyone();
	getchar();
	while(1)
	{
		
		
		//getchar();
		
		random_move();
		print_whole_terrain();
		print_everyone();
		getchar();
		//year_cycle();
		//print_everyone();

		
	}
	
	
	return 0;
}
