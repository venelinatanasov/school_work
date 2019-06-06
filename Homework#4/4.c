#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Venelin Atanasov 10g N8



#define INIT_CAP 10
struct process_t
{
	int ID;
	int duration;
};
struct vector_t
{
	int capacity;
	int size;
	struct process_t *data;
};




//DECLARATIONS
void init_vec(struct vector_t *);
void resize_vec(struct vector_t *);
void add_at(struct vector_t *, int , struct process_t);

void add_at_the_end(struct vector_t *, struct process_t);

void exec();
int input_buffarr(struct process_t *);
void input_process(struct process_t *);

void sort(struct vector_t *, struct vector_t *, struct vector_t *, struct vector_t *, struct process_t *);
int get_dur(struct vector_t);
void print_processor(struct vector_t,int);
long int last_id=0;
void destroy_vector(struct vector_t *);




int main()
{

	exec();
	return 0;
}

void exec()
{
	
	struct vector_t CPU1;
	struct vector_t CPU2;
	struct vector_t CPU3;
	struct vector_t CPU4;
	init_vec(&CPU1);
	init_vec(&CPU2);
	init_vec(&CPU3);
	init_vec(&CPU4);
	struct process_t buffarr[5];
	
	while(1)
	{
		if((input_buffarr(buffarr)))
		{
			break;
		}
		sort(&CPU1,&CPU2,&CPU3,&CPU4,buffarr);
		print_processor(CPU1,1);
		print_processor(CPU2,2);
		print_processor(CPU3,3);
		print_processor(CPU4,4);
		
	}
	destroy_vector(&CPU1);
	destroy_vector(&CPU2);
	destroy_vector(&CPU3);
	destroy_vector(&CPU4);






}
void print_processor(struct vector_t CPU,int num)
{
	printf("Queue for processor %d: %d processes, Total time: %d\n",num,CPU.size,get_dur(CPU));
}

void sort(struct vector_t *CPU1, struct vector_t *CPU2, struct vector_t *CPU3, struct vector_t *CPU4, struct process_t *buff)
{
		
	int buff_dur=0;
	for(int i=0;i<5;i++)
	{
		buff_dur+=buff->duration;
	}
	float avr=(get_dur(*CPU1)+get_dur(*CPU2)+get_dur(*CPU3)+get_dur(*CPU4)+buff_dur)/9;
	int sm_diff;
	int cpu_buff;
	for(int i=0;i<5;i++)
	{
		sm_diff=abs(get_dur(*CPU1)+buff[i].duration-avr);
		cpu_buff=1;
		if(abs(get_dur(*CPU2)+buff[i].duration-avr)<sm_diff)
		{
			cpu_buff=2;
			sm_diff=abs(get_dur(*CPU2)+buff[i].duration-avr);
		}
		if(abs(get_dur(*CPU3)+buff[i].duration-avr)<sm_diff)
		{
			sm_diff=abs(get_dur(*CPU3)+buff[i].duration-avr);
			cpu_buff=3;
		}
		if(abs(get_dur(*CPU4)+buff[i].duration-avr)<sm_diff)
		{
			sm_diff=abs(get_dur(*CPU4)+buff[i].duration-avr);
			cpu_buff=4;
		}	
		

		if(cpu_buff==1)
		{
			add_at_the_end(CPU1,buff[i]);
		}			
		if(cpu_buff==2)
		{
			add_at_the_end(CPU2,buff[i]);
		}
		if(cpu_buff==3)
		{
			add_at_the_end(CPU3,buff[i]);
		}			
		if(cpu_buff==4)
		{
			add_at_the_end(CPU4,buff[i]);
		}
	}








}
int get_dur(struct vector_t CPU)
{	int dur=0;
	for(int i=0;i<CPU.size;i++)
	{
		dur+=CPU.data[i].duration;
	}
	return dur;
}		

int input_buffarr(struct process_t *buff)
{
	int a;
	for(int i=0;i<5;i++)
	{
		a=last_id;
		input_process(&buff[i]);
		if(last_id==a)return 1;
		
	}
	
	return 0;
	
}

void input_process(struct process_t *process)
{
	
	char ch[10];
	fgets(ch,10,stdin);
	if(!strcmp(ch,"exit\n")){return;}
	
	process->duration=atoi(ch);
	last_id++;
	process->ID=last_id;
	
}




void init_vec(struct vector_t *vector)
{
	vector->capacity=INIT_CAP;
	vector->size=0;
	vector->data=(struct process_t *)malloc(INIT_CAP*sizeof(struct process_t));
	for(int i=0;i<vector->capacity;i++)
	{
		vector->data[i].duration=0;
	}
}


void resize_vec(struct vector_t *vector)
{
	vector->capacity++;
	vector->data=(struct process_t *)realloc(vector->data,vector->capacity*sizeof(struct process_t));
}


void add_at(struct vector_t *vector, int pos, struct process_t process)
{
	if(vector->size==vector->capacity)
	{
		resize_vec(vector);
	}
	vector->size++;
	for(int i=vector->size-1;i>pos;i--)
	{
		vector->data[i]=vector->data[i-1];
	}
	vector->data[pos]=process;
}

void add_at_the_end(struct vector_t *vector, struct process_t process)
{
	add_at(vector, vector->size, process);
}

void destroy_vector(struct vector_t *vector)
{
	vector->capacity=0;
	vector->size=0;
	free(vector->data);
	vector->data=NULL;
}
