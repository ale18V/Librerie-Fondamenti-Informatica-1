#pragma once
/*
*	MATRICOLA:	0001044234
*	NOME:		Alessandro
*	COGNOME:	Bombarda
*
*	PROVA:
*/
#ifndef MYLISTELEMENT_H
#define MYLISTELEMENT_H
#include <stdio.h>
#include "commondef.h"
/*

A meno che il tipo non sia primitivo
Inserisci la sua definizione in COMMONDEF.H */
typedef int myListElement;



/*
Restituisce <0	se	 e1 < e2
Restituisce  0	se	 e1 == e2
Restituisce >0	se	 e1 > e2	*/
int compareMyListElement(myListElement e1, myListElement e2);


/*
Restituisce True se e1 == e2
Restituisce False se e1 != e2	*/
boolean equalsMyListElement(myListElement e1, myListElement e2);


/*
Stampa una variabile di tipo myListElement	*/
void printMyListElement(myListElement e);

//DA MODIFICARE
ReadCode readMyListElement(FILE* fp, myListElement* dest);



#endif // !MYLISTELEMENT_H