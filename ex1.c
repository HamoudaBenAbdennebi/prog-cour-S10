#include<stdio.h>

int Max(int x,int y){
    if(x>y)
        return x;
    else
        return y;
}

int Min(int x,int y){
    if(x<y)
        return x;
    else
        return y;
}

int saisir(char x){
    printf("%c = ",x);
    fflush(stdin);
    scanf("%d",&x);
    return x;
}

void afficher(int a,int b, int c,int d){
    printf("le maximum est %d et le minimum %d",Max(Max(a,b),Max(c,d)),Min(Min(a,b),Min(c,d)));
}

void main(){
    int a,b,c,d;

    a=saisir('a');
    b=saisir('b');
    c=saisir('c');
    d=saisir('d');

    afficher(a,b,c,d);

}


