#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funcionesGet.h"
#define ATTEMPS 3
#define NAMETAM 128

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int rtn=-1;

	if((pFile=fopen(path, "r"))!=NULL)
	{
		ll_clear(pArrayListEmployee);

		if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
		{
			rtn= 0;
		}

	}
    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int rtn=-1;
	if((pFile = fopen(path, "rb"))!= NULL)
	{
		ll_clear(pArrayListEmployee);
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			rtn=0;
		}
	}
    return rtn;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;//error
	Employee* employee;
	//FILE *pFile;
	int id;
	char auxNombre[NAMETAM];
	int auxHorasTrabajadas;
	int auxSueldo;
	int option;

	if(pArrayListEmployee!=NULL)
	{
		employee=employee_new();
		if(employee!=NULL)
		{
			getIntNumber(&id, "Ingrese un ID:",
					"Error ID invalida", 1, 10000, ATTEMPS);
			getStringChar(auxNombre, "Ingrese un nombre: ",
					"Error ingrese caracteres validos", NAMETAM, ATTEMPS);
			getIntNumber(&auxHorasTrabajadas, "Ingrese horas trabajadas:",
					"Error ingrese un horario valido", 1, 30000, ATTEMPS);
			getIntNumber(&auxSueldo, "Ingrese el sueldo:",
					"Error sueldo valido", 1, 300000, ATTEMPS);
			employee_setId(employee, id);
			employee_setNombre(employee, auxNombre);
			employee_setHorasTrabajadas(employee, auxHorasTrabajadas);
			employee_setSueldo(employee, auxSueldo);
			if(!getIntNumber(&option, "Desea cargar los Datos?\n1-SI\n2-NO",
					"Error opcion invalida", 1, 2, ATTEMPS))
			{
				if(!ll_add(pArrayListEmployee, employee))
				{
					puts("Empleado Cargado con exito");
					printf("%d,%s,%d,%d\n", (*employee).id, (*employee).nombre, (*employee).horasTrabajadas, (*employee).sueldo);
					rtn=0;
				}
			}
		}

	}

    return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	int rtn=-1;
	int idToGet;
	int i;
	int len;
	int option;
	int subOption;
	char auxNombre[NAMETAM];
	int auxHorasTrabajadas;
	int auxSueldo;

	setbuf(stdout,NULL);
	puts("Ingrese el ID del empleado:");
	scanf("%d", &idToGet);

	len=ll_len(pArrayListEmployee);
	for(i=0;i<len;i++)
	{
		employee=ll_get(pArrayListEmployee, i);
		if(employee->id == idToGet)
		{
			employee=ll_get(pArrayListEmployee, i);
			do
			{
				puts("Este es el empleado que desea modificar:");
				printf("%d,%s,%d,%d\n", employee->id,
										employee->nombre,
										employee->horasTrabajadas,
										employee->sueldo);
				getIntNumber(&option, "Ingrese\n1-SI desea modificar:\n2-NO desea modificar:\n",
									"Error opcion invalida", 1, 2, ATTEMPS);
				switch(option)
				{
				case 1:
				do
				{
					getIntNumber(&subOption, "Ingrese:\n1-Modificar nombre:\n2-Modificar horas trabajadas:\n"
										  "3-Modificar sueldo:\n4-Salir:\n",
										"Error opcion invalida", 1, 4, ATTEMPS);
				switch(subOption)
				{
					case 1:
						getStringChar(auxNombre, "Ingrese el nuevo nombre:\n",
									 "Error ingrese caracteres validos", NAMETAM, ATTEMPS);
						employee_setNombre(employee, auxNombre);
						break;
					case 2:
						getIntNumber(&auxHorasTrabajadas, "Ingrese horas trabajadas:",
								"Error ingrese un horario valido", 1, 30000, ATTEMPS);
						employee_setHorasTrabajadas(employee, auxHorasTrabajadas);
						break;
					case 3:
						getIntNumber(&auxSueldo, "Ingrese el sueldo:",
											"Error sueldo valido", 1, 300000, ATTEMPS);
						employee_setSueldo(employee, auxSueldo);
						break;
				}
				}while(subOption!=4);
				break;
				}
			}while(option!=2);

		}
	}

    return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* employee;
	int rtn=-1;
	int idToGet;
	int i;
	int len;
	int option;

	setbuf(stdout,NULL);
	puts("Ingrese el ID del empleado:");
	scanf("%d", &idToGet);

	len=ll_len(pArrayListEmployee);
	for(i=0;i<len;i++)
	{
		employee=ll_get(pArrayListEmployee, i);
		if(employee->id == idToGet)
		{
			employee=ll_get(pArrayListEmployee, i);

			puts("Este es el empleado que desea eliminar:");
			printf("%d,%s,%d,%d\n", employee->id,
									employee->nombre,
									employee->horasTrabajadas,
									employee->sueldo);
			getIntNumber(&option, "Ingrese\n1-SI desea eliminar:\n2-NO desea eliminar:\n",
								"Error opcion invalida", 1, 2, ATTEMPS);
			if(option==1)
			{
				puts("Empleado removido con exito");
				ll_remove(pArrayListEmployee, i);
				break;
			}else
			{
				puts("Operacion cancelada");
			}
		}
	}
    return rtn;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int rtn=-1;
	int len;

	if(pArrayListEmployee != NULL)
	{
		len=ll_len(pArrayListEmployee);
		employee_showEmployee(pArrayListEmployee, 0, len);
		rtn=1;
	}
	puts("Final");
    return rtn;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	LinkedList* listEmployeesaux;
	int option;
	int parameter=0;
	listEmployeesaux = ll_clone(pArrayListEmployee);
	getIntNumber(&option, "Indique como organizar:\n1. Por ID:\n2. Por Nombre:\n3. Por Horas Trabajadas:\n"
				"4. Por Sueldo:\n",
				"Error opcion invalida", 1, 4, ATTEMPS);
	switch(option)
	{
	case 1:
		parameter=employee_compareParameter("Indique el modo:\n1. Menor a mayor\n2. Mayor a menor\n");
		ll_sort(listEmployeesaux, employee_comparebyId, parameter);
		controller_ListEmployee(listEmployeesaux);
		break;
	case 2:
		parameter=employee_compareParameter("Indique el modo:\n1. (Z-A)\n2. (A-Z)\n");
		ll_sort(listEmployeesaux, employee_comparebyName, parameter);
		controller_ListEmployee(listEmployeesaux);
		break;
	case 3:
		parameter=employee_compareParameter("Indique el modo:\n1. Menor a mayor(no funciona)\n2. Mayor a menor\n");
		ll_sort(listEmployeesaux, employee_comparebyHoursWorked, parameter);
		controller_ListEmployee(listEmployeesaux);
		break;
	case 4:
		parameter=employee_compareParameter("Indique el modo:\n1. Menor a mayor(no funciona)\n2. Mayor a menor\n");
		ll_sort(listEmployeesaux, employee_comparebySalary, parameter);
		controller_ListEmployee(listEmployeesaux);
		break;
	}
	ll_deleteLinkedList(listEmployeesaux);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	LinkedList* listEmployeesaux;
	Employee* employees;
	FILE *pFile;
	int rtn=-1;
	int i;
	int min=0;
	int max=0;
	int len;
	max=ll_len(pArrayListEmployee);
	min = employee_minLenghtList(path);
	min=min-1;

	listEmployeesaux = ll_subList(pArrayListEmployee,min,max);
	len=ll_len(listEmployeesaux);
	pFile=fopen(path, "w");
	puts("Nuevos empleados: ");
	employee_showEmployee(listEmployeesaux, min, len);
	ll_deleteLinkedList(listEmployeesaux);
	for(i=0; i<max; i++)
	{
		employees=ll_get(pArrayListEmployee, i);
		fprintf(pFile,"%d,%s,%d,%d\n", employees->id,
								employees->nombre,
								employees->horasTrabajadas,
								employees->sueldo);
		rtn=0;
	}
    return rtn;
}


/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	LinkedList* listEmployeesaux;
	Employee* employees;
	FILE *pFile;
	int rtn=-1;
	int i;
	int min=0;
	int max=0;
	int len;
	max=ll_len(pArrayListEmployee);
	min = employee_minLenghtList(path);
	min=min-1;

	listEmployeesaux = ll_subList(pArrayListEmployee,min,max);
	len=ll_len(listEmployeesaux);
	pFile=fopen(path, "wb");
	puts("Nuevos empleados: ");
	employee_showEmployee(listEmployeesaux, min, len);
	ll_deleteLinkedList(listEmployeesaux);
	for(i=0; i<max; i++)
	{
		employees=ll_get(pArrayListEmployee, i);
		fwrite(employees, sizeof(Employee), 1, pFile);
		rtn=0;
	}

    return rtn;
}

