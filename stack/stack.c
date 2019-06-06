#include <stdio.h>
#include <stdlib.h>


struct stack_t 
{
	int capacity;
	int size;
	int *data;
};

void init(struct stack_t *stack)
{
	stack->capacity=10;
	stack->size=0;
	stack->data=(int *)malloc(stack->capacity*sizeof(int));
}





void resize(struct stack_t *stack)
{
	stack->capacity++;
	stack->data=(int *)realloc(stack->data, stack->capacity*sizeof(int));
}



void push(struct stack_t *stack, int num)
{
	if(stack->size==stack->capacity)
	{
		resize(stack);
	}
	stack->data[stack->size]=num;
	stack->size++;
}

int pop(struct stack_t *stack)
{
	int a=stack->data[stack->size-1];
	stack->data[stack->size-1]=0;
	stack->size--;
	return a;
}






void print_stack(struct stack_t stack)
{
	printf("\nCapacity: %d",stack.capacity);
	printf("\nSize: %d",stack.size);
	for(int i=0;i<stack.size;i++)
	{
		printf("\n%d",stack.data[i]);
	}
	putchar('\n');
}



int main()
{
	struct stack_t stack;
	
	init(&stack);
	


	push(&stack, 1);
	push(&stack,33);
	push(&stack,323);
	push(&stack,3);
	push(&stack, 12);
	print_stack(stack);
	printf("\n%d",pop(&stack));


	print_stack(stack);

	return 0;
}


























