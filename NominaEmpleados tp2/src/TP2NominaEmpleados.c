/*
 ============================================================================
 Name        : TP2NominaEmpleados.c
 Author      : Ezequiel Melo
 Version     :
 Copyright   : Your copyright notice
 Description : Trabajo practico N�2 UTN 2021
 ============================================================================
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"
#include "Employee.h"

#define SIZE 1000
#define TRUE 1
#define FALSE 0
#define LIMITE_BUFFER 4096
#define LIMIT_CHARACTERS 51
#define ATTEMPS 2

int main(void)
{
	int id;
	char name[LIMIT_CHARACTERS];
	char lastName[LIMIT_CHARACTERS];
	float salary;
	int sector;

	Employee arrayEmployees[SIZE];
	initEmployees(arrayEmployees, SIZE);

	int option;
	int subOption;
	int auxIndex;
	int answer;
	int order;
	int r;

	do
	{
		setbuf(stdout,NULL);
		answer = utn_getEntero(&option,
				"Seleccione una opcion\n1-ALTA empleado\n2-MODIFICAR empleado\n3-BAJA empleado\n4-INFORMAR\n5-SALIR del programa",
				"Opcion INCORRECTA\nIngrese una opcion valida\n",
				1, 5 ,ATTEMPS);
		if(!answer)
		{
			switch(option)
			{
			case 1:
				r = addEmployee(arrayEmployees, SIZE, id, name, lastName, salary, sector);
				if(r != -1)
				{
					printf("Empleado Cargado con exito\n");
				}else
				{
					printf("ERROR lista completa no se pueden a�adir mas empleados\n");
				}
			break;
			case 2:
				auxIndex = findEmployeebyId(arrayEmployees, SIZE, id);
				if(searchTakenPosition(arrayEmployees, SIZE) != FALSE &&
				   !utn_getEntero(&id,"Ingrese el id del empleado que desea MODIFICAR\n",
				   "Error id incorrecto\n",
				   0, 1000, 3) &&
				   printEmployee(arrayEmployees[id-1]) == 0 &&
				   !utn_getEntero(&subOption, "Que desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector","opcion INCORRECTA\n",1,4,ATTEMPS))
				{
					switch(subOption)
					{
					case 1:
						if(!utn_getString(name,
								"Escriba el nuevo nombre: \n",
								"Error el NOMBRE ha superado el limite de caracteres\n",
								LIMIT_CHARACTERS, ATTEMPS))
						{
							strcpy(arrayEmployees[auxIndex].name, name);
						}
					break;
					case 2:
						if(!utn_getString(lastName,
								"Escriba el nuevo apellido: \n",
								"Error el APELLIDO ha superado el limite de caracteres\n",
								LIMIT_CHARACTERS, ATTEMPS))
						{
							strcpy(arrayEmployees[auxIndex].lastName, lastName);
						}
					break;
					case 3:
						if(!utn_getFlotante(&salary,
								"Escriba el nuevo salario: \n",
								"Error el SALARIO incorrecto\n",
								0, 300000, ATTEMPS))
						{
							arrayEmployees[auxIndex].salary = salary;
						}
					break;
					case 4:
						if(!utn_getEntero(&sector,
								"Escriba el nuevo sector: \n",
								"Error el SECTOR incorrecto\n",
								0, 100, ATTEMPS))
						{
							arrayEmployees[auxIndex].sector = sector;
						}
					break;
					}
				}else
				{
					printf("ERROR primero debe haber un empleado ingresado\n");
				}
			break;
			case 3:
				if(searchTakenPosition(arrayEmployees, SIZE) != FALSE &&
					!utn_getEntero(&id,"Ingrese el id del empleado que desea ELIMINAR\n",
					"Error id incorrecto\n",
					0, 1000, ATTEMPS) &&
					printEmployee(arrayEmployees[id-1]) == 0 &&
					findEmployeebyId(arrayEmployees, SIZE, id) != -1 &&
					!removeEmployee(arrayEmployees, SIZE, id))
				{
					printf("Empleado removido con EXITO\n");
				}else
				{
					printf("ERROR primero debe haber un empleado ingresado\n");
				}
			break;
			case 4:
				if(searchTakenPosition(arrayEmployees, SIZE) != FALSE &&
				   !utn_getEntero(&subOption, "Que desea INFORMAR?\n1-Listado ORDENADO por APELLIDO\n2-Listado ORDENADO por SECTOR\n3-Salarios y sus PROMEDIOS","opcion INCORRECTA\n",1, 3, ATTEMPS))
				{
					switch(subOption)
					{
					case 1:
						utn_getEntero(&order,"Como desea ORDENAR los empleados?\n1-Ascendente(A a Z)\n2-Descendente (Z a A)","opcion INCORRECTA\n", 1, 2, ATTEMPS);
						sortEmployeesbyLastName(arrayEmployees, SIZE, order);
						printEmployees(arrayEmployees, SIZE);
					break;
					case 2:
						utn_getEntero(&order,"Como desea ORDENAR los empleados?\n1-Menor a mayor\n2-Mayor a menor","opcion INCORRECTA\n", 1, 2, ATTEMPS);
						sortEmployeesbySector(arrayEmployees, SIZE, order);
						printEmployees(arrayEmployees, SIZE);
					break;
					case 3:
						averageSalaryEmployee(arrayEmployees, SIZE);
					break;
					}
				}else
				{
					printf("ERROR primero debe haber un empleado ingresado\n");
				}
			break;
			}
		}
	}
	while(option!=5);
	return EXIT_SUCCESS;
}
