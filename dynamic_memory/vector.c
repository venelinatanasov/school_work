#include <stdio.h>
#include <stdlib.h>
#define INIT_CAPACITY 10

struct vector_t
{
	int capacity;
	int size;
	int *data;
};

struct vector_t init()
{
	struct vector_t vec;
	vec.capacity=INIT_CAPACITY;
	vec.data=(int *)malloc(INIT_CAPACITY*sizeof(int));
	vec.size=0;

	return vec;
}


void destroy(struct vector_t *vector)
{
	free(vector->data);
	vector->data=NULL;
	vector->capacity=0;
	vector->size=0;
}

void resize(struct vector_t *vector)
{
	int *tmp=vector->data;
	vector->capacity*=2;
	vector->data=malloc(vector->capacity * sizeof(int));
	for(int i=0;i<vector->size;i++)
	{
		vector->data[i]=tmp[i];
	}
	free(tmp);
}
	
	


void add_at(struct vector_t *vector, int position, int elem)
{
	if(vector->data==NULL)
	{
		return;
	}
	if(vector->capacity==vector->size)
	{
		resize(vector);
	}
	if(position<0||position>vector->size)
	{
		return;
	}
	for(int i=vector->size;i>position;i--)
	{
		vector->data[i]=vector->data[i-1];
	}
	vector->data[position]=elem;
	vector->size++;

}		



void print_vector(struct vector_t vector)
{
	printf("\n%d\n",vector.capacity);
	printf("\n%d\n",vector.size);putchar('\n');
	for(int i=0;i<vector.size;i++)
	{
		printf("%d",vector.data[i]);
	}
}



int main()
{
	struct vector_t vector=init();
	for(int i=0;i<10;i++)
	{
		vector.data[i]=i+1;
	}
	print_vector(vector);
	add_at(&vector,5,10);
	printf("\n%ld\n",sizeof(vector.data));
	print_vector(vector);

	resize(&vector);
	printf("\n%ld\n",sizeof(vector.data));
	print_vector(vector);
	destroy(&vector);
	printf("\n%ld\n",sizeof(vector.data));
	print_vector(vector);

	return 0;
}



















