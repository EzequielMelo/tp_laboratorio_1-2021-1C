#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_compareParameter(char* message);
int employee_comparebyId(void* emp1, void* emp2);
int employee_comparebyName(void* emp1, void* emp2);
int employee_comparebyHoursWorked(void* emp1, void* emp2);
int employee_comparebySalary(void* emp1, void* emp2);

int employee_minLenghtList(char* path);

void employee_showEmployee(LinkedList* pArrayListEmployee, int min, int max);

#endif // employee_H_INCLUDED
