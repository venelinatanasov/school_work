#include <stdio.h>
#include <string.h>

struct product_t
{
	char name[100];
	double price;
	int quantity;
};

struct shop_t
{
	char shop_name[100];
	double earnings;
	int product_count;
	struct product_t products[20];
};
void print_shop(struct shop_t);
void print_product(struct product_t);
struct shop_t buy_products(struct shop_t,char *, int);
int main()
{
	//shop
	struct shop_t shop;
	
	strcpy(shop.shop_name,"CBA");
	shop.earnings=0;
	shop.product_count=1;

	strcpy(shop.products[0].name,"Bread");
	shop.products[0].price=1.40;
	shop.products[0].quantity=970;
	print_shop(shop);
	
	shop=buy_products(shop,"Bread",1);
	
	print_shop(shop);

	

return 0;
}


struct shop_t buy_products(struct shop_t the_shop, char product_name[100], int product_count)
{
	for(int i=0;i<20;i++)
	{
		if(!strcmp(product_name,the_shop.products[i].name))
		{
			if(the_shop.products[i].quantity==0)
			{
				product_count=0;
				return the_shop;
			}
			if(the_shop.products[i].quantity>=product_count)
			{
				
				the_shop.products[i].quantity-=product_count;
				the_shop.earnings=the_shop.earnings+(product_count*the_shop.products[i].price);
				return the_shop;
			}
			else 
			{
				product_count=the_shop.products[i].quantity;
				the_shop.products[i].quantity=0;
				the_shop.earnings=the_shop.earnings+product_count*the_shop.products[i].price;
				return the_shop;
			}
			
		}
	}
	return the_shop;
}
void print_product(struct product_t product)
{
	printf("%s\n%f\n%d\n",product.name,product.price,product.quantity);
}

void print_shop(struct shop_t shop)
{
	printf("\n%s\n%f\n%d\n",shop.shop_name,shop.earnings,shop.product_count);
	if(shop.product_count>0)
	{
		for(int i=0;i<shop.product_count;i++)
		{
			print_product(shop.products[i]);
		}
	}
}





























			
	
	
	
