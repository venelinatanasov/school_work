#include <stdio.h>

//DEFINITIONS
int is_divisor(int ,int);
int how_many_vowels(char *);
void replace_element(int *,int,int);
void print_item(int *,int);
int is_vowel(char);
int is_consonant(char);
int is_divisor_array(int *,int);
float avr_marks(float *);
int the_smallest_number(int *);
void the_smallest_five(int *,int *);
int search_in_array(int *,int);
int char_to_number(char );
int do_operation(int ,int ,char );
int how_many_times_in_number(int,int);

//MAIN
int main()
{	int arr_test[10]={1,2,3,4,5,6,7,8,9,0};
	//int arr_div[10]={2,4,6,9}; 
	int the_smallest[5];
	char c; 
	
	//float arr_marks[10]={6,5.50,5.5,5.5,5.5,5.5,1,2,5.5,5.5};
	//char str[10]="Helloo";
	//printf("\n%d\n",is_vowel('E'));	
	//printf("\n%d\n",is_consonant('B'));
	//print_item(arr_test,9);
	//replace_element(arr_test,4,10);
	//printf("\n%d\n",arr_test[3]);
	
	//printf("\n%d\n",how_many_vowels(str));
	//printf("\n%d\n",is_divisor(8,4));
	//printf("\n%d\n",is_divisor_array(arr_div,2));

//	printf("\n%f\n",avr_marks(arr_marks));
	//printf("\n\n%d\n",the_smallest_number(arr_test)); 





	//the_smallest_five(arr_test,the_smallest);
	//printf("\n\n%d   %d\n",the_smallest[0],the_smallest[4]);	
	//printf("\n%d\n",search_in_array(arr_test,7));
	//c='9';
	
	//printf("\n%d\n",char_to_number(c));
	//printf("\n%d\n",do_operation(10,5,'/'));
	printf("\n%d\n",how_many_times_in_number(-3033,3));
	
}







//FUNCTIONS
int is_vowel(char i)
{
	switch(i)
	{
		case 'a':
			return 1;
			break;
		case 'e':
			return 1;			
			break;
		case 'o':
			return 1;
			break;
		case 'u':
			return 1;
			break;
		case 'i':
			return 1;
			break;
		case 'A':
			return 1;
			break;
		case 'E':
			return 1;			
			break;
		case 'O':
			return 1;
			break;
		case 'U':
			return 1;
			break;
		case 'I':
			return 1;
			break;
	}
	return 0;
}
int is_consonant(char a)
{
	return !is_vowel(a);
}
void print_item(int arr[],int i)
{
	if(i>=0&&i<=9)
	{
		printf("\n%d\n",arr[i]);
	}
}
void replace_element(int arr[],int index,int new_element)
{
	arr[index]=new_element;
}	
int how_many_vowels(char str[])
{int k=0;
	for(int i=0;i<10;i++)
	{
		if(is_vowel(str[i]))
		{
			k++;
		}
	}
	return k;
}
int is_divisor(int a,int b)
{
	return a%b==0;
}
int is_divisor_array(int arr[], int i)
{
	for(int k=0;k<10;k++)
	{
		if(!is_divisor(arr[k],i))return 0;
	}
	return 1;
}
float avr_marks(float arr[])
{float avr=0;
	for(int i=0;i<10;i++)
	{
		avr+=arr[i];
	}
	avr=avr/10;
	return avr;
}
	
		
int the_smallest_number(int arr[])
{
	int small=arr[0];
	for(int i=0;i<10;i++)
	{
		if(arr[i]<small)
		{
			small=arr[i];
		}
	}
	return small;
}

void the_smallest_five(int arr[],int arr_five[])
{
	int k;
	int arr_copy[10];
	
	for(k=0;k<10;k++)
	{
		arr_copy[k]=arr[k];
	}

	for(int i=0;i<10;i++)
	{
		for(int z=0;z<9;z++)
		{
			if(arr_copy[z]>arr_copy[z+1])
			{
				k=arr_copy[z];
				arr_copy[z]=arr_copy[z+1];
				arr_copy[z+1]=k;
			}
		}
	}
	for(k=0;k<5;k++)
	{
		arr_five[k]=arr_copy[k];
	}
}
			
			
	
int search_in_array(int arr[],int search)
{
	int i;
	for(i=0;i<10;i++)
	{
		if(arr[i]==search){return i;};
	}
	return -1;
		




}
			
		
int char_to_number(char c)
{
	return c=c-'0';	
}
int do_operation(int a,int b,char oper)
{
	switch(oper)
	{
		case '/':
			return a/b;
			break;
		case '*':
			return a*b;
			break;
		case '+':
			return a+b;
			break;
		case '-':
			return a-b;
			break;
	}
	return 0;
}
int how_many_times_in_number(int num,int in_num)
{int i=0;
	if(num==0 && in_num==0){return 1;}
	while(num!=0)
	{	
		if(num%10==in_num)
		{
			i++;
		}
		num/=10;
	}
	return i;
}
		
	




























	
	

