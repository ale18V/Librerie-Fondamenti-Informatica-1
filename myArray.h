#pragma once
/*
*	MATRICOLA:	0001044234
*	NOME:		Alessandro
*	COGNOME:	Bombarda
*
*	PROVA:
*/
#ifndef MYARRAY_H
#define MYARRAY_H
#include "commondef.h"
#include "myArrayElement.h"

/* UTILITY */

//Tutte le funz. utility sono RICORSIVE

/*
* Stampa un array
* @FUNZIONE RICORSIVA
* @Parametro v: Array da stampare
* @Parametro dim: Dimensione dell'array da stampare
*/
void printMyArray(myArrayElement* v, int dim);

/*
* Riempie un array leggendo le istanze da un file. 
* Se la malloc fallisce stampa l'errore e ritorna un array NULL con dimensione 0
* @FUNZIONE RICORSIVA
* @parametro fp: Puntatore al file da leggere
* @Parametro vDim: Dimensione logica dell'array restituito
* 
* 
*/
myArrayElement* readMyArrayFromFile(FILE* fp,  int* vDim); //Funzione proxy

myArrayElement* readMyArrayFromFileR(FILE* fp, int counter, int* vDim); //Funzione vera e propria

/*
* Restituisce la posizione della prima occorrenza di un elemento a partire dall'indice 0. 
* Restituisce -1 se l'elemento non è presente
* @FUNZIONE RICORSIVA
* @Parametro el: Elemento da cercare
* @Parametro v: Array in cui cercare l'elemento
* @Parametro dim: Dimensione logica dell'array
*/
int trovaPosArray(myArrayElement el, myArrayElement* v, int dim);


/* ORDINAMENTO */
void	scambia(myArrayElement* a, myArrayElement* b);

int		trovaPosMax(myArrayElement v[], int dim);

void	naiveSort(myArrayElement v[], int dim);

void	bubbleSort(myArrayElement v[], int dim);

void	insertSort(myArrayElement v[], int dim);

void	insOrd(myArrayElement v[], int pos);

/*
* Ordina un sottoarray dell'array v[].
* Il sottoarray comincia dall'indice first e termina nell'indice di last.
* Per ordinare l'intero v[] dare come parametri (v, 0, dim-1)
*/
void	mergeSort(myArrayElement v[], int first, int last);

void	mergeSortR(myArrayElement v[], int first, int last, myArrayElement vout[]);

void	merge(myArrayElement v[], int i1, int i2, int fine, myArrayElement vout[]);

void	quickSortR(myArrayElement a[], int iniz, int fine);

void	quickSort(myArrayElement a[], int dim);


#endif // !MYARRAY_H


