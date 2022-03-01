#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int min(int a, int b, int c){
    if(a<= b && a <=c) return a;
    if(b<= a && b <=c) return b;
    return c;
}

int L(char* S1, char* S2){
    int nb_ligne =strlen(S1) +1;
    int nb_colonnes =strlen(S2) +1;
    int distance_tab[nb_ligne][nb_colonnes];
    int i,j;
    for (i = 0; i< nb_colonnes;i++){
      distance_tab[0][i] = i;  
    }
    for(i=1; i< nb_ligne; i++){
        distance_tab[i][0] = i;
        for(j=1; j < nb_colonnes;j++){
            if(S1[i-1] == S2[j-1]){
                distance_tab[i][j] = min(distance_tab[i-1][j]+1 , distance_tab[i][j-1] +1, distance_tab[i-1][j-1]);
            }else{
                distance_tab[i][j] = min(distance_tab[i-1][j] , distance_tab[i][j-1], distance_tab[i-1][j-1])+1;
            }
        }
    }
    return distance_tab[nb_ligne-1][nb_colonnes-1];
}

int L_naif(char* S1, char* S2){
    if(strlen(S1) == 0) return strlen(S2);
    if(strlen(S2) == 0) return strlen(S1);
    if(S1[0]==S2[0]){
        return min(L_naif(S1, S2+1)+1, L_naif(S1+1,S2)+1, L_naif(S1+1,S2+1));
    }
    else{
        return min(L_naif(S1,S2+1), L_naif(S1+1,S2), L_naif(S1+1,S2+1))+1;
    }
    
}


int main(int argc, char *argv[])
{
    if(argc == 0){
        printf("il faut au moins deux paramètres.");
        return -1;
    }
    char* chaine1 = argv[1];
    char* chaine2 = argv[2];
    printf("%d",L(chaine1, chaine2));

    return 0;
}
