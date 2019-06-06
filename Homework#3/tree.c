
//Venelin Atanasov 10g n8


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//structures
struct tree_t
{
	float height;
	int age;
};


struct forest_t
{
	int tree_count;
	struct tree_t trees[1000];
};




//definitions
float my_rand();
struct forest_t age_trees(struct forest_t);
void print_tree(struct tree_t);
void print_forest(struct forest_t);
struct forest_t generate_forest(struct forest_t);
struct tree_t generate_tree(struct tree_t);
struct forest_t cut_old_trees(struct forest_t, int);
struct forest_t cut_tall_trees(struct forest_t,int);
//life of a forest
void the_forest(int, int, float);






//MAIN
int main(int argc, char* argv[])
{
	srand(time(NULL));
	if(argc>4)
	{
		printf("\nToo many arguments!\n");
		return 0;
	}
	int cycles=atoi(argv[1]);
	int age_treshold=atoi(argv[2]);
	float height_treshold=atof(argv[3]);

		
		
	the_forest(cycles, age_treshold, height_treshold);
		
	
	
	
	/*tree1
	struct forest_t forest;
	forest.tree_count=1;
	forest.trees[0].height=10;
	forest.trees[0].age=8;
	forest=generate_forest(forest);
	print_forest(forest);
	
	printf("\n\n\n\n");
	forest=cut_high_trees(forest,25);
	print_forest(forest);






	forest=age_trees(forest);
	

	printf("\n%f\n",forest.trees[0].height);
	printf("\n%d\n",forest.trees[0].age);
	printf("\n%f\n",(float)rand()/RAND_MAX);
	print_tree(forest.trees[0]);
	print_forest(forest);*/
	

	return 0;
}



float 
my_rand()
{
	int r;
	do
	{
		r=rand()%2000001;
	}while(r<100000);
	float r1=(float)r/1000000;
	return r1;
}

struct forest_t 
age_trees(struct forest_t forest)
{
	for(int i=0;i<forest.tree_count;i++)
	{
		forest.trees[i].age++;
		forest.trees[i].height+=my_rand();
	}
	return forest;
}

void
print_tree(struct tree_t tree)
{
	printf("\nAge: %d  Height: %f\n",tree.age, tree.height);
}
void
print_forest(struct forest_t forest)
{
	printf("\nForest tree count: %d\n",forest.tree_count);
	for(int i=0;i<forest.tree_count;i++)
	{
		printf("\nTree %d\n",i+1);
		print_tree(forest.trees[i]);
	}
}


struct forest_t 
generate_forest(struct forest_t forest)
{	
	do
	{
		forest.tree_count=rand()%31;
	}while(forest.tree_count==0);
	for(int i=0;i<forest.tree_count;i++)
	{
		forest.trees[i]=generate_tree(forest.trees[i]);
	}
	return forest;
}





struct tree_t 
generate_tree(struct tree_t tree)
{
	
	int i;
	i=rand()%500001;
	tree.height=(float)i/10000;
	tree.age=rand()%101;
	return tree;
}



struct forest_t 
cut_old_trees(struct forest_t forest, int age_treshold)
{
	for(int i=0;i<forest.tree_count;i++)
	{
		if(forest.trees[i].age>age_treshold)
		{
			forest.trees[i].age=1;
			forest.trees[i].height=0.5;
		}
	}
	return forest;
}
		
	


struct forest_t 
cut_tall_trees(struct forest_t forest,int height_treshold)
{
	for(int i=0;i<forest.tree_count;i++)
	{
		if(forest.trees[i].height>height_treshold)
		{
			forest.trees[i].age=1;
			forest.trees[i].height=0.5;
		}
	}
	return forest;
}	



void the_forest(int cycles, int age_treshold, float height_treshold)
{
	struct forest_t forest;

	forest=generate_forest(forest);
	printf("\n\n\n\nThe forest Before:\n\n\n\n");
	print_forest(forest);
	for(int i=0;i<cycles;i++)
	{
		forest=age_trees(forest);
		forest=cut_old_trees(forest, age_treshold);
		forest=cut_tall_trees(forest, height_treshold);
	}
	printf("\n\n\n\nThe forest after:\n\n\n\n");
	print_forest(forest);
}
	
		















































