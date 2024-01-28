#include "Ecole.h"

// Saisie de l'école
void SaisirEcole (Ecole_t * Ecole)
{
    // Saisie du nom de l'école
    printf("Saisir le nom de l'Ecole : \n");
    scanf("%s", Ecole -> Nom);
    //Saisie Tableau de classe
    SaisirTabClasse(Ecole -> TabClasse, &Ecole ->nbClasse);
}

// Affichage de l'école
void AfficherEcole (Ecole_t Ecole)
{
    // Nom de l'école
    printf("Nom de l'école : %s\n", Ecole.Nom);

    //Nombre de classe
    printf("Nombre de classes : %d\n", Ecole.nbClasse);

    // Affichage tableau d'école
    AfficherTabClasse(Ecole.TabClasse, Ecole.nbClasse);
}

// Fonction d'affichage dans un fichier lisible par la machine
void EcrireFwrite (Ecole_t* Ecole, const char * filename)
{

    FILE* ptr;
    ptr = fopen(filename, "w"); //ouverture du fichier en écriture
    // Test d'ouverture du fichier
    if(ptr==NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    fwrite(Ecole -> TabClasse, sizeof(Classe_t), Ecole -> nbClasse, ptr); //Ecrit les données de toute l'école dans le fichier
    //     Ecole -> TabClasse : adresse du point de départ
    //     sizeof(Classe_t) : taille des blocs
    //     Ecole -> nbClasse : nombre de bloc
    //     ptr : le fichier


    fclose(ptr); // toujours penser à fermer le fichier
}

// Fonction de saisie des données du fichier lisible par la machine
void SaisirFread (Ecole_t * Ecole, const char * filename)
{
    FILE* ptr;
    int i= 0;
    ptr = fopen(filename, "r"); //ouverture du fichier en lecture
    // Test d'ouverture du fichier
    if(ptr==NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    while(!feof(ptr)) // boucle tant que le pointeur n'a pas atteint la fin du fichier
    {
        i++; //incrémentation pour aller à la ligne suivante
        fread(&Ecole -> TabClasse[i], sizeof(Classe_t),1,ptr); //Lis les données de toute l'école dans le fichier

    }
    Ecole -> nbClasse = i; //récupère le nombre d'itération donc le nombre de classe
    fclose(ptr); // toujours penser à fermer le fichier
}

// Fonction d'affichage dans un fichier lisible par l'homme (excel par exemple)
void EcrireFprintfEcole (Ecole_t * Ecole, const char * filename)
{
    FILE* ptr;
    int i= 0;// compteur de classes
    int j= 0;// compteur d'élèves
    ptr = fopen(filename, "w"); //ouverture du fichier en écriture
    // Test d'ouverture du fichier
    if(ptr==NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    // Affiche le nom de l'école dans le fichier
    fprintf(ptr,"%s\n",Ecole -> Nom);

    // Affiche le nombre de classes
    fprintf(ptr,"%d\n",Ecole -> nbClasse);

    // Boucle sur le nombre de classes
    for(i=0;i<Ecole -> nbClasse;i++)
    {
        // Affiche le nom de la classes
        fprintf(ptr,"%s\n",Ecole -> TabClasse[i].Nom);

        // Affiche le nom et prénom du professeur
        fprintf(ptr,"%s %s\n",Ecole->TabClasse[i].NomProf, Ecole->TabClasse[i].PrenomProf);

        // affiche le nombre d'élèves
        fprintf(ptr,"%d\n", Ecole -> TabClasse[i].nbEleve);

        // Boucle sur le nombre d'élèves
        for(j=0;j<Ecole -> TabClasse[i].nbEleve;j++)
        {

            // Affiche les informations de chaque élève (Nom, Prénom et date de naissance)
            fprintf(ptr,"%s %s %d %d %d\n",Ecole -> TabClasse[i].TabEleve[j].Nom,
            Ecole -> TabClasse[i].TabEleve[j].Prenom,Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_mday,
            Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_mon+1,Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_year+1900);
        }

    }



    fclose(ptr); // toujours penser à fermer le fichier
}

void EcrireFprintfEleve (Ecole_t * Ecole, const char * filename)
{
    FILE* ptr;
    int i= 0;// compteur de classes
    int j= 0;// compteur d'élèves
    ptr = fopen(filename, "w"); //ouverture du fichier en écriture

    // Test d'ouverture du fichier
    if(ptr==NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    // Boucle sur le nombre de classes
    for(i=0;i<Ecole -> nbClasse;i++)
    {
        // Boucle sur le nombre d'élèves
        for(j=0;j<Ecole -> TabClasse[i].nbEleve;j++)
        {

            // Affiche les informations de chaque élève (Nom, Prénom et date de naissance)
            fprintf(ptr,"%s %s %d %d %d\n",Ecole -> TabClasse[i].TabEleve[j].Nom,
            Ecole -> TabClasse[i].TabEleve[j].Prenom,Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_mday,
            Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_mon+1,Ecole -> TabClasse[i].TabEleve[j].Naissance.tm_year+1900);
        }
    }
    fclose(ptr); // toujours penser à fermer le fichier
}

// Extrait les données du fichier voulu et l'affiche dans la console
void SaisirFscanf(Ecole_t * Ecole, const char * filename)
{
    FILE * ptr;
    int cptClasse = 0;
    int cptEleve = 0;
    ptr = fopen(filename, "r");//ouverture du fichier en lecture

    // Test d'ouverture du fichier
    if(ptr == NULL)
    {
        perror("Impossible d'ouvrir le fichier\n");
        exit(EXIT_FAILURE);
    }
    // Lire le nom de l'école depuis le fichier
    fscanf(ptr, "%s", Ecole->Nom);

    // Lis le nombre de classes
    fscanf(ptr,"%d", &Ecole->nbClasse);

    // boucle sur le nombre de classe
    for(cptClasse = 0; cptClasse < Ecole -> nbClasse; cptClasse++)
    {
        //Lis le nom de la classe
        fscanf(ptr,"%s", Ecole->TabClasse[cptClasse].Nom);
        //lis le nom et prénom du professeur
        fscanf(ptr,"%s %s",Ecole->TabClasse[cptClasse].NomProf, Ecole->TabClasse[cptClasse].PrenomProf);
        // lis nombre d'élèves
        fscanf(ptr, "%d", &Ecole -> TabClasse[cptClasse].nbEleve);

        // boucle sur le nombre d'élève
        for(cptEleve = 0; cptEleve < Ecole -> TabClasse[cptClasse].nbEleve; cptEleve++)
        {
            // Lis le Nom de l'élève
            fscanf(ptr,"%s", Ecole -> TabClasse[cptClasse].TabEleve[cptEleve].Nom);

            // Lis le prénom de l'élève
            fscanf(ptr,"%s", Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Prenom);

            // Lis la date de naissance
            fscanf(ptr,"%d %d %d",
                &(Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Naissance.tm_mday),
                &(Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Naissance.tm_mon),
                &(Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Naissance.tm_year));

            // Ajuster le mois en soustrayant 1
            Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Naissance.tm_mon -= 1;

            // Ajuster l'année en soustrayant 1900
            Ecole->TabClasse[cptClasse].TabEleve[cptEleve].Naissance.tm_year -= 1900; // Ajuster l'année en soustrayant 1900
        }
    }
    fclose(ptr);
}

bool RechercherEleve(Ecole_t Ecole, int *indexClasse, int *indexEleve)
{
    char searchNom[50], searchPrenom[50];
    printf("Entrez le nom de l'élève : ");
    scanf("%s", searchNom);
    printf("Entrez le prénom de l'élève : ");
    scanf("%s", searchPrenom);

    bool found = false; // Variable to track if the student is found

    // Iterate through each class in the school
    for (int i = 0; i < Ecole.nbClasse; i++)
    {
        // Iterate through each student in the class
        for (int j = 0; j < Ecole.TabClasse[i].nbEleve; j++)
        {
            // Check if the student's name and surname match the search criteria
            if (strcmp(Ecole.TabClasse[i].TabEleve[j].Nom, searchNom) == 0 && strcmp(Ecole.TabClasse[i].TabEleve[j].Prenom, searchPrenom) == 0)
            {
                printf("L'élève %s %s appartient à la classe %s.\n", searchNom, searchPrenom, Ecole.TabClasse[i].Nom);
                *indexClasse = i;
                *indexEleve = j;
                found = true;
                break; // Exit loop
            }

        }
    }

    if (!found)//not found create a new student data base
    {
        printf("L'élève %s %s n'appartient à aucune classe.\n", searchNom, searchPrenom);
        printf("Voudriez vous procéder à l'inscription de l'élève? si oui utiliser Option b\n");
    }
    return found;
}

//Function to create a new registration
void NewEleve(Eleve_t newEleve)
{
    SaisirEleve(&newEleve);

    // Determine the appropriate class for the student based on age
    AssignerNiveau(newEleve);
}

//Fonction de création d'une nouvelle classe (Non-Fonctionnel)
// Si la capacité de l'école est augmenté ce prototype de fonction servira à ouvrir une nouvelle classe
// void CreerNewClasse(Ecole_t* Ecole)

// {
//     int i, nbEleves;
//     int nbClasse;
//     printf("Création d'une nouvelle classe :\n");
//     printf("Saisir le nom de la classe : ");
//     scanf("%d", &nbClasse);
//     printf("Saisir le nombre d'élèves : ");
//     scanf("%d", &nbEleves);
//     if (Ecole->nbClasse >= MAXCLASSE) {
//         printf("Nombre maximal de classes atteint.\n");
//         return;
//     }
//     Classe_t newClasse; // Create a new class
//     // Set class details
//     //strcpy(newClasse.Nom, nbClasse);
//     newClasse.nbEleve = 0;
// }

// Prototype de fonction pour équilibrer les classe
// bool EstClasseEquilibree(Classe_t Classe)

// {
//     int count[5] = { 0 }; // Array to store the count of students in each age group
//  // Count the number of students in each age group
//     for (int i = 0; i < Classe.nbEleve; i++) {
//         int age = Classe.TabEleve[i].age;
//         if (age == 6) {
//             count[0]++;
//         } else if (age == 7) {
//             count[1]++;
//         } else if (age == 8) {
//             count[2]++;
//         } else if (age == 9) {
//             count[3]++;
//         } else if (age == 10) {
//             count[4]++;
//         }
//     }
// }


//Just FYI, in English, Niveau means Class and classe means section. Example: CP1- CP is class and 1 is a section.               
// void DistributeEleves(Ecole_t* Ecole)

// { 
//     int StudentsPerClasse[TOTAL_CLASSES];
//     int totalEleves = TOTAL_STUDENTS;
//     int totalClasses = TOTAL_CLASSES;
//     int totalEleves = 0;
//     // Calculate the total number of students in the school of each 'niveau' of class. Example: CP1, CP2, CP3)
//     for (int i = 0; i < Ecole->nbClasse; i++) {
//         totalEleves += Ecole->TabClasse[i].nbEleve;//Calculates the total number of students in the 'niveau' by summing up the number of students in each classe.
//     }
//     //Calculates the average number of students per classe 
//     int avgStudentsPerClasse = totalEleves / Ecole->nbClasse; //To be used later to create classes if needed      
//     // Calculate the quotient and remainder using Euclidean division
//     int quotient = totalEleves / totalClasses;
//     int remainder = totalEleves % totalClasses;
//     // Assign the quotient number of students to each class initially
//     for (int i = 0; i < nbClasse; i++) {
//         StudentsPerClasse[i] = quotient;
//     }
//     // Distribute the remaining students one by one to each class
//     for (int i = 0; i < remainder; i++) {
//         StudentsPerClasse[i]++;
//     }
//        //Checks the availability of the class. If available, the students are transferred by iterating over the 
//        //excess students and moving them from the current class to the next class's student array.
// }
// }
//Assuming that we create functions of the following: 
//GetcurrentDate
//TransferEleves
//AnneeScolaireDebut
//AnneeScolaireFin

// Function to check if the opening of a class is validated and distribute the pupils
// void PassageAnneeScolaire(Ecole_t* Ecole)

// {
//     // Get the current year
//     Date_t currentDate = GetCurrentDate(); // Assuming it is created in Date.c to get the current date
//     for (int i = 0; i < Ecole->nbClasse; i++) {
//         Classe_t* currentClass = &Ecole->TabClasse[i];
//         // Compare the current year with the end year of the school year associated with the class
//         if (currentDate.annee >= currentClass->AnneeScolaire.fin.annee) {
//             // Class for the next school year
//             CreerClasse(Ecole);
//             // Transfer the students to the new class
//             TransfererEleves(); // Assuming we have a function to transfer students
//             // Update the school year of the current class and the new class
//             currentClass->AnneeScolaire.debut.annee++;
//             currentClass->AnneeScolaire.fin.annee++;
//         }
//     }
// }