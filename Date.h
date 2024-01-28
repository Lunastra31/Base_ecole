#include <stdio.h>
#include <time.h>
#include <stdbool.h>

#ifndef DATE_H
#define DATE_H

//Saisie de la date de naissance
void SaisirNaissance(struct tm * Naissance);

//Affichage de la date de naissance
void AfficherNaissance(struct tm Naissance);

#endif