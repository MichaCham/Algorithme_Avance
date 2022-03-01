#include <stdio.h>
#include <stdlib.h>

int fibo_naif(int n){
    if(n <= 1){
        return 1;
    }
    return fibo_naif(n-1) + fibo_naif(n-2);
}

//T(n) = T(n)
int fibo(int n){
    int Fpp =1;
    int Fp =1;

    int i,tmp;

    for(i =2;i<=n;i++){
        tmp = Fpp + Fp;
        Fpp = Fp;
        Fp = tmp;
    }
    return Fp;
}


int main(int argc, char const *argv[])
{
    int haine = atoi(argv[1]);
    printf("F(%d) = %d\n",haine, fibo(haine));
    return 0;
}

/*T(n) = fibo(n)-1;
En effet, cette approche somme fibo(n) n nombres "1"*/

