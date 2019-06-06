#include <stdio.h>
#include <string.h>

struct patient_t
{
	char first_name[100];
	char last_name[100];
	int condition_count;
	char conditions[5][50];
	int severity;
	int for_operation;
};

struct hospital_t
{
	int patient_count;
	struct patient_t patients[10];
	int operating_room_capacity;
};

struct hospital_t mark_for_operation(struct hospital_t the_hospital);
struct hospital_t sort(struct hospital_t the_hospital,int count);

int main()
{	struct hospital_t hospital;

	//hospital
	//printf("\nhospital set\n");
	hospital.patient_count=3;
	hospital.operating_room_capacity=2;
	//patient 1
	//printf("\npatient 1 set\n");
	strcpy(hospital.patients[0].first_name,"Gosho");
	strcpy(hospital.patients[0].last_name,"Tsekov");
	strcpy(hospital.patients[0].conditions[0],"Almost dead");
	hospital.patients[0].severity=2;
	hospital.patients[0].condition_count=1;
	//patient 2
	//printf("\npatient 2 set\n");
	strcpy(hospital.patients[1].first_name,"Pesho");
	strcpy(hospital.patients[1].last_name,"De la Mancha");
	strcpy(hospital.patients[1].conditions[0],"Missing leg");
	hospital.patients[1].severity=2;
	hospital.patients[1].condition_count=1;
	

	strcpy(hospital.patients[2].first_name,"Misho");
	strcpy(hospital.patients[2].last_name,"The god");
	strcpy(hospital.patients[2].conditions[0],"Missing legs");
	hospital.patients[2].severity=2;
	hospital.patients[2].condition_count=1;

	if(hospital.operating_room_capacity==0)
	{
		printf("\nNo place for operations!\n");
	}
	hospital=mark_for_operation(hospital);
	//printf("\n%d\n",hospital.patients[0].for_operation);
	//printf("\n%d\n",hospital.patients[1].for_operation);
	for(int i=0;i<hospital.patient_count;i++)
	{
		if(hospital.patients[i].for_operation==1)
		{	//printf("\nin if\n");
			printf("\nFor operation: %s\n",hospital.patients[i].first_name);
		}
	}
	
	
	return 0;
}

struct hospital_t mark_for_operation(struct hospital_t the_hospital)
{
	the_hospital=sort(the_hospital,the_hospital.patient_count);
	for(int i=0;i<the_hospital.operating_room_capacity&&i<the_hospital.patient_count;i++)
	{
		the_hospital.patients[i].for_operation=1;
		//printf("\nFor operation : %s\n",the_hospital.patients[i].first_name);
	}
	//printf("\n11%s\n",the_hospital.patients[0].first_name);
	//printf("\n11%s\n",the_hospital.patients[1].first_name);
	return the_hospital;
}
		




struct hospital_t sort(struct hospital_t the_hospital,int count)
{
	struct patient_t help;
	
	for(int i=0;i<count;i++)
	{
		for(int k=0;k<count-1;k++)
		{	//printf("\nsorting\n");
			if(the_hospital.patients[k].severity<the_hospital.patients[k+1].severity)
			{
				help=the_hospital.patients[k];
				the_hospital.patients[k]=the_hospital.patients[k+1];
				the_hospital.patients[k+1]=help;
			}
		}
	}
	//printf("\n12%s\n",the_hospital.patients[0].first_name);
	//printf("\n12%s\n",the_hospital.patients[1].first_name);
	return the_hospital;
}
