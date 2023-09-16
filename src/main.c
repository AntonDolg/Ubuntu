#include <stdio.h>
#include <string.h>

#define TYPS char* flags, char** argv, int last, int t

void cat(TYPS);
void fb(TYPS);
void fe(TYPS);
void fn(TYPS);
void fs(TYPS);
void ft(TYPS);
void grep(TYPS);
void Read(TYPS);

int main(int argc, char **argv){
    char flags[256]={0}, vhod[0];
    int last=0;
    int t=0;

    for (int i=1;i<argc;i++){
        if(argv[i][0]=='-'){
            for(int j=1;argv[i][j]!='\0';++j){
                flags[t]=argv[i][j];
                t++;
            }
        }
        else{
            last=i;
        }
    }

    /*for(int i=0;i<strlen(argv[0]);i++){
        strcat(vhod[0],argv[0][i]);
    }*/

    if(sizeof(argv[0])==8 && argv[0][0]=='.' && argv[0][1]=='/' && argv[0][2]=='s' && 
    argv[0][3]=='2' && argv[0][4]=='1' && argv[0][5]=='_' && 
    argv[0][6]=='c' && argv[0][7]=='a' && argv[0][8]=='t'){
        cat(flags,argv,last,t);
    }
    else if(sizeof(argv[0])==9 && argv[0][0]=='.' && argv[0][1]=='/' && argv[0][2]=='s' && 
    argv[0][3]=='2' && argv[0][4]=='1' && argv[0][5]=='_' && 
    argv[0][6]=='g' && argv[0][7]=='r' && argv[0][8]=='e' && argv[0][9]=='p'){
        grep(flags,argv,last,t);
    }
    else{
        printf("OOO");
    }
    return 0;
    /*if(vhod[0]=="/s21_cat"){
        cat(flags,argv,last,t);
    }
    else if(vhod[0]=="/s21_grep"){
        grep(flags,argv,last,t);
    }
    else{
        printf("error");
    }*/
}
void Read(TYPS){
    FILE *file=fopen(argv[last],"r");
    if(file==NULL){
        printf("Error>>NoFile");
    }
    char words[256];
    while(fgets(words,sizeof(words),file)!=NULL){
        printf("%s",words);
    }
    fclose(file);
}

void fb(TYPS){
    int N=1;
    FILE *file=fopen(argv[last],"r");
    if(file==NULL){
        printf("Error>>NoFile");
    }
    char words[256];
    while(fgets(words,sizeof(words),file)!=NULL){
        if(strlen(words)>1){
            printf("%d %s",N,words);
            N++;
        }
        else{
            printf("%s",words);
        }
    }
    fclose(file);
}

void fe(TYPS){
    int p=0;
    FILE *file=fopen(argv[last],"r");
    if(file==NULL){
        printf("Error>>NoFile");
    }
    char words[256];
    while(fgets(words,sizeof(words),file)!=NULL){
        words[strcspn(words,"\n")]='\0';
        strcat(words, "$");
        if(p!=0){
            printf("\n");
        }
        printf("%s",words);
        p++;
    }
    fclose(file);
}

void fn(TYPS){
    int N=1;
    FILE *file=fopen(argv[last],"r");
    if(file==NULL){
        printf("Error>>NoFile");
    }
    char words[256];
    while(fgets(words,sizeof(words),file)!=NULL){
        printf("%d %s",N,words);
        N++;
    }
    fclose(file);
}

void fs(TYPS){
    int V=0;
    FILE *file=fopen(argv[last],"r");
    if(file==NULL){
        printf("Error>>NoFile");
    }
    char words[256];
    while(fgets(words,sizeof(words),file)!=NULL){
        if(strlen(words)==1 && V!=1){
            V++;
            printf("%s",words);
        }
        else if(strlen(words)>1){
            printf("%s",words);
            V=0;
        }
    }
    fclose(file);
}

void ft(TYPS){
}

void cat(TYPS){
    switch(flags[0]){
        case 'b':fb(flags,argv,last,t);
        break;
        case 'e':fe(flags,argv,last,t);
        break;
        case 'n':fn(flags,argv,last,t);
        break;
        case 's':fs(flags,argv,last,t);
        break;
        case 't':ft(flags,argv,last,t);
        break;
        default:Read(flags,argv,last,t);
        break;
    }

}
void grep(TYPS){
}