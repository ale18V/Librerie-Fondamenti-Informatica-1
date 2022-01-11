#define _CRT_SECURE_NO_DEPRECATE
/*
*	MATRICOLA:	0001044234
*	NOME:		Alessandro
*	COGNOME:	Bombarda
*
*	PROVA:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myArrayElement.h"

//DA MODIFICARE
int compareMyArrayElement(myArrayElement e1, myArrayElement e2)
{
	int result;
	result = 1;

	return result;
}

//EQUALS OK MODIFICA LA COMPARE
boolean equalsMyArrayElement(myArrayElement e1, myArrayElement e2)
{
	if (compareMyArrayElement(e1, e2) == 0)
		return True;
	else
		return False;
}

//DA MODIFICARE
void printMyArrayElement(myArrayElement e1)
{
	//Stampa un elemento
	printf("\n");
	return;
}

//DA MODIFICARE
ReadCode readMyArrayElement(FILE* fp, myArrayElement* dest)
{
	myArrayElement temp;
	ReadCode resultCode;
	if (/*...*/ 1)
	{
		//*dest = temp;
		resultCode = OK;
	}
	else
		resultCode = ERROR;


	return resultCode;
}
