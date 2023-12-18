#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

struct p{
    char x;
    int y;
};

void empty(int n,char game[n][n]){
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            game[a][b]=' ';
        }
    }
}

void label(int n, char game[n][n]){
    for(int a=0;a<1;a++){
        int c=0;
        for(int b=1;b<n;b+=2){
            game[a][b]='A'+c;
            c++;
        }
    }
    
    for(int b=0;b<1;b++){
        int c=0;
        for(int a=1;a<n;a+=2){
            game[a][b]='a'+c;
            c++;
        }
    }
    for(int a=0;a<1;a++){
        int c=0;
        for(int b=2;b<n;b+=2){
            game[a][b]='1'+c;
            c++;
        }
    }
    
    for(int b=0;b<1;b++){
        int c=0;
        for(int a=2;a<n;a+=2){
            game[a][b]='1'+c;
            c++;
        }
    }
    for(int a=1;a<n;a+=2){
        for(int b=1;b<n;b+=2){
            game[a][b]='.';
        }
    }
}

void basicprint(int n, char game[n][n]){
    for(int a=0;a<n;a++){
        for(int b=0;b<n;b++){
            printf("%c",game[a][b]);
        }
        printf("\n");
    }
}

void position(struct p p,int n,int* posX,int* posY,char* P){
    int aux=1;
    for(char a='A';a<'A'+(n/2);a++){
        if(p.x==a){
            *posX=aux;
            *posY=p.y*2;
            *P='H';
        }
        aux+=2;
    }
    
    aux=1;
    
    for(char a='a';a<'a'+(n/2);a++){
        if(p.x==a){
            *posX=aux;
            *posY=p.y*2;
            *P='V';
        }
        aux+=2;
    }
}

void play(char P,int n,char game[n][n],int posX, int posY, int* erro2, int* playing){
    if(P=='V'){
        if(game[posX][posY]==' '){
            game[posX][posY]='-';
            *erro2=1;
            (*playing)++;
        }
        else if(game[posX][posY]!=' '){
            printf("Posição não disponivel. Tente novamnete.\n");
            *erro2=0;
        }
    }
    else if(P=='H'){
        if(game[posY][posX]==' '){
            game[posY][posX]='|';
            *erro2=1;
            (*playing)++;
        }
        else if(game[posY][posX]!=' '){
            printf("Posição não disponivel. Tente novamente.\n");
            *erro2=0;
        }
    }
}

void markpoint(int n,char game[n][n],char player[2][20],int* turn){
    int point=0, again=0;
    for(int a=2;a<n;a+=2){
        for(int b=2;b<n;b+=2){
            if(game[a][b-1]=='|'){
                point++;
            }
            if(game[a][b+1]=='|'){
                point++;
            }
            if(game[a-1][b]=='-'){
                point++;
            }
            if(game[a+1][b]=='-'){
                point++;
            }
            if(point == 4 && game[a][b]==' '){
                game[a][b]=player[*turn][0];
                again=1;
            }
            //printf("\n%d",point);
            point=0;
        }
    }
    if(*turn==0 && again==1){ 
        *turn=1;
    }
    else{
        if(*turn==1 && again==1){ 
            *turn=0;
                        
        }
    } 
}

void winner(int n,char game[n][n],char player[2][20]){
    
    int p1=0,p2=0;
    for(int a=2;a<n;a+=2){
        for(int b=2;b<n;b+=2){
            if(game[a][b]==player[0][0]){
                p1++;
            }
            if(game[a][b]==player[1][0]){
                p2++;
            }
        }
    }
    if(p1>p2){
        printf("Player %d: %s, Venceu!\n",1,player[0]);
    }
    else if(p1<p2){
        printf("Player %d: %s, Venceu!\n",2,player[1]);
    }
    else if(p1==p2){
        printf("EMPATE!!\n");
    }
    printf("%s, %d pontos.\n%s, %d pontos.",player[0],p1,player[1],p2);
}

int main()
{
    int n; //size of the game
    
    for(int erro3=0;erro3<1;){
        printf("Escolha um tamanho para a matriz game[n]x[n] de 1 á 9:\n");
        scanf("%d",&n);
        if(n<1 || n>9){
            erro3=0;
            printf("Numero fora do limite permitido. Tente novamente!\n");
        }
        else{
            erro3=1;
        }
    }
    n=(2+(2*n));
    
    char game[n][n]; //matrix of the game
    char player[2][20]; //name of players
    int posX, posY; //position of play([][])
    struct p p; //position of play(Aa1)
    char P; //(V or H)
    int playing=0;
    char GAME[300];
    char TEMP[100];
    
    for(int i=0;i<2;i++){
        
        printf("Name of Player %d:\n",i+1);
        scanf(" %19[^\n]",player[i]);
        
        if(player[0][0]==player[1][0]){
            printf("Nomes com iniciais iguais, tente colocar outro nome.\n");
            i=-1;
            memset(player, 0, sizeof(player));
        }
        else{
            printf("Player %d: %s cadastrado!\n",i+1,player[i]);
        }
    }
    
    empty(n,game); //clean the matrix
    label(n,game); //label the matrix(Aa1.)
    basicprint(n,game); //print without format
    
    int turn=0,erro2=0;
    
    while(playing< n*((n-2)/2)){
        
        //printf("playing = %d\n",playing);
        
            for(int i=0;i<2;i++){
                
                for(;erro2!=1;){
                
                    for(int erro1=0;erro1<2;){
                        printf("Player %d: %s, escolha uma posição de jogada:\n",i+1,player[turn]);
                        scanf(" %c%d",&p.x,&p.y); //pick a letter and a number
                        //printf("%c%d",p.x,p.y); //check!!
                        
                        erro1=0;//reset
                        for(int a=0;a<(n/2);a++){
                            //printf("%c %c\n",'A'+a,'a'+a);
                            if(p.x=='A'+a || p.x=='a'+a){
                                erro1++;
                            }
                        }
                        for(int b=0;b<((n/2)-1);b++){
                            //printf("%d\n",1+b);
                            if(p.y==1+b){
                                erro1++;
                            }
                        }
                        
                        //printf("erro1=%d\n",erro1);
                        if(erro1<2){
                            printf("Posição de jogada invalida. Tente novamente.\n\n");
                        }
                    
                    }
                    //printf("%d",erro2);
                    
                    position(p,n,&posX,&posY,&P); //get the position at matrix
                    //printf("\nposX=%d posY=%d P=%c\n\n",posX,posY,P); //check!!
                    
                    play(P,n,game,posX,posY,&erro2,&playing);//put - or |;
                    //basicprint(n,game);
                    
                    //printf("aaa-teste-aaa\n");
                    
                }
                
                erro2=0;//reset 
                
                markpoint(n,game,player,&turn);

                printf("\033[H\033[J");

                basicprint(n,game);
                
                // troca de jogador
                if(turn==0){ turn=1;}
                else{
                    if(turn==1){ turn=0;}
                }  
            }
        
    }
    
    printf("FIM DE JOGO!\n");
    winner(n,game,player);
    
    
    return 0;
}
