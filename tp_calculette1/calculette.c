#include <stdio.h>
#include <stdlib.h>

FILE* mon_fichier;

char mon_caractere_courant;

void expression();

void lire_caractere(){
    mon_caractere_courant = fgetc(mon_fichier);
    printf("%c\n", mon_caractere_courant);
    if(mon_caractere_courant == ' ' || mon_caractere_courant == '\n' || mon_caractere_courant == '\r'){
        lire_caractere();
    }
}

void amorcer_lecture(){
    mon_fichier = fopen("exemples.txt", "r");
    lire_caractere();
}

void terminer_lecture(){
    fclose(mon_fichier);
}

void consommer_caractere(char c){//,char* fonction){
    if(mon_caractere_courant != c){
        //
        fprintf(stderr, "<!> erreur : caractere attendu : %c, caractere trouvé : %c <!>", 
        c, mon_caractere_courant);//, fonction);
        exit(-1);
    }
    lire_caractere();
}

void chiffre_non_nul(){
    if(mon_caractere_courant <= '9' && '1' <= mon_caractere_courant ){
        consommer_caractere(mon_caractere_courant);//,"chiffre_non_nul");
    }
}

void sequence_chiffre(){
    if(mon_caractere_courant == '0'){
        consommer_caractere('0');//,"sequence_chiffre");
    } else {
        chiffre_non_nul();
    }
    if(mon_caractere_courant <= '9' && '1' <= mon_caractere_courant ){
        sequence_chiffre();
    }
}

void nombre_non_signe(){
    if(mon_caractere_courant == '0'){
        consommer_caractere('0');//,"nombre_non_signe");
    } else {
        chiffre_non_nul();
        sequence_chiffre();
    }
}

void nombre(){
    if(mon_caractere_courant == '-'){
        consommer_caractere('-');//,"nombre");
    }
    nombre_non_signe();
}

void op_add(){
    switch (mon_caractere_courant){
        case '+':
            consommer_caractere('+');//,"op_add");
            break;
        case '-':
            consommer_caractere('-');//,"op_add");
            break;
    }
}

void op_mult(){
    switch (mon_caractere_courant){
        case '*':
            consommer_caractere('*');//,"op_mult");
            break;
        case '/':
            consommer_caractere('/');//,"op_mult");
            break;
        case '%':
            consommer_caractere('%');//,"op_mult");
            break;
    }
}

void facteur(){
    if(mon_caractere_courant == '('){
        consommer_caractere('(');
        expression();
        consommer_caractere('(');
    } else {
        nombre();
    }
}

void terme(){
    facteur();
    switch(mon_caractere_courant){
        case '*':
        case '/':
        case '%':
            op_mult();
            terme();
    }
}

void expression(){
    terme();
    while(mon_caractere_courant == '+' || mon_caractere_courant == '-'){
        op_add();
        terme();
    }
}

void calcul(){
    expression();
    consommer_caractere('=');
}

void salve(){
    while(mon_caractere_courant != EOF){
        calcul();
    }
}


int main(){
    amorcer_lecture();

    salve();

    terminer_lecture();
    return 0;
}