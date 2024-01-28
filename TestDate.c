#include <stdio.h>
#include <stdbool.h>
#include "Date.h"

int main()
{
    struct tm Naissance;
    SaisirNaissance(&Naissance);
    AfficherNaissance(Naissance);
    
    /*bool shouldPass = PassageClasse(Naissance);
    if (shouldPass) {
        printf("L'étudiant devrait réussir la classe.\n");
    } else {
        printf("L'étudiant ne devrait pas réussir la classe.\n");
    }*/
    
    return 0;
}