#include "Eleve.h"

void SaisirEleve (Eleve_t * Eleve) // Saisie d'un élève (nom, prenom, date de naissance)
{
    printf("Saisir Nom et prénom de l'élève : \n");
    scanf("%s %s", Eleve -> Nom, Eleve -> Prenom);
    SaisirNaissance(&Eleve -> Naissance);
}

void AfficherEleve (Eleve_t Eleve) // Affichage des informations d'un eleve
{
    printf ("%s %s né le ", Eleve.Nom, Eleve.Prenom);
    AfficherNaissance(Eleve.Naissance);
}

void SaisirTabEleve (Eleve_t TabEleve[], int * nbr) // Saisie d'un tableau d'eleve (nbre d'eleves)
{
    printf("Saisir le nombre d'élèves : \n");
    scanf("%d", nbr);
    for(int i=0; i<*nbr;i++)
    {
        SaisirEleve(&TabEleve[i]);
    }
}

void AfficherTabEleve (Eleve_t TabEleve[], int nbr) // Afficher un tableau d'eleve
{
    for(int i=0; i<nbr;i++)
    {
        printf("l'élève %d : \n", i+1);
        AfficherEleve(TabEleve[i]);
    }
}

// Le calcul de l'age (année en cours - année de naissance)
int CalculerAge (Eleve_t Eleve)
{
time_t now;
time(&now);
struct tm* currentTime = localtime(&now);

Eleve.age = currentTime->tm_year - Eleve.Naissance.tm_year;

return Eleve.age;
}

void AfficherAge (Eleve_t Eleve) // Affiche l'age de l'eleve
{
    int age = CalculerAge (Eleve);
    printf("%d ans\n", age);
}

// Affecter un niveau (CP, CE1, CE2, CM1, CM2)selon l'année de naissance de l'élève
char AssignerNiveau (Eleve_t Eleve)
{
    int age = CalculerAge(Eleve);
    if(age < 6)
    {
        printf("Cet élève est trop jeune, vous pouvez l'inscrire dans notre maternelle : Mat supp\n");
    }
        if(age == 6)
        {
            printf("Cet élève est en CP\n");
        }
        else 
            if (age == 7)
            {
                printf("Cet élève est en CE1\n");
            }
            else
                if(age == 8)
                {
                    printf("Cet élève est en CE2\n");
                }
                else
                    if(age == 9)
                    {
                        printf("Cet élève est en CM1\n");
                    }
                    else
                        if(age == 10)
                        {
                            printf("Cet élève est en CM2\n");
                        }
                        else
                            if(age > 10)
                        {
                            printf("Cet élève est trop vieux pour intégrer cette école primaire\n");
                        }
}

void ModifierEleve (Eleve_t * Eleve) //Modifie les informations de l'eleve - Permet de choisir l'information à modifier 
{
    char Reponse[20];
    char Prenom[50];
    char Nom[50];
    char Naissance[50];
    int choix;
    printf("Quelle donnée voulez-vous modifier (Nom, Prénom ou Naissance) ?\n");
    scanf("%s", Reponse);

    while (!((strcmp(Reponse, "Nom") == 0) || (strcmp(Reponse, "Prénom") == 0) || (strcmp(Reponse, "Naissance") == 0))) 
    {
        printf("Choisir parmi Nom, Prénom ou Naissance.\n"); //choix de l'information à modifier
        scanf("%s", Reponse);
    }

    if (strcmp(Reponse, "Nom") == 0)
        {
            printf("Saisir le nouveau nom :\n");
            scanf("%s", Nom); //saisie du nouveau nom
            strcpy(Eleve->Nom, Nom); // copie du nouveau nom
        }    
    else if (strcmp(Reponse, "Prénom") == 0) 
        {
            printf("Saisir le nouveau prénom :\n");
            scanf("%s", Prenom);//saisie du nouveau prenom
            strcpy(Eleve->Prenom, Prenom);// copie du nouveau prenom
        } 
    else if (strcmp(Reponse, "Naissance") == 0) 
        {
            printf("Saisir la nouvelle date de naissance (JJ-MM-AAAA) :\n");
            scanf("%s", Naissance);//saisie de la nouvelle date de naissance
            sscanf(Naissance, "%d-%d-%d", &Eleve->Naissance.tm_mday, &Eleve->Naissance.tm_mon, &Eleve->Naissance.tm_year);// copie de la nouvelle date de naissance
            Eleve->Naissance.tm_mon -= 1; //correction du mois de naissance
            Eleve->Naissance.tm_year -= 1900; //correction de l'année de naissance
        }          
}