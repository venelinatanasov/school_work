#include <stdio.h>
#include <stdlib.h>

struct node_t
{
	int value;
	struct node_t *next;
};

struct list_t
{
	struct node_t *first;
};


struct stack_t
{
	struct list_t data;
	int size;
};


struct list_t init_list()
{
	struct list_t list;
	list.first=NULL;

	return list;
}
struct stack_t init_stack()
{
	struct stack_t stack;
	stack.data=init_list();
	stack.size=0;
	return stack;
}

void insert(struct list_t* list, int value)
{
	struct node_t* new=(struct node_t *)malloc(sizeof(struct node_t));
	new->value=value;
	new->next=list->first;
	list->first=new;
}



void remove_first(struct list_t *list)
{
	struct node_t *tmp=list->first->next;
	free(list->first);
	list->first=tmp;
}

void push(struct stack_t *stack,int value)
{
	insert(&stack->data,value);
	stack->size++;
}

int pop(struct stack_t *stack)
{
	int value=stack->data.first->value;
	remove_first(&stack->data);
	stack->size--;
	return value;
	
}

	

	
void print_list(struct list_t *list)
{
	for(struct node_t *n=list->first;n!=NULL;n=n->next)
	{
		printf("\n%d",n->value);
	}
	putchar('\n');
}

void destroy_list(struct list_t *list)
{

	struct node_t *tmp=list->first;
	
	while(tmp!=NULL)
	{
		
		struct node_t *free_node=tmp;
		tmp=tmp->next;
		free(free_node);
	}

	list->first=NULL;
}

int size(struct list_t *list)
{	int i=0;
	for(struct node_t *n=list->first;n!=NULL;n=n->next)
	{
		i++;
	}
	return i;
}

int is_empty(struct list_t *list)
{
	if(list->first==NULL)
	{
		return 1;
	}
	return 0;
}		



void insert_after(struct list_t *list, int after, int value)
{
	struct node_t *tmp=list->first;
	
	for(int i=1;i<after;i++)
	{
		tmp=tmp->next;
	}
	
	struct node_t *tmp2=tmp->next;
	tmp->next=(struct node_t *)malloc(sizeof(struct node_t));
	tmp->next->value=value;
	tmp->next->next=tmp2;
}
		
void remove_after(struct list_t *list, int after)
{
	struct node_t *tmp=list->first;
	for(int i=1;i<after;i++)
	{
		tmp=tmp->next;
	}
	struct node_t *tmp2=tmp->next;
	tmp->next=tmp2->next;
	free(tmp2);
}

int get(struct list_t *list, int pos)
{
	struct node_t *tmp=list->first;
	for(int i=1;i<pos;i++)
	{
		tmp=tmp->next;
	}
	return tmp->value;
}

struct list_t copy_list(struct list_t *list)
{
	struct list_t new;
	struct node_t *tmp=list->first;
	struct node_t *tmp2;

	for(int i=1;i<size(list);i++)
	{
		if(i==1)
		{
			new.first=(struct node_t *)malloc(sizeof(struct node_t *));
			tmp2=new.first;
			*tmp2=*tmp;
			continue;
		}
		tmp2->next=(struct node_t *)malloc(sizeof(struct node_t *));
		tmp2=tmp2->next;
		tmp=tmp->next;
		*tmp2=*tmp;
	}
	
	return new;
}
		
		
		
	
		






























		

int main()
{
	
/*	struct list_t list=init_list();
	insert(&list,3);
//	print_list(&list);
	insert(&list,23);
	
	//print_list(&list);
	//printf("%d\n",size(&list));
	insert_after(&list,2,15);
	insert_after(&list,3,105);
	remove_after(&list,3);
	//destroy_list(&list);
	//print_list(&list);
	
	//printf("\n%d\n",get(&list,3));	
	//printf("%d\n",size(&list));

	struct list_t list2=copy_list(&list);
	print_list(&list2);
	print_list(&list);

	destroy_list(&list);*/
	struct stack_t stack=init_stack();
	push(&stack,1);	
	push(&stack,34);	
	push(&stack,11);	
	push(&stack,123);
	for(int i=0;i<4;i++)
	{
		printf("%d\n",pop(&stack));
	}
	destroy_list(&stack.data);







	
	

	
	return 0;
}
