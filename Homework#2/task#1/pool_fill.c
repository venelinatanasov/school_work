#include <stdio.h>
#include <string.h>

struct tube_t
{
	int diameter;
	long int flow;
};
struct pool_t
{
	double capacity;
	struct tube_t tubes_in[5];
	struct tube_t tubes_out[5];
};

double fill_time(struct pool_t pool);

int main()
{
	struct pool_t pool;
	pool.tubes_in[0].flow=30;
	pool.tubes_in[1].flow=20;
	pool.tubes_in[2].flow=10;
	pool.tubes_in[3].flow=1;
	pool.tubes_in[4].flow=1;
	pool.tubes_out[0].flow=1;
	pool.tubes_out[1].flow=0;
	pool.tubes_out[2].flow=10;
	pool.tubes_out[3].flow=20;
	pool.tubes_out[4].flow=30;
		

	pool.capacity=4000000;
	
	printf("\n%f\n",fill_time(pool));
return 0;
}
double fill_time(struct pool_t pool)
{
	double time;
	double flow=0;
	for(int i=0;i<5;i++)
	{
		flow=flow+(pool.tubes_in[i].flow-pool.tubes_out[i].flow);
	}
	if(flow<0){return -1;};
	
	time=pool.capacity/flow;
	return time;
}
	
