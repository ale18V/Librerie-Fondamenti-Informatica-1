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
#include "myList.h"

/* OPERAZIONI PRIMITIVE */
list  emptylist(void)		/* costruttore lista vuota */
{
	return NULL;
}

boolean  empty(list l)	/* verifica se lista vuota */
{
	if (l == NULL)
		return True;
	else
		return False;
}

list  cons(myListElement e, list l)
{
	list t;       /* costruttore che aggiunge in testa alla lista */
	t = (list)malloc(sizeof(item));
	if (t == NULL)
	{
		printf("La malloc della funzione cons non è andata a buon fine\n");
		return l;
	}
	else {
		t->value = e;
		t->next = l;
		return(t);
	}
}

myListElement head(list l) /* selettore testa lista */
{
	if (empty(l)) {
		printf("La lista fornita alla funzione head è vuota\n");
		exit(-2);
	}
	else return (l->value);
}

list  tail(list l)         /* selettore coda lista */
{
	if (empty(l)) {
		printf("La lista fornita alla funzione tail è vuota\n");
		exit(-1);
	}
	else return (l->next);
}



/* UTILITY */
void printMyList(list l)
{
	if (empty(l))
		return;
	else
	{
		printMyListElement(head(l));
		printMyList(tail(l));
		
		return;
	}


}

list readMyListFromFile(FILE* fp)
{
	list result;
	myListElement temp;
	ReadCode code;

	result = emptylist();
	while ((code = readMyListElement(fp, &temp)) != ERROR)
		if(code == OK)
			result = cons(temp, result); //Se code == IGNORE non fa nulla

	return result;
}

void freelist(list l) {
	if (empty(l))
		return;
	else {
		freelist(tail(l));
		free(l);
	}
	return;
}

boolean member(myListElement el, list l)
{
	int pos = trovaPosList(el, l);
	if (pos == -1)
		return False;
	else
		return True;

}

void scambiaL(list l, int posElement1, int posElement2)
{
	myListElement temp;
	myListElement* e1 = getPointerToElement(l, posElement1);
	myListElement* e2 = getPointerToElement(l, posElement2);

	temp = *e1;
	*e1 = *e2;
	*e2 = temp;
}

void invertiLista(list l)
{
	int last = getLengthOfList(l) - 1;
	int first = 0;
	while (first < last)
	{
		scambiaL(l, first, last);
		first++;
		last--;
	}
}

int getLengthOfList(list l)
{
	int i = 0;
	while (!empty(l))
	{
		i++;
		l = tail(l);
	}
	return i;
}

list subList(list l, int startPos)
{
	list result;
	int counter = 0;

	result = emptylist();
	while (!empty(l) && counter < startPos)
	{
		counter++;
		l = tail(l);
	}
	if (counter == startPos)
		result = l;

	return result;
}

/*
* Sposta un nodo della lista dalla oldPos alla newPos.
* Il nodo nella posizione di destinazione viene spostato verso la coda e
* diventa il successivo del nodo da spostare
*/
void moveElement(list* l, int oldPosElement, int newPosElement)
{
	item* elementToMove;
	item* insertionPoint;
	item* deletionPoint;
	if (oldPosElement != newPosElement) {
		if (oldPosElement == 0) //La lista ora dovrà puntare al secondo elemento
		{
			elementToMove = *l;
			insertionPoint = subList(*l, newPosElement - 1);

			//Inserisci
			elementToMove->next = insertionPoint->next;
			insertionPoint->next = elementToMove;

			//Elimina
			*l = tail(*l);
		}
		else if (newPosElement == 0)
		{
			deletionPoint = subList(*l, oldPosElement -1);
			elementToMove = tail(deletionPoint);

			//Elimina
			deletionPoint->next = elementToMove->next;

			//Inserisci
			elementToMove->next = *l;
			*l = elementToMove;
		}
		else
		{
			deletionPoint = subList(*l, oldPosElement - 1);
			insertionPoint = subList(*l, newPosElement-1);
			elementToMove = deletionPoint->next;

			//Elimina
			deletionPoint->next = elementToMove->next;

			//Inserisci
			elementToMove->next = insertionPoint->next;
			insertionPoint->next = elementToMove;
		}
	}
	
}



/* ALGORITMI DI RICERCA */

//Funziona anche se viene fornita la lista nulla oppure un elemento non appartenente alla lista
int trovaPosList(myListElement el, list l)
{
	int pos = 0;
	boolean trovato = False;
	while (!empty(l) && !trovato)
	{
		if (equalsMyListElement(el, head(l)))
			trovato = True;

		else pos++;

		l = tail(l);
	}
	if (!trovato)
		pos = -1;

	return pos;
}

myListElement* getPointerToElement(list l, int posElement)
{
	int i = 0;
	myListElement* result = NULL;
	if (i >= 0) {
		while (!empty(l) && i <= posElement)
		{
			if (i == posElement)
				result = &(l->value);
			i++;
			l = tail(l);
		}
	}

	return result;
}

myListElement getElement(list l, int posElement)
{
	myListElement* result;
	result = getPointerToElement(l, posElement);
	return (*result);
}

int trovaPosMinList(list l)
{
	myListElement min;
	myListElement temp;
	int posMin = 0;
	int i = 1;
	if (!empty(l))
	{
		min = head(l);
		l = tail(l);
		while (!empty(l))
		{
			temp = head(l);
			if (compareMyListElement(min, temp) > 0)
			{
				min = temp;
				posMin = i;
			}
			i++;
			l = tail(l);

		}
	}
	return posMin;
}




/* ALGORITMI DI ORDINAMENTO */

void naiveSortList(list l)
{
	int i = 0;
	int posMin = 0;

	if (empty(l)) //Se la lista è vuota non c'è nulla da ordinare
		return;
	else
	{
		//Trova il minimo della lista
		posMin = trovaPosMinList(l);

		//Metti il minimo in testa alla lista
		if (posMin > 0)
			scambiaL(l, 0, posMin);

		//Ripeti sulla sua coda
		naiveSortList(tail(l));
	}

}

void bubbleSortList(list l)
{
	/*
	* Al contrario del bubble sort normale si parte dal fondo a far salire in testa gli elementi minori.
	* Questo perchè è facile passare a una funzione la coda della lista 
	* mentre è laborioso passare una sottolista non contenente l'ultimo elemento della coda.
	*/
	

	list temp = l;
	boolean ordinato = True;
	int i = 0;

	if (empty(l)) //Caso base: se la lista è vuota non c'è nulla da ordinare
		return;
	else
	{
		//Manda il minimo nella testa della lista
		ordinato = bubbleSortListR(l);

		//Se non è ordinato ripeti il bubble sort sulla coda della lista
		if (ordinato == False)
			bubbleSortList(tail(l));
		else
			return;
	}
}

boolean bubbleSortListR(list l)
{
	list temp = l;
	myListElement elSuccessivo, elPrecedente;
	boolean ordinato;

	if (empty(tail(temp))) //Caso base: è rimasto un solo elemento non c'è nulla da confrontare
	{
		ordinato = True;
	}
	else
	{
		elSuccessivo = head(temp);
		temp = tail(temp);
		elPrecedente = head(temp); //elPrecedente sta più in fondo alla lista rispetto a elSuccessivo

		//Inizia a confrontare gli elementi dal fondo
		ordinato = bubbleSortListR(temp);

		//Confronta posCurrentElement due elementi e manda verso la testa il minore
		if (compareMyListElement(elPrecedente, elSuccessivo) < 0)
		{
			//Se il precedente è minore del successivo scambiali
			scambiaL(l, 0, 1);
			ordinato = False;
		}
	}
	return ordinato;
}

void insertSortList(list l)
{
	if (empty(tail(l)))
		return;
	else
	{
		//Chiamare prima la insertSort sulla coda fa in modo che nel proseguio la coda sia ordinata.
		//Infatti la coda verrà ordinata dalla insertSortR per prima.
		insertSortList(tail(l)); 
		insertSortListR(l);
		return;
	}
}

//Mette la testa della lista nella posizione corretta.
//La coda deve essere già ordinata.
void insertSortListR(list l)
{
	myListElement elementToSort;
	myListElement nextElement;
	boolean ordinato = False;

	while (!empty(tail(l)) && !ordinato)
	{
		//Prende l'elemento da ordinare
		elementToSort = head(l);

		//Prende l'elemento successivo
		nextElement = head(tail(l));
		if (compareMyListElement(elementToSort, nextElement) > 0)
			scambiaL(l, 0, 1); //L'elemento da ordinare risale se è maggiore
		else
			ordinato = True; //Altrimenti l'elemento è nella sua giusta posizione e finisce il ciclo

		l = tail(l);
	}
	

}

//Insert sort normale, lavora nello stesso verso in cui lavorerebbe con un'array.
//Tuttavia cambia le posizioni dei nodi 
//Quindi se più liste condividono gli stessi nodi sei fottuto
void insertSortList2(list* l)
{
	int length = getLengthOfList(*l);
	int i = 0;
	for (i = 1; i < length; i++) 
		 insertSortList2R(l, i); //Ordina la sottolista che parte dalla testa e contenente i+1 elementi
}

void insertSortList2R(list *l, int posElementToBeSorted)
{
	myListElement elementToBeSorted, currentElement;
	int posCurrentElement;
	boolean isOrdinato = False;

	elementToBeSorted = head(subList(*l, posElementToBeSorted));
	posCurrentElement = posElementToBeSorted - 1;

	while (posCurrentElement >= 0 && !isOrdinato) 
	{//Ripeti finchè rimangono elementi da confrontare e non hai trovato un elemento minore all'elemento da ordinare
		
		currentElement = getElement(*l, posCurrentElement);  //Prendi il prossimo elemento da confrontare
		if (compareMyListElement(elementToBeSorted, currentElement) < 0) //Controlla se tale elemento è minore dell'elemento da ordinare
		{
			posCurrentElement--;
			isOrdinato = False;
		}
		else
			isOrdinato = True;
	}
	//Quando hai finito inserisci l'elemento da ordinare nella giusta posizione
	//Nota che la moveElement non fa nulla se la posizione di partenza è la stessa di destinazione
	moveElement(l, posElementToBeSorted, posCurrentElement + 1); 
}
//
//list insord_p(myListElement el, list l) {
//	list pprec = NULL, patt = l, paux;
//	int trovato = 0;
//
//	while (patt != NULL && !trovato) {
//-		if (el.costo > patt->value.costo)
//			trovato = 1;
//		else {
//			pprec = patt;
//			patt = patt->next;
//		}
//	}
//	paux = (list)malloc(sizeof(item));
//	paux->value = el;
//	paux->next = patt;
//	if (patt == l)
//		return paux;
//	else {
//		pprec->next = paux;
//		return l;
//	}
//}