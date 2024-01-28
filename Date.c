#include "Date.h"

// Entrer la date de naissance 
void SaisirNaissance(struct tm* Naissance) 
{
    printf("Entrer la date de naissance (JJ-MM-YYYY) : ");
    scanf("%d-%d-%d", &Naissance->tm_mday, &Naissance->tm_mon,&Naissance->tm_year);
    Naissance->tm_year -= 1900;
    Naissance->tm_mon -= 1;
}

// Afficher la date de naissance 
void AfficherNaissance(struct tm Naissance) 
{
    //Affichage  de la date de naissance au format JJ-MM-AAAA
    printf("%02d-%02d-%04d\n",Naissance.tm_mday,Naissance.tm_mon + 1,Naissance.tm_year + 1900);
}