#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funcionesGet.h"
#define ATTEMPS 3

Employee* employee_new()
{
	Employee* newEmployee = NULL;
	newEmployee= (Employee*)malloc(sizeof(Employee));
	if(newEmployee!=NULL)
	{
		newEmployee->id=0;
		strcpy(newEmployee->nombre, " ");
		newEmployee->horasTrabajadas=0;
		newEmployee->sueldo=0;
	}
	return newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* newEmployee;
	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		newEmployee = (Employee*)malloc(sizeof(Employee));
		if(newEmployee != NULL)
		{
			newEmployee->id = atoi(idStr);
			strncpy(newEmployee->nombre, nombreStr, 100);
			newEmployee->horasTrabajadas = atoi(horasTrabajadasStr);
			newEmployee->sueldo = atoi(sueldoStr);
		}
	}
	return newEmployee;
}

int employee_setId(Employee* this, int id)
{
	int rtn=-1;
	if(this!=NULL && id>0)
	{
		this->id = id;
		rtn=0;
	}
	return rtn;
}

int employee_setNombre(Employee* this, char* nombre)
{
	int rtn=-1;
	if(this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		rtn=0;
	}
	return rtn;
}

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas)
{
	int rtn=-1;
	if(this!=NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas = horasTrabajadas;
		rtn=0;
	}
	return rtn;
}

int employee_setSueldo(Employee* this, int sueldo)
{
	int rtn=-1;
	if(this!=NULL && sueldo>0)
	{
		this->sueldo = sueldo;
		rtn=0;
	}
	return rtn;
}

int employee_getId(Employee* this, int* id)
{
	int rtn=-1;
	if(this!=NULL)
	{
		*id=this->id;
		rtn=0;
	}
	return rtn;
}
int employee_compareParameter(char* message)
{
	int option;
	getIntNumber(&option, message,
			"Error opcion invalida", 1, 2, ATTEMPS);
	if(option==1)
	{
		option=0;
	}else
	{
		if(option==2)
		{
			option=1;
		}
	}

	return option;
}

int employee_comparebyId(void* emp1, void* emp2)
{
	int comp=-1;
	Employee* employee1;
	Employee* employee2;

	employee1=emp1;
	employee2=emp2;

	if(employee1->id > employee2->id)
	{
		comp=0;
	}
	else
	{
		if(employee1->id < employee2->id)
		{
			comp=1;
		}
	}
	return comp;
}

int employee_comparebyName(void* emp1, void* emp2)
{
	int comp=-1;
	Employee* employee1;
	Employee* employee2;

	employee1=emp1;
	employee2=emp2;

	comp= strcmp(employee1->nombre, employee2->nombre);

	return comp;
}

int employee_comparebyHoursWorked(void* emp1, void* emp2)
{
	int comp=-1;
	Employee* employee1;
	Employee* employee2;

	employee1=emp1;
	employee2=emp2;

	if((employee1->horasTrabajadas) > (employee2->horasTrabajadas))
	{
		comp=0;
	}
	if((employee1->horasTrabajadas) < (employee2->horasTrabajadas))
	{
		comp=1;
	}
	return comp;
}

int employee_comparebySalary(void* emp1, void* emp2)
{
	int comp=-1;
	Employee* employee1;
	Employee* employee2;

	employee1=emp1;
	employee2=emp2;

	if(employee1->sueldo > employee2->sueldo)
	{
		comp=0;
	}
	else
	{
		if(employee1->sueldo < employee2->sueldo)
		{
			comp=1;
		}
	}
	return comp;
}

int employee_minLenghtList(char* path)
{
	char id[100];
	char nombre[100];
	char horasTrabajadas[100];
	char sueldo[100];
	int min = 0;

	FILE *pFile;
	if((pFile=fopen(path, "r"))!=NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);
			min++;
			//printf("min: %d\n", min);

		}
	}
	return min;
}

void employee_showEmployee(LinkedList* pArrayListEmployee, int min, int max)
{
	int i;
	Employee* this;

	for(i=0; i<max; i++)
	{
		this=ll_get(pArrayListEmployee, i);

		printf("%d,%s,%d,%d\n", this->id,
				this->nombre,
				this->horasTrabajadas,
				this->sueldo);
	}
}


