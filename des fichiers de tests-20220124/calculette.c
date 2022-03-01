#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* mon_fichier;

char mon_caractere_courant;
int mon_resultat = 0;

void expression();

void lire_caractere(){
    mon_caractere_courant = fgetc(mon_fichier);
    printf("%c", mon_caractere_courant);
}

void passer_espaces(){
    while(mon_caractere_courant == ' ' || mon_caractere_courant == '\t' || mon_caractere_courant == '\n' || mon_caractere_courant == '\r'){
        lire_caractere();
    }
}

void amorcer_lecture(char* nom_fichier){
    mon_fichier = fopen(nom_fichier, "r");
    if(!mon_fichier){
        fprintf(stderr, "fichier %s inconnu\n", nom_fichier);
    }
    lire_caractere();
}

void terminer_lecture(){
    fclose(mon_fichier);
}

void consommer_caractere(char c){
    if(mon_caractere_courant != c){
        fprintf(stderr, "erreur : caractere attendu : '%c' caractere trouve : '%c' (%d).\n",
        c, mon_caractere_courant, mon_caractere_courant);

        exit(-1);
    }
    lire_caractere();
}

void chiffre_non_nul(){
    if('1' <= mon_caractere_courant && mon_caractere_courant <= '9'){
        mon_resultat += (int)(mon_caractere_courant -'0');
        consommer_caractere(mon_caractere_courant);
    }else{
        fprintf(stderr, "chiffre attendu\n");
        exit(-1);
    }
}

void sequence_chiffres(){
    while('0' <= mon_caractere_courant && mon_caractere_courant <= '9'){
        mon_resultat *= 10 ;
        if(mon_caractere_courant == '0'){
            consommer_caractere('0');
        }else{
            chiffre_non_nul();
        }
    }
}

void nombre_non_signe(){
    if(mon_caractere_courant == '0'){
        consommer_caractere('0');
    }else{
        chiffre_non_nul();
        sequence_chiffres();
    }
}

void nombre(){
    int sg = 1;
    mon_resultat =0;
    if(mon_caractere_courant == '-'){
        consommer_caractere('-');
        passer_espaces();
        sg = -1;
    }
    if(mon_caractere_courant == '('){
        consommer_caractere('(');
        passer_espaces();
        expression();
        consommer_caractere(')');
    }else{
        nombre_non_signe();
    }
    mon_resultat *=sg;
    passer_espaces();
}

void op_add(){
    switch (mon_caractere_courant){
        case '+':
            consommer_caractere('+');
            break;        
        case '-':
            consommer_caractere('-');
            break;        
    }
    passer_espaces();
}

void op_mult(){
    switch (mon_caractere_courant){
        case '*':
            consommer_caractere('*');
            break;        
        case '/':
            consommer_caractere('/');
            break;        
        case '%':
            consommer_caractere('%');
            break;        
    }
    passer_espaces();
}

void facteur(){
    nombre();
    passer_espaces();
}

void terme(){
    facteur();
    int mon_acc = mon_resultat;
    while(mon_caractere_courant == '*' || mon_caractere_courant == '/' || mon_caractere_courant == '%'){
        switch(mon_caractere_courant){
            case '*':
                op_mult();
                facteur();
                mon_acc *= mon_resultat;
                break;
            case '/':
                op_mult();
                facteur();
                mon_acc /= mon_resultat;
                break;
            case '%':
                op_mult();
                facteur();
                mon_acc%= mon_resultat;
                break;
            default:
                fprintf(stderr, "operateur multiplicatif attendu\n");
        }
        
    }
    mon_resultat = mon_acc;
    passer_espaces();
}

void expression(){
    terme();
    int mon_acc = mon_resultat;
    while(mon_caractere_courant == '+' || mon_caractere_courant == '-'){
        switch(mon_caractere_courant){
            case '+':
                op_add();
                terme();
                mon_acc+= mon_resultat;
                break;
            case '-':
                op_add();
                terme();
                mon_acc-= mon_resultat;
                break;
            default:
                fprintf(stderr, "operateur additif attendu\n");
        }
    }
    mon_resultat =mon_acc;
    passer_espaces();
}

void calcul(){
    expression();
    passer_espaces();
    consommer_caractere('=');
    printf("%d",mon_resultat);
    passer_espaces();
    
}

void salve(){
    while(mon_caractere_courant != EOF){
        calcul();
    }
}

int main(int argc, char** argv){
    for(int i = 1; i<argc; i++){
        amorcer_lecture(argv[i]);
        salve();
        terminer_lecture();
    }
    return 0;
}

