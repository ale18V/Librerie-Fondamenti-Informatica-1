#pragma once
/*
*	MATRICOLA:	0001044234
*	NOME:		Alessandro
*	COGNOME:	Bombarda
*
*	PROVA:
*/
#ifndef MYLIST_H
#define MYLIST_H
#include "commondef.h"
#include "myListElement.h"

typedef struct list_element {
	myListElement value;
	struct list_element* next;
} item;

typedef  item* list;



/* PRIMITIVE  */
list emptylist(void);
boolean empty(list);
list cons(myListElement, list);
myListElement head(list);
list tail(list);


/* UTILITY */

/*
* Funzione che stampa una lista in modo ricorsivo. 
* Stampa in ordine da testa a coda.
* @Parametro l: Lista da stampare
*/
void printMyList(list l);

/*
* Funzione che crea una lista leggendo i suoi elementi da un file
* @Parametro fp: Puntatore al file da leggere
*/
list readMyListFromFile(FILE* fp);


void freelist(list l);

/*
* Funzione che ritorna vero se un elemento appartiene alla lista, falso altrimenti
* @Parametro el: Elemento per cui verificare l'appartenenza
* @Parametro l: Lista in cui cercare l'elemento
*/
boolean member(myListElement el, list l);

/*
* Scambia il value di due nodi della lista.
* NOTA: l'elemento in testa è in posizione 0!
*/
void scambiaL(list l, int posElement1, int posElement2);

/*
* Restituisce il numero di elementi nella lista
*/
int getLengthOfList(list l); 

/*
* Inverte una lista
*/
void invertiLista(list l);
/*
* Cambia la posizione di un nodo all'interno della lista*/
void moveElement(list *l, int oldPosElement, int newPosElement);

/*
* Ritorna una sottolista di l, che inizia dalla posizione fornita come parametro
* NOTA: l'elemento in testa di l è in posizione 0!
*/
list subList(list l, int subListStartPos);


/* ALGORITMI DI RICERCA */

/*
* Restituisce la posizione della prima occorrenza di un elemento a partire dall'indice 0.
* Restituisce -1 se l'elemento non è presente
* @Parametro el: Elemento da cercare
* @Parametro l: Lista in cui cercare l'elemento
*/
int trovaPosList(myListElement el, list l);
/*
* Restituisce un puntatore al value di un nodo della lista.
* NOTA: l'elemento in testa è in posizione 0!
*/
myListElement* getPointerToElement(list l, int posElement);
/*
* Restituisce il value di un nodo della lista.
* NOTA: l'elemento in testa è in posizione 0!
*/
myListElement getElement(list l, int posElement);
/*
* Restituisce la posizione del minimo secondo il criterio della compareMyListElement.
* NOTA: la posizione dell'elemnto in testa è 0!
*/
int trovaPosMinList(list l);

/* ALGORITMI DI ORDINAMENTO */

void naiveSortList(list l);

void bubbleSortList(list l);
boolean bubbleSortListR(list l);

void insertSortList(list l);
void insertSortListR(list l);

//NON USARE se c'è structure sharing
void insertSortList2(list *l);
void insertSortList2R(list *l, int length);


//list insord_p(myListElement el, list l);

#endif // !MYLIST_H