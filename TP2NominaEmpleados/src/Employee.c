#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Employee.h"

/*======================================= ALTA EMPLEADOS ==============================================*/

int initEmployees(Employee list[], int len)
{
	int i;
	int rtn = -1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			list[i].isEmpty = TRUE;
		}
		rtn = 0;

	}
	return rtn;
}

int searchTakenPosition(Employee list[], int len)
{
	int i;
	int takenPositions = 0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			takenPositions++;
		}
	}
	return takenPositions;
}

int searchFreePosition(Employee list[], int len)
{
	int i;
	int index;
	index = -1;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == TRUE)
		{
			index = i;
			break;
		}
	}
	return index;
}

void askForEmployeeData(char name[], char lastName[], float *salary, int *sector)
{
	char auxName[LIMIT_CHARACTERS];
	char auxLastName[LIMIT_CHARACTERS];
	float auxSalary;
	int auxSector;
	int nameCorrect;
	int lastnameCorrect;
	int salaryCorrect;
	int sectorCorrect;

	nameCorrect=getStringChar(auxName,
			      "Ingrese el NOMBRE del empleado:\n",
                  "Error el NOMBRE ha superado el limite de caracteres\n",
				  LIMIT_CHARACTERS, ATTEMPS, 1);
	lastnameCorrect=getStringChar(auxLastName,
			      "Ingrese el APELLIDO del empleado:\n",
				  "Error el APELLIDO ha superado el limite de caracteres\n",
				  LIMIT_CHARACTERS, ATTEMPS, 1);
	salaryCorrect=getFloatNumber(&auxSalary,
			        "Ingrese el SALARIO del empleado:\n",
					"Error el SALARIO ingresado no corresponde\n",
					0, 300000, ATTEMPS);
	sectorCorrect=getIntNumber(&auxSector,
			      "Ingrese el SECTOR en el que trabaja el empleado\n",
				  "Error SECTOR incorrecto\n",
				  0, 100, ATTEMPS);
	if(nameCorrect!=-1 && lastnameCorrect!=-1 && salaryCorrect!=-1 && sectorCorrect!=-1)
	{
		strcpy(name,auxName);
		strcpy(lastName,auxLastName);
		*salary = auxSalary;
		*sector = auxSector;
		puts("Datos cargados con exito");
	}else
	{
		puts("Empleado no cargado error en un campo");
	}
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary, int sector)
{
	int index;
	int rtn = -1;
	index = searchFreePosition(list, len);

	int i;
	int maxid=0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			if(list[i].id > maxid)
			{
				maxid = list[i].id;
			}
		}
	}

	if(list != NULL && len > 0)
	{
		if(index != -1)
		{
			askForEmployeeData(name, lastName, &salary, &sector);
			list[index].id = maxid + 1;
			strcpy(list[index].name,name);
			strcpy(list[index].lastName,lastName);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty=FALSE;
			rtn = 0;
		}
	}
	return rtn;
}

/*======================================= BAJA EMPLEADOS ==============================================*/

int findEmployeebyId(Employee* list, int len, int id)
{
	int i;
	int index = -1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len ;i++)
		{
			if(id == list[i].id && list[i].isEmpty == FALSE)
			{
				index = i;
				break;
			}
		}
	}
	return index;
}

int removeEmployee(Employee* list, int len, int id)
{
	int rtn = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len ;i++)
		{
			if(id == list[i].id && list[i].isEmpty == FALSE)
			{
				list[i].isEmpty = TRUE;
				rtn = 0;
				break;
			}
		}
	}
	return rtn;
}

/*======================================= ORDENAR EMPLEADOS ==============================================*/

int sortEmployeesbyLastName(Employee* list, int len, int order)
{
	Employee auxEmployee;
	int i;
	int j;
	int rtn = -1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == FALSE &&
				   strcmp(list[i].lastName,list[j].lastName) > 0 &&
				   order==1)
				{
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
					rtn = 0;
				}else
				{
					if(list[i].isEmpty == FALSE &&
					   strcmp(list[i].lastName,list[j].lastName) < 0 &&
					   order==2)
					{
						auxEmployee = list[i];
						list[i]=list[j];
						list[j]=auxEmployee;
						rtn = 0;
					}
				}
			}
		}
	}
 return rtn;
}

int sortEmployeesbySector(Employee* list, int len, int order)
{
	Employee auxEmployee;
	int i;
	int j;
	int rtn = -1;
	if(list != NULL && len > 0)
	{
		for(i=0; i<len; i++)
		{
			for(j=i+1; j<len; j++)
			{
				if(list[i].isEmpty == FALSE &&
				   list[i].sector > list[j].sector &&
				   order==1)
				{
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
					rtn = 0;
				}else
				{
					if(list[i].isEmpty == FALSE &&
					   list[i].sector < list[j].sector &&
					   order==2)
					{
						auxEmployee = list[i];
						list[i]=list[j];
						list[j]=auxEmployee;
						rtn = 0;
					}
				}
			}
		}
	}
 return rtn;
}

/*======================================= PROMEDIAR EMPLEADOS ==============================================*/

int averageSalaryEmployee(Employee* list, int len)
{
	int i;
	float auxSalary;
	int employeeQuantity = 0;
	float averageSalary = 0;
	int overAverageSalary = 0;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE &&
		   list[i].salary != 0)
		{
			employeeQuantity++;
			auxSalary = list[i].salary + auxSalary;
		}
	}
	averageSalary = auxSalary / employeeQuantity;
	printf("\nSuma Total de salarios: %8.2f\n\n", auxSalary);
	printf("Promedio de salarios: %8.2f\n\n", averageSalary);
	printf("Empleados que superan el salario promedio: %d\n\n", overAverageSalary = overAverageSalaryEmployee(list, len, averageSalary));
 return 0;
}

int overAverageSalaryEmployee(Employee* list, int len, float averageSalary)
{
	int overAverageSalary = 0;
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE && list[i].salary > averageSalary)
		{
			overAverageSalary++;
			printEmployee(list[i]);
		}
	}
	return overAverageSalary;
}
/*======================================= MOSTRAR EMPLEADOS ==============================================*/

int printEmployee(Employee employee)
{
	printf("%04d %10s %10s %5.2f %2d\n",employee.id,
									   employee.name,
								       employee.lastName,
								       employee.salary,
								       employee.sector);
	return 0;
}

void printEmployees(Employee list[], int len)
{
	int i;
	for(i=0; i<len; i++)
	{
		if(list[i].isEmpty == FALSE)
		{
			printEmployee(list[i]);
		}
	}
}

