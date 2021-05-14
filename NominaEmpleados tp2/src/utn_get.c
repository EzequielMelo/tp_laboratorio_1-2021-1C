#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_get.h"

int utn_myGets(char* cadena, int longitud)
{
	int retorno = -1;
	char bufferString[52];
	if(cadena != NULL && longitud > 0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if(bufferString[strlen(bufferString)-1]=='\n')
			{
				bufferString[strcspn(bufferString,"\n\r")]= '\0';
			}
			if(strlen(bufferString) <= longitud)
			{
				strncpy(cadena,bufferString,longitud);
				retorno = 0;
			}
		}
	}

	return retorno;
}

int utn_getEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferInt);
			if(bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat >= minimo && bufferFloat <= maximo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

int utn_getString(char* pResultado, char* mensaje, char* mensajeError, int limite, int reintentos)
{
	int retorno = -1;
	char bufferString[LIMITE_BUFFER];
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && limite != 0 && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			if(utn_myGets(bufferString, LIMITE_BUFFER) == 0 &&
			   strnlen(bufferString, sizeof(bufferString)) <= limite)
			{
				strncpy(pResultado, bufferString, limite);
				retorno = 0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}
