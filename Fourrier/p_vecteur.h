#ifndef P_VECTEUR_H
#define P_VECTEUR_H

#define TAILLE_SIGNAL 16

typedef float t_scalaire;

typedef struct s_vecteur{
    t_scalaire les_valeurs[TAILLE_SIGNAL];
}t_vecteur;

/**
 * Affiche <ceci>.
 * @param ceci : t_vecteur.
 */
void afficher_vecteur(const t_vecteur* ceci);

/**
 * Copie <*ceci> dans <*dans>.
 * @param ceci : const t_vecteur*.
 * @param dans : t_vecteur*.
 */
void copie_vecteur(const t_vecteur* ceci, t_vecteur* dans);

/**
 * Ajoute <*ceci> a <*a>.
 * @param ceci : const t_vecteur*.
 * @param a : t_vecteur*.
 */
void ajoute_vecteur(const t_vecteur* ceci, t_vecteur* a);

/**
 * multiplie tous les coefficients de <*ceci> par le coefficient <coefficient>.
 * @param a : t_scalaire.
 * @param ceci : const t_vecteur*.
 */
void dilate_vecteur(t_scalaire coefficient, t_vecteur* ceci);

/**
 * retourne le produit scalaire de <*ceci> par <*cela>.
 * @param ceci : const t_vecteur*.
 * @param cela : const t_vecteur*.
 * @return : t_scalaire.
 */
t_scalaire produit_scalaire(const t_vecteur* ceci, const t_vecteur* cela);

/**
 * Copie dans <*e_i> le i^{ème} vecteur de la base canonique (des 0 partout sauf à l'indice i (où il y a un 1)).
 * @param i : int.
 * @param e_i : t_vecteur*.
 */
void vecteur_base_canonique(int i, t_vecteur* e_i);

/**
 * Initalise la bibliothèque pour réaliser les calculs de transformation de fourier rapide.
 */
void initialiser_base_fourier();

/**
 * Copie dans <*f_i> le i^{ème} vecteur de la base de transformation.
 * @param i : int.
 * @param f_i : t_vecteur*.
 */
void vecteur_base_fourier(int i, t_vecteur* f_i);

/**
 * Copie la transformée de <*ceci> dans <*transforme>.
 * @param ceci : const t_vecteur*.
 * @param transforme : t_vecteur*.
 */
void transformer_vecteur(const t_vecteur* ceci, t_vecteur* transforme);

/**
 * Copie le vecteur original de la transformée <*ceci> dans <*original>.
 * @param ceci : const t_vecteur*.
 * @param original : t_vecteur*.
 */
void reformer_vecteur(const t_vecteur* ceci, t_vecteur* original);

#endif