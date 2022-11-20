#include<stdio.h>
#include<string.h>
int menu(){
    int choix;
    do{
        printf("1 - salade\n");
        printf("2 - Grillades\n");
        printf("3 - Lasagne\n");
        printf("4 - Pizza\n");
        scanf("%d",&choix);
    }while(!(choix<=4 && choix >= 1));
    return choix;
}


void afficher(int choix){
    char x[20];
    switch(choix){
        case 1:
            strcpy(x,"salade");
            break;
        case 2:
            strcpy(x,"Grillades");
            break;
        case 3:
            strcpy(x,"Lasagne");
            break;
        case 4:
            strcpy(x,"Pizza");
            break;
    }

    printf("votre choix est : %s",x);
}

void main(){
    int choix;
    choix = menu();
    afficher(choix);
}


