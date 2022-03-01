#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "p_vecteur.h"

/**
 * Affiche <ceci>.
 * @param ceci : t_vecteur.
 */
void afficher_vecteur(const t_vecteur* ceci){
    int i;
    printf("{ ");
    for(i = 0; i< TAILLE_SIGNAL; i++){
        printf("%f ", ceci->les_valeurs[i]);
    }
    printf("}\n");
}


/**
 * Copie <*ceci> dans <*dans>.
 * @param ceci : const t_vecteur*.
 * @param dans : t_vecteur*.
 */
void copie_vecteur(const t_vecteur* ceci, t_vecteur* dans){
    memcpy(dans->les_valeurs, ceci->les_valeurs, TAILLE_SIGNAL * sizeof(t_scalaire));
}

/**
 * Ajoute <*ceci> a <*a>.
 * @param ceci : const t_vecteur*.
 * @param a : t_vecteur*.
 */
void ajoute_vecteur(const t_vecteur* ceci, t_vecteur* a){
    int i;
    for(i=0; i<TAILLE_SIGNAL; i++){
        a->les_valeurs[i] += ceci->les_valeurs[i];
    }
}

/**
 * multiplie tous les coefficients de <*ceci> par le coefficient <coefficient>.
 * @param a : t_scalaire.
 * @param ceci : const t_vecteur*.
 */
void dilate_vecteur(t_scalaire coefficient, t_vecteur* ceci){
    int i;
    for(i = 0 ; i<TAILLE_SIGNAL; i++){
        ceci->les_valeurs[i] = ceci->les_valeurs[i]*coefficient;
    }
}

/**
 * retourne le produit scalaire de <*ceci> par <*cela>.
 * @param ceci : const t_vecteur*.
 * @param cela : const t_vecteur*.
 * @return : t_scalaire.
 */
t_scalaire produit_scalaire(const t_vecteur* ceci, const t_vecteur* cela){
    int i;
    t_scalaire tmp_scalaire =0;

    for(i=0; i<TAILLE_SIGNAL; i++){
        tmp_scalaire += ceci->les_valeurs[i] * cela->les_valeurs[i];
    }
    return tmp_scalaire;
}


/**
 * Copie dans <*e_i> le i^{ème} vecteur de la base canonique (des 0 partout sauf à l'indice i (où il y a un 1)).
 * @param i : int.
 * @param e_i : t_vecteur*.
 */
void vecteur_base_canonique(int i, t_vecteur* e_i){
    for(int y = 0; y<TAILLE_SIGNAL; y++){
        e_i->les_valeurs[y] = 0;
    }
    e_i->les_valeurs[i] = 1.0;
}

t_vecteur mes_vecteurs_de_fourier[TAILLE_SIGNAL];
int mon_nb_vecteurs_de_fourier;

void doubler_vecteur_fourrier(int nb_vecteur){
    
}


/**
 * Initalise la bibliothèque pour réaliser les calculs de transformation de fourier rapide.
 */
void initialiser_base_fourier(){
    mon_nb_vecteurs_de_fourier = 1;
    mes_vecteurs_de_fourier[0].les_valeurs[0]= 1.0;
    for (int i = 0; i < mon_nb_vecteurs_de_fourier; i++)
    {
        if(mon_nb_vecteurs_de_fourier>=TAILLE_SIGNAL){
            return;
        }
    }
    
}