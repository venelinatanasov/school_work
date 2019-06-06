HUMAN
generate_human(HUMAN human)
{
	FILE *f;
	human.sex=rand()%2;
	//1 for male 
	//0 for female
	int i=0;	
	if(human.sex)
	{	int a=rand()%2900;
		f=fopen("male.txt","r");
		while(i<a)//there are 2900 names in the file
		{
			fgets(human.name,30,f);
			i++;
		}
		fclose(f);
		//printf("\ni %d\n",i);
		
	}
	else
	{	int a=rand()%5000;
		f=fopen("female.txt","r");
		i=0;
		while(i<a)//there are 5000 names in the file
		{
			fgets(human.name,30,f);
			i++;
		}
		//printf("\ni %d\n",i);
		fclose(f);
	}
	//printf("\n%s   %d\n",human.name,human.sex);

	
	
	human.age=rand()%31+19;
	printf("\nage %d\n",human.age);getchar();
	human.name[30]=0;//i use the 30th byte for move check when moving down and right. i use it only in random_move()
	
	
	human.strenght=(rand()%(100-human.age))+human.age;
	



	human.health=rand()%100;
	printf("\nHuman generated.\n");
	return human;
}
void print_human(HUMAN h)
{	
	printf("\n%s",h.name);
	printf("%d years old.\n",h.age);

	if(h.sex)
	{
		printf("Male\n");
	}else printf("Female\n");
	printf("Strenght: %d\n",h.strenght);
	printf("Health: %d\n",h.health);
}




TERRAIN
generate_piece_of_terrain(TERRAIN t)
{
	t.humans_num=0;
	t.land=1;
	t.water=0;
	t.house=0;
	int a=rand()%101;
	if(a>=0&&a<=5)
	{
		
		t.humans_num=1;
		t.humans[0]=generate_human(t.humans[0]);
	}
	//printf("\nPiece generated\n");
	return t;
}

void print_piece_of_terrain(TERRAIN t)
{
	if(t.land)
	{
		printf("\nLand!\n");
	}
	if(t.house&&t.land)
	{
		printf("Land with house\n");
	}
	if(t.water)
	{
		printf("Water\n");
	}
	for(int i=0;i<t.humans_num;i++)
	{
		print_human(t.humans[i]);
	}
	
}



void
generate_terrain()
{
	for(int x=0;x<size_of_terrain;x++)
	{
		for(int y=0;y<size_of_terrain;y++)
		{

			terrain[x][y]=generate_piece_of_terrain(terrain[x][y]);
		}
	}
	//printf("\nTerrain generated\n");
	
}



void
print_whole_terrain()
{
	system("clear");
	for(int y=0;y<size_of_terrain;y++)
	{
		for(int x=0;x<size_of_terrain;x++)
		{
			if(terrain[y][x].land&&!terrain[y][x].humans_num)
			{
				putchar('0');
			}
			if(terrain[y][x].land&&terrain[y][x].humans_num)
			{
				putchar(terrain[y][x].humans_num+'0');
			}
			if(terrain[y][x].water)
			{
				putchar('w');
			}
		}
		printf("\n");
	}
	//printf("\nSuccessfully printed whole terrain.\n");
}
			




void random_move()
{	
	int dir;//1-up, 2-right, 3-down, 4-left	
	for(int y=0;y<size_of_terrain;y++)
	{
		for(int x=0;x<size_of_terrain;x++)
		{		//print_whole_terrain();
				int a=terrain[y][x].humans_num-1;
				/*printf("\na set: %d\n",a);
				printf("\nPress any key to continue...\n");
				getchar();*/
	
				for(int i=0;i<=a;i++)
				{


					if(!terrain[y][x].humans[i].name[30])
					{
					
						dir=(rand()%4)+1;
						/*printf("\nDir: %d\n",dir);
						printf("\nPress any key to continue...\n");
						getchar();*/
						if(dir==1)
						{
							if(y==0)
							{
								continue;
								
							}
							terrain[y-1][x].humans[terrain[y-1][x].humans_num]=terrain[y][x].humans[i];
							for(int i1=i;i1<a;i1++)
							{
								terrain[y][x].humans[i1]=terrain[y][x].humans[i1+1];
							}	
																			
							terrain[y-1][x].humans_num++;
							terrain[y][x].humans_num--;
							i--;
							a--;
							/*printf("\nDir 1 executed\n");
							printf("\nPress any key to continue...\n");
							getchar(); */
							
						}
						if(dir==2)
						{
							if(x==size_of_terrain-1)
							{
								continue;
								
							}
							terrain[y][x+1].humans[terrain[y][x+1].humans_num]=terrain[y][x].humans[i];
							for(int i1=i;i1<a;i1++)
							{
								terrain[y][x].humans[i1]=terrain[y][x].humans[i1+1];
							}							
							terrain[y][x+1].humans_num++;
							terrain[y][x].humans_num--;
							terrain[y][x+1].humans[terrain[y][x+1].humans_num-1].name[30]=1;
							i--;
							a--;
							/*printf("\nDir 2 executed\n");
							printf("\nPress any key to continue...\n");
							getchar();*/ 
						}					
						if(dir==3)
						{
							if(y==size_of_terrain-1)
							{
								continue;
								
							}
							terrain[y+1][x].humans[terrain[y+1][x].humans_num]=terrain[y][x].humans[i];
							for(int i1=i;i1<a;i1++)
							{
								terrain[y][x].humans[i1]=terrain[y][x].humans[i1+1];
							}
							terrain[y+1][x].humans_num++;
							terrain[y][x].humans_num--;
							terrain[y+1][x].humans[terrain[y+1][x].humans_num-1].name[30]=1;
							i--;
							a--;
							/*printf("\nDir 3 executed\n");
							printf("\nPress any key to continue...\n");
							getchar();*/ 
						}
							
						if(dir==4)
						{
							if(x==0)
							{
								continue;
								
							}
							terrain[y][x-1].humans[terrain[y][x-1].humans_num]=terrain[y][x].humans[i];
							for(int i1=i;i1<a;i1++)
							{
								terrain[y][x].humans[i1]=terrain[y][x].humans[i1+1];
							}
							terrain[y][x-1].humans_num++;
							terrain[y][x].humans_num--;
							i--;
							a--;
							/*printf("\nDir 4 executed\n");
							printf("\nPress any key to continue...\n");
							getchar(); */
						}
						if(!terrain[y][x].humans_num)
						{
							break;
						}
					}
					else
					{
						terrain[y][x].humans[i].name[30]=0;
						break;
					}
				}
		}
	}
	//printf("\nRandom move success!\n");
}


void year_cycle()
{				
	for(int y=0;y<size_of_terrain;y++)
	{
		for(int x=0;x<size_of_terrain;x++)
		{
			if(terrain[y][x].humans_num)
			{
				for(int i=0;i<terrain[y][x].humans_num;i++)
				{
					if(terrain[y][x].humans[i].age==terrain[y][x].humans[i].strenght)
					{
						terrain[y][x].humans_num--;
						terrain[y][x].humans[i]=terrain[y][x].humans[terrain[y][x].humans_num];	
					}
					else
					{
						terrain[y][x].humans[i].age++;
					}
				}
			}
		}
	}
		
}
void print_everyone()
{
	for(int y=0;y<size_of_terrain;y++)
	{
		for(int x=0;x<size_of_terrain;x++)
		{
			if(terrain[y][x].humans_num)
			{
				//for(int i=0;i<terrain[y][x].humans_num;i++)
				//{
					printf("\nagg%d\n",terrain[y][x].humans[0].age);
					print_human(terrain[y][x].humans[0]);
				//}
			}
		}
	}
}
	
					






















				
				
			









































		






















