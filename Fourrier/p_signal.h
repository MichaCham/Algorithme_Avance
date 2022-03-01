#ifndef P_SIGNAL_H
#define P_SIGNAL_H

#include <stdio.h>
#include "p_vecteur.h"

/** En C une union permet de donner une vue sur les informations stockées dans une variable.
 *  Ici un <t_octet> est :
 *     - soit un entier signé allant de -128 à 127
 *     - soit un entier non signé (positif) allant de 0 à 255
 *  En général, la taille du type est égal au maximum des tailles des différents champs.
 *  Il se trouve qu'ici les deux champs font la même taille.
 */
typedef union u_octet{
    unsigned char la_valeur_non_signe;
    char la_valeur_signe;
}t_octet;

/** un signal est un tableau d'octets
 *  Ce type fonctionnera de la même façon
 *    - pour le type <t_decompresse> qui est composé <TAILLE_SIGNAL> entiers compris entre 0 et 255
 *    - pour le type <t_compresse> qui est composé d'un entier compris entre 0 et 255 et de
 * <TAILLE_SIGNAL - 1> entiers compris entre -128 et 127.
 */
typedef struct s_signal{
    t_octet les_valeurs[TAILLE_SIGNAL];
}t_signal;

/**
 *  Initialiser la bibliothèque. Notamment pour le générateur de nombre aléatoire.
 */
void initialiser_p_signal();

/**
 * Affiche <ceci>.
 * @param ceci : t_signal.
 */
void afficher_signal(const t_signal* ceci);

/**
 * Initialise le contenu de <ceci> par des valeurs aléatoires.
 * @param ceci : t_signal.
 */
void randomiser_signal(t_signal* ceci);

/**
 * Ouvre un fichier binaire pour y lire des signaux.
 * @param nom_fichier : char*.
 */
FILE* ouvrir_lecture_signal(char* nom_fichier);


/**
 * Ouvre un fichier binaire pour y écrire des signaux.
 * @param nom_fichier : char*.
 */
FILE* ouvrir_ecriture_signal(char* nom_fichier);

/**
 * ferme un fichier binaire.
 * @param nom_fichier : char*.
 */
void fermer_signal(FILE* fichier);

/** Lit un signal dans le fichier <fichier> et place la lecture dans ceci.
 * @param ceci : t_signal*.
 * @param fichier : FILE*.
 * @warning : <ceci> est altéré par la fonction.
 */
void lire_signal(t_signal* ceci, FILE* fichier);


/** Lit un signal dans le fichier <fichier> et place la lecture dans ceci.
 * @param ceci : t_signal*.
 * @param fichier : FILE*.
 * @warning : <ceci>* est altéré par la fonction.
 */
void ecrire_signal(const t_signal* ceci, FILE* fichier);

#endif