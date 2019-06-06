#include <stdio.h>
#include <stdlib.h>
#include <string.h>



int S;
int W;
int F;
int I;
int helpp;
char helpstr[200];
struct product_t
{
	char name[700];
	float quality;
	int quantity;
};

struct factory_t
{
	char name[700];
	char product_name[700];
	float quality;
	int quantity;
};

struct warehouse_t
{
	int compartments;
	int max_product_in_compartment;
	struct product_t products[100];
};
void print_product(struct product_t product)
{
	printf("%s",product.name);
	printf("Quality: %f\n",product.quality);
	printf("Quantity: %d\n",product.quantity);
}


struct factory_t input_factory()
{
	struct factory_t factory;
	printf("Factory name: ");
	fgets(factory.name,700,stdin);
	//putchar('\n');
	printf("Factory product name: ");
	fgets(factory.product_name,700,stdin);
	//putchar('\n');
	
	do
	{
		printf("Quality: ");
		scanf("%f",&factory.quality);
	}while(factory.quality>1||factory.quality<=0);
	//putchar('\n');
	printf("Quantity: ");
	scanf("%d",&factory.quantity);
	putchar('\n');
	getchar();
	return factory;
}
	
struct product_t *produce(struct factory_t *factories)
{
	struct product_t *products=(struct product_t *)malloc(F*sizeof(struct product_t));
	
	for(int i=0;i<F;i++)
	{
		strcpy(products[i].name,factories[i].product_name);
		products[i].quality=factories[i].quality;
		products[i].quantity=factories[i].quantity;
		factories[i].name[strlen(factories[i].name)-1]='\0';
		printf("%s produced %d %s\n",factories[i].name, factories[i].quantity, factories[i].product_name);
		//print_product(products[i]);
	}
	
	return products;
}


int in_wr(struct product_t product, struct warehouse_t warehouse)
{
	for(int i=0;i<warehouse.compartments;i++)
	{
		//printf("\ninwr\n");
		//print_product(product);
		//print_product(warehouse.products[i]);







		if(((!(strcmp(product.name,warehouse.products[i].name)))&&(product.quality==warehouse.products[i].quality)&&warehouse.products[i].quantity<warehouse.max_product_in_compartment)||warehouse.products[i].quantity==0)
		{
			//printf("Found: %d",i);
			return i;
		}
	}
	return 0;
}
	
void distribute(struct product_t *products, struct warehouse_t *warehouse)
{	int a;int pra=0;
	for(int i=0;i<F;i++)
	{	pra=0;
		while(products[i].quantity>0)
		{
			a=in_wr(products[i],*warehouse);
			if(a<pra){helpp=products[i].quantity;strcpy(helpstr,products[i].name);break;};
			pra=a;
			//printf("Found cell: %d\n",a);
			if(a<warehouse->compartments)
			{
				
					
				if(warehouse->products[a].quantity+products[i].quantity>warehouse->max_product_in_compartment)
				{
					products[i].quantity-=(warehouse->max_product_in_compartment-warehouse->products[a].quantity);
					warehouse->products[a].quantity=warehouse->max_product_in_compartment;
					warehouse->products[a].quality=products[i].quality;
					strcpy(warehouse->products[a].name,products[i].name);
				}
				else
				{
					strcpy(warehouse->products[a].name,products[i].name);
					warehouse->products[a].quality=products[i].quality;
					warehouse->products[a].quantity+=products[i].quantity;
					products[i].quantity=0;
				}
			}
			else
			{
				/*for(k=0;(warehouse->products[k].quantity!=0&&k!=warehouse->compartments);k++)
				{
				}
				warehouse->products[k]=products[i];
				
				if(k==warehouse->compartments)
				{*/
					
					break;
				//}
				
			}
					
	
			
		}
		
	
	
	
	
	
	}
}

void iter(struct factory_t *factories, struct warehouse_t *warehouse)
{
	struct product_t *products=produce(factories);
	distribute(products,warehouse);
}



			
							
	
					


void print_warehouse(struct warehouse_t warehouse)
{
	printf("Warehouse: \n");
	for(int i=0;i<W;i++)
	{
		if(warehouse.products[i].quantity>0)
		{
			printf("%d - %d %s\n",i+1, warehouse.products[i].quantity, warehouse.products[i].name);
		}
		else printf("<empty>\n\n");
	}
}

















int main(int argc, char *argv[])
{
	F=atoi(argv[1]);
	W=atoi(argv[2]);
	S=atoi(argv[3]);
	I=atoi(argv[4]);
	struct factory_t factories[F];
	struct warehouse_t warehouse;
	warehouse.compartments=W;
	warehouse.max_product_in_compartment=S;
	for(int i=0;i<100;i++)
	{
		warehouse.products[i].quantity=0;
	}
	for(int i=0;i<F;i++)
	{
		factories[i]=input_factory();
	}		
	//struct product_t *products=produce(factories);
	/*for(int i=0;i<F;i++)
	{
		print_product(products[i]);
	}*/

	for(int i=0;i<I;i++)
	{
		printf("Iteration %d\n\n",i+1);
		iter(factories, &warehouse);
		print_warehouse(warehouse);
		if(helpp)
		{
			printf("There isn't any room for the remaining %d %s\n",helpp,helpstr);
			helpp=0;
		}
	}


	return 0;
}

