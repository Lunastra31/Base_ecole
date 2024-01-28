#include "Date.h"
#include <stdlib.h>
#include <string.h>

#ifndef ELEVE_H
#define ELEVE_H

//Définition de la structure d'un élève
typedef struct Eleve
{
    char Nom[50]; //Nom de l'élève
    char Prenom[50]; //Prénom de l'élève
    struct tm Naissance; //Date de naissance de l'élève
    int age; //L'âge de l'élève
    //int Note; paramètre optionnel
}Eleve_t;

// Fonction de saisie d'un élève
void SaisirEleve (Eleve_t * Eleve);

// Fonction d'affichage d'un élève
void AfficherEleve (Eleve_t Eleve);

// Fonction de saisie d'un tableau d'élève
void SaisirTabEleve (Eleve_t TabEleve[], int * nbr);

// Fonction d'affichage d'un tableau d'élève
void AfficherTabEleve (Eleve_t TabEleve[], int nbr);

// Calculer l'âge selon l'année de naissance de l'élève
int CalculerAge (Eleve_t Eleve);

// Fonction de test pour vérifier CalculerAge
void AfficherAge (Eleve_t Eleve);

// Affecter un niveau (CP, CE1, CE2, CM1, CM2)selon l'année de naissance de l'élève
char AssignerNiveau (Eleve_t Eleve);

// Fonction pour modifier les informations d'un élève
void ModifierEleve (Eleve_t * Eleve);

#endif