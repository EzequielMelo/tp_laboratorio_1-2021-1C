/*
 ============================================================================
 Name        : Calculadora.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Calculadora in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcionesCalculadora.h"

int main()
{
    int opcion;
    int operandoA=0;
    int operandoB=0;
    int respuestaSuma;
    int respuestaResta;
    float respuestaDivision;
    int respuestaMultiplicacion;
    long int respuestaFactorialA;
    long int respuestaFactorialB;

    do{
        printf("1. Ingresar 1er operando: A=%d", operandoA);
        printf("\n2. Ingresar 2do operando: B=%d", operandoB);
        printf("\n3. Calcular todas las operaciones: ");
        printf("\n4. Informar resultados: ");
        printf("\n5. Salir: ");
        printf("\nIngrese una opcion: \n");
        setbuf(stdout, NULL);
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            operandoA=operandos("Ingrese el operando A: ");
        break;
        case 2:
            operandoB=operandos("Ingrese el operando B: ");
        break;
        case 3:
            respuestaSuma=suma(operandoA, operandoB);
            respuestaResta=resta(operandoA, operandoB);
            respuestaDivision=division(operandoA, operandoB);
            respuestaMultiplicacion=multiplicacion(operandoA, operandoB);
            respuestaFactorialA=factorial(operandoA);
            respuestaFactorialB=factorial(operandoB);
            printf("Calculo completado\n");
        break;
        case 4:
            printf("La suma de los operandos %d + %d es: %d\n",operandoA, operandoB, respuestaSuma);
            printf("La resta de los operandos %d - %d es: %d\n",operandoA, operandoB, respuestaResta);
            if(operandoB==0)
            {
                printf("No se puede dividir por 0 cero\n");
            }else
            {
                printf("La division de los operandos %d / %d es: %.2f\n",operandoA, operandoB, respuestaDivision);
            }
            printf("La multiplicacion de los operandos %d * %d es: %d\n",operandoA, operandoB, respuestaMultiplicacion);
            if(operandoA<0 || operandoB<0)
            {
                printf("No se puede obtener el factorial de un numero negativo\n");
            }else
            {
                printf("El factorial de %d es: %ld y de %d es: %ld\n", operandoA, respuestaFactorialA, operandoB, respuestaFactorialB);
            }

        break;
        }
    system ("pause");
    system ("cls");

    }while(opcion!=5);
    return 0;
}
