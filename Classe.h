#include "Eleve.h"

#ifndef CLASSE_H
#define CLASSE_H
#define MAXELEVE 25 //Nombre maximum d'élèves dans une classe

//Définition de la structure classe
typedef struct Classe
{
    char Nom[50]; //Nom de la classe ex : CPA ,CE2C...
    char NomProf[50]; //Nom du professeur référent
    char PrenomProf[50]; //Prénom du professeur référent
    int nbEleve; //Nombre d'élève dans la classe
    Eleve_t TabEleve [MAXELEVE]; //Tableau d'élève
}Classe_t;

// Fonction de saisie d'une classe
void SaisirClasse (Classe_t * Classe);

// Fonction d'affichage d'une classe
void AfficherClasse (Classe_t Classe);

// Fonction de saisie d'un tableau de classe
void SaisirTabClasse (Classe_t TabClasse[], int *nbr);

// Fonction d'affichage d'un tableau de classe
void AfficherTabClasse (Classe_t TabClasse[], int nbr);

// Fonction de saisie de la classe dans un fichier
void EcrireFprintfClasse (Classe_t * Classe, const char * filename);

#endif