#define _CRT_SECURE_NO_DEPRECATE

#include "myArray.h"
#include <stdio.h>
#include <stdlib.h>

/* UTILITY */
void printMyArray(myArrayElement* v, int dim)
{
	if (dim < 0) //Gestione errore
	{
		printf("Errore nella funzione printMyArray\t(Dimensione array negativa?)\n");
		return;
	}


	if (dim == 0) //Caso base
		return;
	else
	{
		dim--;
		printMyArray(v, dim);
		printMyArrayElement(v[dim]);
		return;
	}
}

//Funzione proxy
myArrayElement* readMyArrayFromFile(FILE* fp, int* vDim)
{
	return readMyArrayFromFileR(fp, 0, vDim);
}

//Funzione vera e propria
myArrayElement* readMyArrayFromFileR(FILE* fp, int counter, int* vDim)
{
	myArrayElement* result;
	myArrayElement temp;
	ReadCode code;

	code = readMyArrayElement(fp, &temp);
	if (code == ERROR) //CASO BASE
	{
		result = (myArrayElement*)malloc(sizeof(myArrayElement) * counter);
		if (result == NULL) 
		{
			printf("Errore nell'allocazione della memoria nella funzione readMyArrayFromFile\n");
			*vDim = 0;
		}
		else *vDim = counter;
	}
	else if (code == IGNORE) //CASO SECONDARIO
		result = readMyArrayFromFileR(fp, counter, vDim);
	else //SCRITTURA DELL'ARRAY
	{
		result = readMyArrayFromFileR(fp, counter + 1, vDim);
		if (counter < (*vDim))
			result[counter] = temp;

	}
	return result;
}

int trovaPosArray(myArrayElement el, myArrayElement* v, int dim)
{
	int pos = -1;
	if (dim < 0) //Gestione errore
	{
		printf("Errore nella funzione trovaPos\t(Dimensione negativa? )\n");
		return pos;
	}


	if (dim == 0) //Caso base
		return pos;
	else
	{
		dim--;
		pos = trovaPosArray(el, v, dim);
		if (pos == -1 && equalsMyArrayElement(v[dim], el))
			pos = dim;

		return pos;
	}
}

/* ORDINAMENTO */
void scambia(myArrayElement* a, myArrayElement* b)
{
	myArrayElement c;
	c = *a;
	*a = *b;
	*b = c;
}

int trovaPosMax(myArrayElement v[], int dim)
{
	int i, posMax = 0;

	for (i = 1; i < dim; i++)
		if (compareMyArrayElement(v[posMax], v[i]) < 0)
			posMax = i;

	return posMax;
}

void naiveSort(myArrayElement v[], int dim) {

	int p;

	while (dim > 1) {
		p = trovaPosMax(v, dim);
		if (p < dim - 1)
			scambia(&v[p], &v[dim - 1]);

		dim--;
	}

}

void bubbleSort(myArrayElement v[], int dim) {
	int i, ordinato = 0;

	while (dim > 1 && !ordinato) {
		ordinato = 1;
		for (i = 0; i < dim - 1; i++)
			if (compareMyArrayElement(v[i], v[i + 1]) > 0)
			{
				scambia(&v[i], &v[i + 1]);
				ordinato = 0;
			}
		dim--;
	}
}

void insertSort(myArrayElement v[], int dim) {
	int k;
	for (k = 1; k < dim; k++)
		insOrd(v, k);
}

void insOrd(myArrayElement v[], int pos) {

	int i = pos - 1;
	myArrayElement x = v[pos];

	while (i >= 0 && (compareMyArrayElement(x, v[i]) < 0)) {
		v[i + 1] = v[i]; /* crea lo spazio */
		i--;
	}

	v[i + 1] = x; /* inserisce l’elemento */
}

void mergeSort(myArrayElement v[], int first, int last)
{
	myArrayElement* vout;
	
	vout = (myArrayElement*)malloc(sizeof(myArrayElement) * (1 + last - first));
		
	if (vout == NULL)
		printf("Errore nell'allocazione di vout nella merge sort");
	
	else {
		mergeSortR(v, first, last, vout);
		free(vout);
	}

}
void mergeSortR(myArrayElement v[], int first, int last, myArrayElement vout[]) {

	int mid;

	if (first < last) {
		mid = (last + first) / 2;
		mergeSortR(v, first, mid, vout);
		mergeSortR(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}

void merge(myArrayElement v[], int pos1, int pos2, int fine, myArrayElement vout[]) {

	int i = pos1, j = pos2, k = pos1;

	while (i <= pos2 - 1 && j <= fine) {
		if (compareMyArrayElement(v[i], v[j]) < 0)
			vout[k] = v[i++];
		else
			vout[k] = v[j++];
		k++;
	}

	while (i <= pos2 - 1)
	{
		vout[k] = v[i++];
		k++;
	}

	while (j <= fine)
	{
		vout[k] = v[j++];
		k++;
	}
	for (i = pos1; i <= fine; i++) v[i] = vout[i];
}

void quickSort(myArrayElement a[], int dim)
{
	quickSortR(a, 0, dim - 1);
}

void quickSortR(myArrayElement a[], int iniz, int fine)
{
	int i, j, iPivot;
	myArrayElement pivot;

	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		pivot = a[iPivot];
		do /* trova la posizione del pivot */
		{
			while (i < j && (compareMyArrayElement(a[i], pivot) <= 0)) i++;
			while (j > i && (compareMyArrayElement(a[j], pivot) >= 0)) j--;
			if (i < j) scambia(&a[i], &a[j]);
		} while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && (!equalsMyArrayElement(a[i], a[iPivot])))
		{
			scambia(&a[i], &a[iPivot]);
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			quickSortR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			quickSortR(a, iPivot + 1, fine);
	} /* (iniz < fine) */
}




