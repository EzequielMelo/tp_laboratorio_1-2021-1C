/*
 * utn_get.h
 *
 *  Created on: 12 may. 2021
 *      Author: ezequ
 */

#ifndef UTN_GET_H_
#define UTN_GET_H_

#define SIZE 1000
#define TRUE 1
#define FALSE 0
#define LIMITE_BUFFER 4096
#define LIMIT_CHARACTERS 51
#define ATTEMPS 2

int utn_myGets(char*, int);
int utn_getEntero(int*, char*, char*, int, int, int);
int utn_getFlotante(float*, char*, char*, float, float, int);
int utn_getString(char*, char*, char*, int, int);

#endif /* UTN_GET_H_ */
