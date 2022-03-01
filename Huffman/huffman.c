#include "limits.h"
#include "stdlib.h"
#include "stdio.h"

#define NVIDE NULL
char current_char;
FILE* file;


typedef union u_etiquette{
    int le_code;
    int la_valeur;
}t_etiquette;


typedef struct s_noeud
{
    t_etiquette etiquette;
    struct s_noeud*  noeud_gauche;
    struct s_noeud*  noeud_droite;  
}t_noeud;
typedef t_noeud* p_noeud;

typedef struct s_code_variable{
    int la_taille;
    /*long*/ int la_valeur;
}t_code_varaible;





int liste_occ[UCHAR_MAX + 1];
p_noeud liste_noeud[UCHAR_MAX+1];
int* liste_trie;

/**
 * \brief affiche n espaces.
 *
 * \param n : int :le nombre de paires d'espaces affichées.
 */
void afficher_n_espaces(int n){
    for(int i = 0; i < n; i++){
        printf(" ");
    }
}

void terminer_lecture(){
    fclose(file);
}

int est_feuille(p_noeud noeud){
    return noeud->noeud_droite == NULL && noeud->noeud_gauche == NULL;
}

int valeur_noeud(p_noeud noeud){
    if(est_feuille(noeud)) {
        return liste_occ[noeud->etiquette.le_code];
    }
    return noeud->etiquette.la_valeur;
}

int noeud_compare(const void * ptr1, const void * ptr2 ){
    p_noeud firstNoeud = * (const p_noeud *) ptr1; 
    p_noeud secondNoeud = * (const p_noeud *) ptr2; 
    return valeur_noeud(firstNoeud) - valeur_noeud(secondNoeud);
}

void creation_tableau_feuille(){
    int i;
    for(i =0 ; i< UCHAR_MAX +1; i++){
        p_noeud noeud = (p_noeud)malloc(sizeof(t_noeud));
        liste_noeud[i] = noeud; 
        liste_noeud[i]->etiquette.le_code = i;
        liste_noeud[i]->noeud_droite = NULL;
        liste_noeud[i]->noeud_gauche = NULL;
    }
    qsort(liste_noeud,UCHAR_MAX +1, sizeof(p_noeud), noeud_compare);
}

void lire_tableau(){
    for(int i = 0; i < UCHAR_MAX; i++){
        printf("CHAR %d (%x) => %d\n", i, i, liste_occ[i]);
    }
}

void initialiser_tableau(){
    for(int i = 0; i < UCHAR_MAX +1; i++){
        liste_occ[i] = 0;
    }
}


void lire_chaine_char(){
    current_char = fgetc(file);
}

void lire_liste_noeud(){
    printf("\nLISTE Noeud Trie :\n");
    for(int i = 0; i < UCHAR_MAX +1; i++){
        if(valeur_noeud(liste_noeud[i]) != 0)
        printf("%c : Occurences => %d\n", liste_noeud[i]->etiquette.le_code, valeur_noeud(liste_noeud[i]));
    }
}

p_noeud creation_arbre(){
    int i;
    for(i = 0; i< UCHAR_MAX ; i++){
        
        if(valeur_noeud(liste_noeud[i]) != 0){
            p_noeud mon_noeud = (p_noeud)malloc(sizeof(t_noeud));
            if(valeur_noeud(liste_noeud[i]) >= valeur_noeud(liste_noeud[i+1])){
                mon_noeud->noeud_gauche = liste_noeud[i];
                mon_noeud->noeud_droite = liste_noeud[i+1];
            }else{
                mon_noeud->noeud_gauche = liste_noeud[i+1];
                mon_noeud->noeud_droite = liste_noeud[i];
            }
            mon_noeud->etiquette.la_valeur = valeur_noeud(liste_noeud[i+1]) + valeur_noeud(liste_noeud[i]);
            liste_noeud[i+1] = mon_noeud;
        }
    }
    return liste_noeud[UCHAR_MAX];
}

void afficher_element(p_noeud mon_noeud){
    printf("%d",valeur_noeud(mon_noeud));
}

void afficher_noeud(p_noeud mon_noeud, int decalage){
    if(mon_noeud != NVIDE){
        afficher_noeud(mon_noeud->noeud_gauche, decalage + 1);
        afficher_n_espaces(2*decalage);
        afficher_element(mon_noeud);
        printf("\n");
        afficher_noeud(mon_noeud->noeud_droite, decalage + 1);
    }
}

void huffman(){
    initialiser_tableau();
    printf("INDEX (DECIMAL) | INDEX (HEXADECIMAL) | NB OCCURENCES\n");
    int taille = 0;
    while (current_char != EOF){
        lire_chaine_char();
        if(liste_occ[(unsigned char)current_char] == 0)
            taille ++;
        liste_occ[(unsigned char)current_char] ++;
    }
    printf("Lecture tableau");
    lire_tableau();
    printf("Creation tableau noeud");
    creation_tableau_feuille();
    lire_liste_noeud();

    p_noeud mon_arbre = creation_arbre();

    afficher_noeud(mon_arbre,0);
}



int main(int argc, char** argv){
    file = fopen("text.txt", "r");
    if(file == NULL){
        fprintf(stderr, "Impossible d'ouvrir le fichier %s.\n", "texte.txt");
    }

    huffman();
    terminer_lecture();

    return 0;
} 
