#include<stdio.h>

int saisir(int T[100]){
    int n,i;
    do{
        printf("n = ");
        scanf("%d",&n);
    }while(!(n>0 && n<=100));

    for(i=0;i<n;i++){
        printf("T[%d] = ",i);
        scanf("%d",&T[i]);
    }
    return n;
}

void afficher(int T[100],int n){
    int i;
    for(i=0;i<n;i++)
        printf("|%d",T[i]);
    printf("|\n");
}

float moy(int T[100],int n){
    float m=0;
    int i;

    for(i=0;i<n;i++)
        m = m+T[i];
    return m/n;

}

float pow(float x,float y){
    int i=0,p=1;

    for(i=0;i<y;i++)
        p = p*x;
    return p;
}

float poucentage(int T[100],int n){
    int tot = 0,i;
    for(i=0;i<n;i++){
        if(T[i]>5)
            tot++;
    }

    return (tot*100)/n;
}

float variance(int T[100],int n){
    float var=0;
    int i;
    for(i=0;i<n;i++){
        var = var +pow(T[i]-moy(T,n),2);
    }

    return var/n;

}

int append(int T[],int n){
    int x;
    n++;
    printf("x = ");scanf("%d",&x);
    T[n-1] = x;
    return n;
}

int insert(int T[],int n,int pos,int x){
    int i;
    n++;

    T[n-1] = x;

    for(i=n-1;i>pos;i--){
        T[i] = T[i]+T[i-1];
        T[i-1] = T[i] - T[i-1];
        T[i] = T[i] - T[i-1];
    }
    return n;

}

void trie(int T[],int n){
    int permut,i,j;
    j=0;
    do{
        permut = 0;
        for(i=1;i<n-j;i++){
            if(T[i]<T[i-1]){
                    permut = 1;
                T[i] = T[i]+T[i-1];
                T[i-1] = T[i] - T[i-1];
                T[i] = T[i] - T[i-1];
            }
        }
        j++;
    }while(permut == 1);
}

int recherche(int T[],int n,int x){
    int indice = -1,i=0;
    while(indice == -1 && i<n){
        if(T[i]>x)
            indice = i;
        i++;
    }
    return indice;
}



void main(){
    int n,x,T[100],pos;
    n = saisir(T);
    afficher(T,n);
    printf("la moyenne du tableau est : %.2f\n",moy(T,n));
    printf("le poucentage de nombre au-dela de 5 est %.2f\n",poucentage(T,n));
    printf("la variance du tableau est : %.2f\n",variance(T,n));
    n = append(T,n);
    afficher(T,n);
    printf("x = ");scanf("%d",&x);
    do{
       printf("pos = ");
       scanf("%d",&pos);
    }while(!(pos<n&& pos>=0));
    n = insert(T,n,pos,x);
    afficher(T,n);
    trie(T,n);
    afficher(T,n);
    printf("x = ");scanf("%d",&x);
    printf("la position du plus petit element suerieur a x est %d\n",recherche(T,n,x));
    printf("x = ");scanf("%d",&x);
    n = insert(T,n,recherche(T,n,x),x);
    afficher(T,n);
}
