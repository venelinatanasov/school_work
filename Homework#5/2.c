#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void input(int *, int *);



int main(int argc, char **argv)
{
	int N=atoi(argv[1]);//printf("%d",N);
	int train[4]={0};
	int in[4];int out[4];int time=0;
	int more;

		/*input(in,out);

		for(int p=0;p<4;p++)
		{
			printf("%d",in[p]);
		}
		putchar('\n');
		for(int p=0;p<4;p++)
		{
			printf("%d",out[p]);
		}
	
		getchar();
		getchar();*/

	for(int g=0;g<5;g++)
	{
		input(in,out);
		for(int z=0;z<4;z++)
		{
			time+=in[z];
			time+=out[z];
		}
		more=0;
		for(int i=0;i<4;i++)
		{
			
			//time+=out[i];
			train[i]=train[i]-out[i];
		
			if(train[i]+in[i]<=N)
			{
				train[i]+=in[i];
				//time+=in[i];
			}
			else
			{
				more+=in[i]-(N-train[i]);

				train[i]+=(N-train[i]);
				//time+=(N-train[i]);
		
			}
			




			 
		}
		if(more>0)
		{	
			printf("There wasn't room for %d passengers.\n",more);
			time-=more;
		}
	}
	printf("\nTotal wait time: %d\n",time);
			
	
	
		



	return 0;
}



void input(int in[], int out[])
{
	
	int k;
	for(int i=0;i<4;i++)
	{
		scanf("%d",&k);
		out[i]=k;
	}
	getchar();
	for(int i=0;i<4;i++)
	{
		scanf("%d",&k);
		in[i]=k;
	}
}			


