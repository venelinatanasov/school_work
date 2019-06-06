#include <stdio.h>
#include <stdlib.h>
#define INIT_CAP 3
struct vector_t 
{
	int capacity;
	int size;
	int *data;
};


void resize(struct vector_t *vector)
{
	vector->capacity++;
	vector->data=realloc(vector->data,vector->capacity*sizeof(int));
} 	

void init(struct vector_t *vector)
{
	vector->capacity=INIT_CAP;
	vector->size=0;
	vector->data=malloc(INIT_CAP*sizeof(int));
}


void add_at(struct vector_t *vector, int position, int num)
{
	if(vector->size==vector->capacity)
	{
		resize(vector);
	}  
	vector->size++;
	for(int i=vector->size-1;i>position;i--)
	{
		vector->data[i]=vector->data[i-1];
	}
	vector->data[position]=num;
}

void add_at_beginning(struct vector_t *vector,int num)
{
	add_at(vector, 0, num);
}
void add_at_the_end(struct vector_t *vector,int num)
{
	add_at(vector, vector->size, num);
}
	


void print_vector(struct vector_t vector)
{
	printf("\nVector capacity: %d",vector.capacity);
	printf("\nVector size: %d",vector.size);
	for(int i=0;i<vector.size;i++)
	{
		printf("\n%d",vector.data[i]);
	}
	putchar('\n');
}


void destroy_vector(struct vector_t *vector)
{
	vector->capacity=0;
	vector->size=0;
	free(vector->data);
	vector->data=NULL;
}
	





int main()
{
	struct vector_t vector;
	init(&vector);
	print_vector(vector);	
	add_at_the_end(&vector, 50);
	add_at_beginning(&vector, 10);
	add_at(&vector, 1, 4);
	add_at(&vector, 1, 5);
	add_at(&vector, 2, 40);
	add_at_the_end(&vector, 51);
	add_at_beginning(&vector, 15);
	print_vector(vector);


	//printf("\n\n\nsize %ld\n\n\n\n",sizeof(*vector.data));



	destroy_vector(&vector);
	

	print_vector(vector);





	//printf("\n\n\nsize %ld\n\n\n\n",sizeof(*vector.data));
	
	return 0;
}



























