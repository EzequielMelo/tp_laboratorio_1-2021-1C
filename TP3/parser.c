#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funcionesGet.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int rtn=-1;
	char id[100];
	char nombre[100];
	char horasTrabajadas[100];
	char sueldo[100];
	char aux[300];
	Employee* employee;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile,"%s\n",aux);
		do
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id, nombre, horasTrabajadas, sueldo);
			employee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);
			if(employee != NULL)
			{
				ll_add(pArrayListEmployee, employee);
				rtn=0;
			}
		}while(!feof(pFile));
	}
    return rtn;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int len=0;
	Employee* employee;
	int rtn=-1;

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		len = ll_len(pArrayListEmployee);
		fread(employee, sizeof(Employee), len, pFile);
		if(!ll_add(pArrayListEmployee, employee))
		{
			rtn = 0;
			printf("%d,%s,%d,%d\n", (*(employee)).id, (*(employee)).nombre, (*(employee)).horasTrabajadas, (*(employee)).sueldo);
		}
	}
    return rtn;
}
