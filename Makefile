# Ceci est le compilateur choisi
Compilateur=gcc

#Cible principale
BaseEcole.exe : main.c Ecole.o Classe.o Eleve.o Date.o
	${Compilateur} $^ -o Ecole.exe 
	
#dependances

Ecole.o : Ecole.c Ecole.h Classe.o
	${Compilateur} -c Ecole.c 

Classe.o : Classe.c Classe.h Eleve.o 
	${Compilateur} -c Classe.c
	

Eleve.o : Eleve.c Eleve.h Date.o
	${Compilateur} -c Eleve.c

Date.o : Date.c Date.h
	${Compilateur} -c Date.c 

TestEcole.exe: TestEcole.c Date.o Eleve.o Classe.o Ecole.o
	${Compilateur} $^ -o $@

TestClasse.exe: TestClasse.c Date.o Eleve.o Classe.o
	${Compilateur} $^ -o $@

TestEleve.exe: TestEleve.c Date.o Eleve.o
	${Compilateur} $^ -o $@

TestDate.exe: TestDate.c Date.o
	${Compilateur} $^ -o $@

#cible fictive

tests : TestDate.exe TestEcole.exe TestEleve.exe TestClasse.exe

.PHONY : MrProper tests

MrProper :
	echo "ceci est une cible fictive"
	rm -f *.o

