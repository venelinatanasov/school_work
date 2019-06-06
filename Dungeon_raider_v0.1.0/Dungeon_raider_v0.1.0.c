#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//TREASURE
struct treasure_t
{
	int value;
};


//CHARACTER
struct character_t
{
		
	int hp;
	int attack;
	int defence;
	int treasure_count;
	struct treasure_t treasures[10];
};

//MONSTER
struct monster_t
{
	int hp;
	int attack;
	int defence;
};

//ROOM
struct room_t
{
	int monster_count;
	struct monster_t monsters[10];
	struct treasure_t treasure;
};

struct dungeon_t
{
	int room_count;
	struct room_t rooms[10];
};


//DECLARATIONS
void print_character(struct character_t);

void print_monster(struct monster_t);

void print_room(struct room_t);

struct character_t perform_combat(struct character_t , struct monster_t );

struct character_t raid_room(struct character_t ,struct room_t );

void print_dungeon(struct dungeon_t);

struct character_t raid_dungeon(struct character_t,struct dungeon_t);

void run_game(struct character_t ,struct dungeon_t);

struct monster_t generate_monster(int, int , int);

struct room_t generate_room(int , int, int,int );

struct dungeon_t generate_dungeon(int, int, int,int);

struct treasure_t generate_treasure(int );

int get_treasure_total(struct character_t);



//MAIN
int main()
{	srand(time(NULL));
	//CHARACTER
	struct character_t character;
	character.hp=5000;
	character.attack=1000;
	character.defence=700;
	character.treasure_count=0;


	/*//MONSTER
	struct monster_t monster;	
	monster.hp=6000;
	monster.attack=300;
	monster.defence=200;
	
	//ROOM
	struct room_t room;
	room.monster_count=1;
	room.monsters[0]=monster;

	//DUNGEON
	struct dungeon_t dungeon;
	dungeon.room_count=1;
	dungeon.rooms[0]=room;
	
	//PRINT
	print_character(character);
	
	print_dungeon(dungeon);*/
	


	
	run_game(character,generate_dungeon(5000,1000,700,7000));
	//printf("\n%d\n",character.hp);

	return 0;
}


//PRINT
void print_character(struct character_t character)
{
	printf("\nCharacter hp: %d\n\nCharacter attack: %d\n\nCharacter defence: %d\n",character.hp,character.attack,character.defence);
}

void print_monster(struct monster_t monster)
{
	printf("\nMonster hp: %d\n\nMonster attack: %d\n\nMonster defence: %d\n",monster.hp,monster.attack,monster.defence);
}

void print_room(struct room_t room)
{
	if(room.monster_count!=1)
	{
		printf("\nThere are %d monsters in the room.\n",room.monster_count);
	}
	else printf("\nThere is 1 monster in the room\n");
	for(int i=0;i<room.monster_count;i++)
	{
		print_monster(room.monsters[0]);
	}
}

//FIGHT
struct character_t perform_combat(struct character_t character, struct monster_t monster)
{
	int hit;
	//printf("\nA monster is approaching.\n");
	print_character(character);
	print_monster(monster);
	while(1)
	{
		hit=character.attack-monster.defence;
		if(hit>0)
		{
			monster.hp-=hit;
		}
		else 
		{
			monster.hp-=1;
			hit=1;
		}
		if(monster.hp<0)
		{
			monster.hp=0;
		}
		printf("\nThe hero hit the monster for %d. (%d remaining)\n",hit,monster.hp);
		if(monster.hp==0)
		{
			printf("\nMonster defeated!\n");
			return character;
		}
		hit=monster.attack-character.defence;
		if(hit>0)
		{
			character.hp-=hit;
		}
		else
		{
			character.hp-=1;
			hit=1;
		}
		if(character.hp<0)
		{
			character.hp=0;
		}
		printf("\nThe monster hit the hero for %d. (%d remaining)\n",hit,character.hp);
		if(character.hp==0)
		{
			printf("\nCharacter defeated!\n");
			return character;
		}
	}
}

//ROOM CLEAR
struct character_t raid_room(struct character_t character,struct room_t room)
{
	if(character.hp>0)
	{
		for(int i=0;i<room.monster_count;i++)
		{
			printf("\nMonster %d is approaching.\n",i+1);			
			character=perform_combat(character,room.monsters[i]);
			
		}
	}
	if(character.hp>0)
	{
		printf("\nRoom cleared!\n");
		character.treasure_count++;
	}
	
	return character;
}
		

void print_dungeon(struct dungeon_t dungeon)
{
	if(dungeon.room_count!=1)
	{
		printf("\nThere are %d rooms in the dungeon.\n",dungeon.room_count);
	}
	else
	{
		printf("\nThere is 1 room in the dungeon.\n");
	}
	for(int i=0;i<dungeon.room_count;i++)
	{
		print_room(dungeon.rooms[i]);
	}	
		
}

struct character_t raid_dungeon(struct character_t character,struct dungeon_t dungeon)
{
	for(int i=0;i<dungeon.room_count;i++)
	{
		if(character.hp>0)
		{
			printf("\nRaiding room %d.\n",i+1);
			character=raid_room(character,dungeon.rooms[i]);
		}
		if(character.hp>0){character.treasures[i]=dungeon.rooms[i].treasure;}
		
	}

	return character;
}

void run_game(struct character_t character,struct dungeon_t dungeon)
{	
	printf("\nThe hero is in a dungeon full of monsters.\n");
	character=raid_dungeon(character,dungeon);
	if(character.hp==0)
	{
		printf("\nThe hero is dead! The dungeon won!\n");
	}
	else 
	{
		printf("\nThe dungeon is clear. The hero won!\n");
		printf("\nHe found %d gold!.\n",get_treasure_total(character));
	}
}

struct monster_t generate_monster(int max_hp, int max_attack, int max_defence)
{
	struct monster_t monster;
	do
	{
		monster.hp=rand()%(max_hp+1);
	}while(monster.hp==0);
	do
	{
		monster.attack=rand()%(max_attack+1);
	}while(monster.hp==0);
	do
	{
		monster.defence=rand()%(max_defence+1);
	}while(monster.defence==0);
	return monster;
}

struct room_t generate_room(int max_hp, int max_attack, int max_defence,int max_value)
{
	struct room_t room;
	do
	{
		room.monster_count=rand()%11;
	}while(room.monster_count==0);
	for(int i=0;i<room.monster_count;i++)
	{
		room.monsters[i]=generate_monster(max_hp, max_attack, max_defence);
	}
	room.treasure=generate_treasure(max_value);
	return room;
}
struct dungeon_t generate_dungeon(int max_hp, int max_attack, int max_defence,int max_value)
{
	struct dungeon_t dungeon;
	do
	{
		dungeon.room_count=rand()%11;
	}while(dungeon.room_count==0);
	for(int i=0;i<dungeon.room_count;i++)
	{
		dungeon.rooms[i]=generate_room(max_hp, max_attack, max_defence,max_value);
	}
	return dungeon;
}

		
struct treasure_t generate_treasure(int max_value)
{
	struct treasure_t treasure;	
	do
	{
		treasure.value=rand()%(max_value-1);
	}while(treasure.value==0);
	return treasure;
}
		
			
int get_treasure_total(struct character_t character)
{	int tr=0;
	for(int i=0;i<character.treasure_count;i++)
	{
		tr+=character.treasures[i].value;
	}
	return tr;
}
	
