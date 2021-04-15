/*
 * funcionesCalculadora.h
 *
 *  Created on: 13 abr. 2021
 *      Author: ezequiel melo
 */

#ifndef FUNCIONESCALCULADORA_H_
#define FUNCIONESCALCULADORA_H_

/** \brief Toma el numero que ingrese el usuario
 *
 * \param char[] Mensaje sobre cual parametro esta ingresando A/B
 * \return int Retorna el numero que ingreso el usuario
 *
 */
int operandos(char[]);

/*_______________________________________________________________________________________________*/

/** \brief Ejecuta la operacion sumar
 *
 * \param operandoA int Numero que se ingreso en primer lugar
 * \param operandoB int Numero que se ingreso en segundo lugar
 * \return int Retorna el resultado de la suma
 *
 */
int suma(int operandoA, int operandoB);

/*_______________________________________________________________________________________________*/

/** \brief Ejecuta la operacion matematica restar
 *
 * \param operandoA int Numero que se ingreso en primer lugar
 * \param operandoB int Numero que se ingreso en segundo lugar
 * \return int Retorna el resultado de la resta
 *
 */
int resta(int operandoA, int operandoB);

/*_______________________________________________________________________________________________*/

/** \brief Ejecuta la operacion matematica dividir
 *
 * \param operandoA int Numero que se ingreso en primer lugar
 * \param operandoB int Numero que se ingreso en segundo lugar
 * \return float Retorna el resultado de la division
 *
 */
float division(int operandoA, int operandoB);

/*_______________________________________________________________________________________________*/

/** \brief Ejecuta la operacion matematica multiplicar
 *
 * \param operandoA int Numero que se ingreso en primer lugar
 * \param operandoB int Numero que se ingreso en segundo lugar
 * \return int Retorna el resultado de la multiplicacion
 *
 */
int multiplicacion(int operandoA, int operandoB);

/*_______________________________________________________________________________________________*/

/** \brief Ejecuta la operacion matematica de obtener el factorial de un numero
 *
 * \param operando int Toma el operando ingresado
 * \return long int Retorna el factorial
 *
 */
long int factorial(int operando);


#endif /* FUNCIONESCALCULADORA_H_ */
