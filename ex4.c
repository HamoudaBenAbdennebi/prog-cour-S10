#include<stdio.h>
#include<string.h>

int search(char ch[20],char c){
    int pos=-1,i;

    for(i=0;i<strlen(ch);i++){
        if(strcmp(ch[i],c)==0)
            pos = i;
    }

    return pos;
}

void search_all(char ch[20],char c){
    int T[100],i,j=0;

    for(i=0;i<strlen(ch);i++){
        if(strcmp(ch[i],c)==0){
            T[j] = i;
            j++;
        }
    }

    for(i=0;i<j;i++)
        printf("|%d",T[i]);
    printf("|\n");
}

void supprimer(char ch[20] , char c){
    int n = strlen(ch),i,j;
    char tmp;
    for(i=0;i<n;i++){
        if(strcmp(ch[i],c)==0){
            for(j=n-1;j>i;j++){
                temp = ch[i];
                ch[i] = ch[i-1];
                ch[i-1]=temp;
                n--;
            }
        }
    }
}

int nb_Occ(char ch[20],char c){
    int nb,i;
    for(i=0;i<strlen(ch);i++){
        if(strcmp(ch[i],c)==0)
            nb++;
    }

    return nb;
}




