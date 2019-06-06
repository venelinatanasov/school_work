/*typedef struct
{
	char name[30];
	short int age;
	short int strenght;
	short int sex;
	short int health;
}HUMAN;
typedef struct 
{
	short int land;
	short int water;
	short int house;
	short int humans_num;
	HUMAN humans[10];
}TERRAIN;*/
typedef struct
{
	char name[30];
	unsigned char age;
	unsigned char strenght;
	unsigned char sex;
	unsigned char health;
}HUMAN;
typedef struct 
{
	unsigned char land;
	unsigned char water;
	unsigned char house;
	unsigned char humans_num;
	HUMAN humans[10];
}TERRAIN;
