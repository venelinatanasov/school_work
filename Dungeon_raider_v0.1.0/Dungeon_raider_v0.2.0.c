#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//1.1
struct hero_t
{
	int max_hp;
	int current_hp;
	int attack;
	int defence;
	char name[50];
};
//1.3
struct monster_t 
{
	int current_hp;
	int attack;
	int defence;
	char type[50];
};

//1.5
struct room_t
{
	struct monster_t *monsters;
	int monster_count;
};
//1.7
struct dungeon_t
{
	struct room_t *rooms;
	int room_count;
};






//DECLARATIONS
//1.2
void print_hero(struct hero_t);
//1.4
void print_monster(struct monster_t);
//1.6
void print_room(struct room_t);
//1.8
void print_dungeon(struct dungeon_t);
//2.1
void generate_monster(struct monster_t *,int,int,int);
//2.2
void generate_new_room(struct room_t *, int, int, int, int);
//2.3
struct dungeon_t generate_new_dungeon(int, int , int , int , int );



int main()
{







	return 0;
}



void print_hero(struct hero_t hero)
{
	putchar('\n');
	printf("Max hp: %d\n",hero.max_hp);
	printf("Current hp: %d\n",hero.current_hp);
	printf("Attack: %d\n",hero.attack);
	printf("Defence: %d\n",hero.defence);
	printf("%s\n",hero.name);
}

void print_monster(struct monster_t monster)
{
	putchar('\n');
	printf("HP: %d\n",monster.current_hp);
	printf("Attack: %d\n",monster.attack);
	printf("Defence: %d\n",monster.defence);
	printf("Type: %s\n",monster.type);
}
void print_room(struct room_t room)
{
	printf("\nThere are %d monsters in this room.",room.monster_count);
	for(int i=0;i<room.monster_count;i++)
	{
		print_monster(room.monsters[i]);
	}
}

void print_dungeon(struct dungeon_t dungeon)
{
	printf("\nThere are %d rooms in this dungeon.\n",dungeon.room_count);
	for(int i=0;i<dungeon.room_count;i++)
	{
		print_room(dungeon.rooms[i]);
	}
}

void generate_monster(struct monster_t *monster,int max_hp,int max_atk,int max_def)
{
	monster->current_hp=(rand()%(max_hp)+1);
	monster->attack=(rand()%max_atk)+1;
	monster->defence=(rand()%max_def)+1;
}
	
void generate_new_room(struct room_t *room, int monsters_num, int max_hp, int max_atk, int max_def)
{
	room->monsters=malloc(sizeof(struct monster_t)*room->monster_count);
	for(int i=0;i<monsters_num;i++)
	{
		generate_monster(&room->monsters[i], max_hp, max_atk, max_def);
	}
}

struct dungeon_t generate_new_dungeon(int max_rooms_num,int max_monsters_num, int max_hp, int max_atk, int max_def)
{
	int i=(rand()%max_rooms_num)+1;
	struct dungeon_t dungeon;
	dungeon.room_count=(rand()%max_monsters_num)+1;
	dungeon.rooms=malloc(sizeof(struct room_t)*dungeon.room_count);
	for(int z=0;z<i;z++)
	{
		generate_new_room(&dungeon.rooms[z],dungeon.room_count, max_hp, max_atk, max_def);
	}

	return dungeon;
	
}
		








