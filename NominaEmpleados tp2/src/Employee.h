/*
 * Employee.h
 *
 *  Created on: 12 may. 2021
 *      Author: Ezequiel Melo
 */

#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#define SIZE 1000
#define TRUE 1
#define FALSE 0
#define LIMITE_BUFFER 4096
#define LIMIT_CHARACTERS 51
#define ATTEMPS 2

typedef struct
{
	int id;
	char name[LIMIT_CHARACTERS];
	char lastName[LIMIT_CHARACTERS];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee[], int);

/** \brief busca las posiciones que estan libres
 * esta funcion busca en el array en el campo(isEmpty) todas las posiciones
 * que esten libres(TRUE) y retorna la posicion desde un index
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 */
int searchFreePosition(Employee[], int);

/** \brief busca las posiciones que estan ocupadas
 * esta funcion busca en el array en el campo(isEmpty) todas las posiciones
 * que esten ocupadas(FALSE) y suma en un contador para saber cuantas son
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 */
int searchTakenPosition(Employee[], int);

/** \brief pide datos al usuario
 * se encarga de pedir a traves de las funciones utn_get
 * los datos correspondientes al usuario
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 */
void askForEmployeeData(char[], char[], float*, int*);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 **/
int addEmployee(Employee*, int, int, char[], char[], float, int);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeebyId(Employee*, int, int);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee*, int, int);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeesbyLastName(Employee*, int, int);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployeesbySector(Employee*, int, int);

/** \ brief saca el promedio de todos los empleados
 * busca en todas la posiciones ocupadas(FALSE) contando los empleados y
 * sumando los salarios luego muestra el resultado de las operaciones
 * \param list Employee*
 * \param len int
 *
 */
int averageSalaryEmployee(Employee*, int);

/** \ brief busca, suma la cantidad y muestra los empleados que superan
 * el sueldo promedio
 * \param list Employee*
 * \param len int
 * \param averageSalary float
 */
int overAverageSalaryEmployee(Employee*, int, float);

/** \ brief muestra un empleado
 * el sueldo promedio
 * \param Employee
 */
int printEmployee(Employee);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
void printEmployees(Employee[], int);

#endif /* EMPLOYEE_H_ */
