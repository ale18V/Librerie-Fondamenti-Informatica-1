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
#include "myListElement.h"

//MODIFICA QUESTA
int compareMyListElement(myListElement e1, myListElement e2)
{
	int result;

	result = 1;

	return result;
}

//EQUALS OK
boolean equalsMyListElement(myListElement e1, myListElement e2)
{
	if (compareMyListElement(e1, e2) == 0)
		return True;
	else
		return False;
}

//MODIFICA QUESTA
void printMyListElement(myListElement e)
{
	//Stampa elemento
	printf("\n");
	return;
}

//DA MODIFICARE
ReadCode readMyListElement(FILE* fp, myListElement* dest)
{
	myListElement temp;
	ReadCode resultCode;
	if (/* ... */ 1)
	{
		//*dest = temp;
		resultCode = OK;
	}
	else
		resultCode = ERROR;


	return resultCode;
}