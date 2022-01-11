# LibrerieMod2
Librerie per l'esame di programmazione di Fondamenti di Informatica T-1

Di seguito è presente la spiegazione di come usare le librerie.

Il file commondef.h contiene definizioni comuni a tutto il progetto, come per esempio il tipo boolean.

Per quanto riguarda gli array, sono presenti un file myArrayElement.h e un file myArray.h.
All'interno del file myArrayElement.h è definito il tipo dell'array, oltre alle funzioni di confronto, stampa e lettura per elementi di tale tipo.
Queste ultime funzioni ovviamente sono da scrivere all'occorrenza in quanto non è possibile scriverle prima di aver definito un tipo.
Le funzioni dichiarate in myArrayElement.h si trovano in myArrayElement.cpp .

Nel file myArray.h sono definite funzioni di comodità e funzioni per l'ordinamento di vettori dello stesso tipo definito in myArrayElement.h .
Tali funzioni sono implementate a partire delle funzioni definite in myArrayElement.cpp;
quindi per esempio la funzione printMyArray necessiterà che in myArrayElement.cpp sia stata scritta la funzione printMyArrayElement.

Un discorso esattamente uguale vale per le liste.
