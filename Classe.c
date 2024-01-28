#include<stdio.h>
#include<stdlib.h>

#include "Eleve.h"
#define MAXELEVE 25

typedef struct Classe
{
    char Nom[50];//exemple CPA, CE2C
    char NomProf[50];//il y a un seul enseignant
    char PrenomProf[50];
    int nbEleve;
    char Niveau[3];
    Eleve_t TabEleve [MAXELEVE];

}Classe_t;

//Fonction Saisir Classe
void SaisirClasse (Classe_t * Classe)
{
    //Nom de la classe
    printf("Entrez le nom de la classe :\n");
    scanf("%s" , Classe->Nom);

    //Nom et prénom du prof
    printf("Entrez le nom et le prénom de l'enseignant : \n");
    scanf("%s %s", Classe->NomProf , Classe->PrenomProf);

    //Saisie du Tableau d'Eleve
    SaisirTabEleve (Classe->TabEleve,&Classe->nbEleve);

}

//Fonction Afficher Classe
void AfficherClasse (Classe_t Classe){

    //Nom de la classe
    printf("Nom de la classe :%s\n" , Classe.Nom);

    //Nom du prof
    printf("Le nom et le prénom de l'enseignant : ""%s %s\n", Classe.NomProf , Classe.PrenomProf);

    //Nombre d'élève
    printf("Le nombre d'élèves : %d\n",Classe.nbEleve);

    //Saisie du Tableau d'Eleve
    AfficherTabEleve (Classe.TabEleve,Classe.nbEleve);
}

void SaisirTabClasse (Classe_t TabClasse[], int *nbr)
{   
    //Saisie d'un tableau de classes (nombre de classes)
    printf("Saisir le nombre de classes : \n");
    scanf("%d", nbr);
    for(int i=0; i<*nbr;i++)
    {
        SaisirClasse(&TabClasse[i]);
    }
}

void AfficherTabClasse (Classe_t TabClasse[], int nbr)
{
    for(int i=0; i<nbr;i++)
    {   
        //Affichage d'un tableau de classes 
        printf("la classe %d : \n", i+1);
        AfficherClasse(TabClasse[i]);
        printf("\n"); //retour à la ligne pour plus de lisibilité
    }
}

void EcrireFprintfClasse (Classe_t * Classe, const char * filename)
{
    FILE* ptr;
    int j= 0;// compteur d'élèves
    ptr = fopen(filename, "w");
    if(ptr==NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    
        // Affiche le nom de la classes
        fprintf(ptr,"%s\n",Classe->Nom);

        // Affiche le nom et prénom du professeur
        fprintf(ptr,"%s %s\n",Classe->NomProf, Classe->PrenomProf);

        // affiche le nombre d'élèves
        fprintf(ptr,"%d\n", Classe->nbEleve);
        
        // Boucle sur le nombre d'élèves
        for(j=0;j<Classe->nbEleve;j++)
        {
            
            // Affiche les informations de chaque élève (Nom, Prénom et date de naissance)
            fprintf(ptr,"%s %s %d %d %d\n",Classe->TabEleve[j].Nom,Classe->TabEleve[j].Prenom,
            Classe->TabEleve[j].Naissance.tm_mday,
            Classe->TabEleve[j].Naissance.tm_mon+1,
            Classe->TabEleve[j].Naissance.tm_year+1900);
        }   
    fclose(ptr); // toujours penser à fermer le fichier
}