/*
 * funcionesCalculadora.c
 *
 *  Created on: 13 abr. 2021
 *      Author: ezequiel melo
 */

#include <stdio.h>
#include <stdlib.h>

int operandos(char texto[])
{
    int dato;

    printf("%s", texto);
    setbuf(stdout,NULL);
    scanf("%d", &dato);

    return dato;
}

int suma(int operandoA, int operandoB)
{
    int respuestaSuma;

    respuestaSuma = operandoA + operandoB;

    return respuestaSuma;
}

int resta(int operandoA, int operandoB)
{
    int respuestaResta;

    respuestaResta = operandoA - operandoB;

    return respuestaResta;
}

float division(int operandoA, int operandoB)
{
    float respuestaDivision;

    respuestaDivision = (float)operandoA / (float)operandoB;

    return respuestaDivision;
}

int multiplicacion(int operandoA, int operandoB)
{
    int respuestaMultiplicacion;

    respuestaMultiplicacion = operandoA * operandoB;

    return respuestaMultiplicacion;
}

long int factorial(int operando)
{
    long int respuestaFactorial= 1;
    int i;

    for (i=operando; i>1; i--)
    {
        respuestaFactorial = respuestaFactorial * i;
    }

    return respuestaFactorial;
}
