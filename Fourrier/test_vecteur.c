#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_vecteur.h"
//#include "p_signal.h"

t_vecteur mon_vecteur;
t_vecteur mon_vecteur2;

int main(){
    mon_vecteur.les_valeurs[0] = 3.5;
    mon_vecteur2.les_valeurs[0] = 1.2;
    printf("avant\n");
    afficher_vecteur(&mon_vecteur);
    afficher_vecteur(&mon_vecteur2);
    copie_vecteur(&mon_vecteur2, &mon_vecteur);
    printf("après\n");
    afficher_vecteur(&mon_vecteur);
    afficher_vecteur(&mon_vecteur2);

    printf("Produit scalaire = %f\n", produit_scalaire(&mon_vecteur, &mon_vecteur2));

    return 0;
}