#include "Eleve.h"

int main()
{
    //initialisation d'un éleve
    Eleve_t E1 = 
    {
        "Nguyen",
        "Minh",
        {0,0,0,27,8-1,2017-1900,0,0,0}

    };

    AfficherEleve(E1);
    // SaisirEleve(&E1);
    //CalculerAge(E1); // calcul de l'âge d'une élève
    //AfficherAge(E1); // fonction de test pour vérifier CalculerAge
    //AssignerNiveau(E1);
    ModifierEleve(&E1);
    AfficherEleve(E1);
    
    // Initialisation Tableau d'éleves
    Eleve_t TabEleve[2]= 
    {
        {
            "Nguyen","Minh",{0,0,0,27,8-1,2015-1900,0,0,0}

        },
        {
            "Gonçalves", "Fabien",{0,0,0,16,1-1,2014-1900,0,0,0}
        },
    };
    int nbr= 3;
    //AfficherTabEleve(TabEleve, nbr);
    //SaisirTabEleve(TabEleve,&nbr);
    //AfficherTabEleve(TabEleve, nbr);

}