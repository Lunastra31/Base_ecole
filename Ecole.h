#include "Classe.h"

#ifndef ECOLE_H
#define ECOLE_H
#define MAXCLASSE 15 // Nombre maximum de classes dans l'école

// Définition de la structure d'une classe
typedef struct Ecole
{
    char Nom[50]; //Nom de l'école ex : Collège Fou Fou Fou
    int nbClasse; //Nombre de classe dans l'école
    Classe_t TabClasse[MAXCLASSE]; //Tableau de classes
}Ecole_t;

// Fonction de Saisie d'une école
void SaisirEcole (Ecole_t *Ecole);

// Fonction d'affichage de l'école
void AfficherEcole (Ecole_t Ecole);

// Fonction de recherche de l'élève dans l'école
// l'indexClasse et l'indexEleve sont pensés pour garder les données de l'élève recherché
bool RechercherEleve(Ecole_t Ecole, int * indexClasse, int  *indexEleve);

void ModifierInfosEleve(Ecole_t Ecole);

// Fontion de création d'une classe
void CreerNewClasse(Ecole_t* Ecole);

// Fonction de création d'un élève
void NewEleve(Eleve_t newEleve);

// Fonction d'affichage dans un fichier lisible par la machine
void EcrireFwrite (Ecole_t *Ecole, const char * filename);

// Fonction de saisie des données du fichier lisible par la machine
void SaisirFread (Ecole_t *Ecole, const char * filename);

// Fonction d'affichage détaillé de toute l'école dans un fichier
void EcrireFprintfEcole (Ecole_t *Ecole, const char * filename);

// Fonction d'affichage de tous les élèves de l'école dans un fichier
void EcrireFprintfEleve (Ecole_t *Ecole, const char * filename);

// Fonction de saisie des données d'un fichier lisible par l'homme
void SaisirFscanf (Ecole_t *Ecole, const char * filename);

// Fonction de création d'une nouvelle classe (Non-Fonctionnel)
// Si la capacité de l'école est augmenté ce prototype de fonction servira à ouvrir une nouvelle classe
// void CreerNewClasse(Ecole_t* Ecole);

// Prototype de fonction pour équilibrer les classe
// bool EstClasseEquilibree(Classe_t Classe);

//Just FYI, in English, Niveau means Class and classe means section. Example: CP1- CP is class and 1 is a section.               
// void DistributeEleves(Ecole_t* Ecole);

// Function to check if the opening of a class is validated and distribute the pupils 
// void PassageAnneeScolaire(Ecole_t* Ecole);

#endif