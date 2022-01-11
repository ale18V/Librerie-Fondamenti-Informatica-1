#pragma once

#ifndef MYARRAYELEMENT_H
#define MYARRAYELEMENT_H
#include <stdio.h>
#include "commondef.h"

/*

A meno che il tipo non sia primitivo
Inserire la sua definizione in COMMONDEF.H */
typedef int myArrayElement;


/*
Restituisce <0	se	 e1 < e2
Restituisce  0	se	 e1 == e2
Restituisce >0	se	 e1 > e2	*/
int compareMyArrayElement(myArrayElement e1, myArrayElement e2);


/*
Restituisce True se e1 == e2
Restituisce False se e1 != e2	*/
boolean equalsMyArrayElement(myArrayElement e1, myArrayElement e2);


/*
Stampa una variabile di tipo myArrayElement */
void printMyArrayElement(myArrayElement e);

/*
Legge una variabile di tipo myArrayElement 
Restituisce OK se non ci sono errori
Restituisce ERROR se qualcosa va storto */
ReadCode readMyArrayElement(FILE* fp, myArrayElement* dest);




#endif // !MYARRAYELEMENT_H
