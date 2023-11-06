
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


struct players{
    char player[30];
    char opc[20];
};

void winner(char ttt[9][3],struct players p[2], int *playing){
    for(int a=0;a<2;){
        if(strcmp(ttt[0], p[a].opc) == 0 && strcmp(ttt[4], p[a].opc) == 0 && strcmp(ttt[8], p[a].opc) == 0){
            printf("Jogador: %s venceu!\n",p[a].player);
            (*playing)=100;
            a=10;
        }
        else{
            if(strcmp(ttt[2], p[a].opc) == 0 && strcmp(ttt[4], p[a].opc) == 0 && strcmp(ttt[6], p[a].opc) == 0){
                printf("Jogador: %s venceu!\n",p[a].player);
                (*playing)=100;
                a=10;
            }
            else{
                for(int b = 0; b < 3; b++){
                    if(strcmp(ttt[0+(b*3)], p[a].opc) == 0 && strcmp(ttt[1+(b*3)], p[a].opc) == 0 && strcmp(ttt[2+(b*3)], p[a].opc) == 0){
                    printf("Jogador: %s venceu!\n",p[a].player);
                    (*playing)=100;
                    a=10;
                    }
                    else{
                        if(strcmp(ttt[0+b], p[a].opc) == 0 && strcmp(ttt[3+b], p[a].opc) == 0 && strcmp(ttt[6+b], p[a].opc) == 0){
                            printf("Jogador: %s venceu!\n",p[a].player);
                            (*playing)=100;
                            a=10;
                        }
                        else{
                            a++;
                        }
                    }
                }
            }
        }
    }
}

void printar(char ttt[9][3],struct players p[2]){
    
    char formattt[200];
    char tempttt[10];
           
        printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);   
           
        snprintf(formattt, sizeof(formattt), ". |  1 |  2 |  3 |\n");
        for (int u = 0; u < 3; u++) {
            snprintf(tempttt, sizeof(tempttt), "%c |", 'A' + u);
            strcat(formattt, tempttt);
               
            for (int v = 0; v < 3; v++) {
                snprintf(tempttt, sizeof(tempttt), " %s |", ttt[u * 3 + v]);
                strcat(formattt, tempttt);
            }

            strcat(formattt, "\n");
        }
       
        printf("%s", formattt);
           
}

int main() {
    int np;//numero de jogadores
    struct players p[2]; //ṕara cada jogador
    int menu=1;
    
    
    while(menu==1){
    printf("Bem vindo ao Tic Tac Toe, Quantos jogadores? 1 ou 2?\n");
    scanf("%d",&np);
    
    // se numero de jogadores for diferente de um ou dois
    if(np != 1 && np != 2){
        printf("Numeros de jogadores invalido!\n");
        menu = 0;
    }
    
    //dois jogadores
    else{
    if(np == 2){
        for(int a=0;a<2;a++){
            printf("Escreva o nome do Jogador %d: ",a+1);
            scanf(" %29[^\n]",p[a].player);
            printf("%s, cadastrado!\n",p[a].player);
        }
        
        usleep(2000000);
    
        int erro=1;
        for(int a=0;a<erro;a++){
            printf("\033[H\033[J");
            printf("Jogador 1: %s, Voce escolhe, O ou X?\n",p[0].player);
            scanf(" %s",p[0].opc);
           
            if(strcmp(p[0].opc, "o")==0 || strcmp(p[0].opc, "O")==0 ){
                strcpy(p[0].opc, " O");
                strcpy(p[1].opc, " X");
                printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);}
            else{
                if(strcmp(p[0].opc, "x")==0 || strcmp(p[0].opc, "X")==0 ){
                    strcpy(p[0].opc, " X");
                    strcpy(p[1].opc, " O");
                    printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);
                }
                else{
                    if(strcmp(p[0].opc, "o")!=0 || strcmp(p[0].opc, "O")!=0 || strcmp(p[0].opc, "x")!=0 || strcmp(p[0].opc, "O")!=0 ){
                        printf("Opcao invalida!\n");
                        usleep(2000000);
                        erro++;
                    }
                }
            }
        }
        char play[10];
        usleep(2000000);
        printf("\033[H\033[J");
        printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);
        printf(" .| 1  | 2  | 3  |\nA | a1 | a2 | a3 |\nB | b1 | b2 | b3 |\nC | c1 | c2 | c3 |\n");
       
        char ttt[9][3] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
       
        //jogadas
        int playing=0;
        int x=0;
        while(playing<9){
           
            int erro2 = 1;
            for(int i=0;i<erro2;i++){
               
                printf("%s, escolha uma letra e um numero: ",p[x].player);
                scanf(" %9[^\n]",play);
                //printf("%s\n",play);
                int counter=0;
               
                for(int a=0;a<9;a++){
                    //printf(" %s = %s\n",play,ttt[a]);
                    if(strcmp(play, ttt[a]) == 0){
                        strcpy(ttt[a], p[x].opc);
                        playing++;
                    }
                    else{
                        if(strcmp(play, ttt[a]) != 0){
                        counter++;
                        //printf("%d",counter);
                        }
                    }
                   
                }
                if(counter>=9){
                        erro2++;
                        printf("Jogada Invalida! Tente novamente.\n");
                }  
               
            }
            
            //ganhou?
            usleep(2000000);
            printf("\033[H\033[J");
            winner(ttt,p,&playing);
           
            //print
            printar(ttt,p);
        
            // troca de jogador
            if(x==0){ x=1;}
            else{
                if(x==1){ x=0;}
            }  
        }//fim do playing
        
        if(playing==9){
            printf("Deu velha! Ninguem ganhou.");
        }
    } //fim dois jogadores
    
    else{ //um jogador
    if(np == 1){
   
        printf("Escreva o nome do Jogador: ");
        scanf(" %29[^\n]",p[0].player);
        strcpy(p[1].player, "Computador");
        int auxx=1;   
        
        int erro=1;
        for(int a=0;a < erro;a++){
            printf("Jogador: %s, Voce escolhe, O ou X?\n",p[0].player);
            scanf(" %s",p[0].opc);
            if(strcmp(p[0].opc, "o")==0 || strcmp(p[0].opc, "O")==0 ){
                strcpy(p[0].opc, " O");
                strcpy(p[1].opc, " X");
                printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);
            }
            else{
                if(strcmp(p[0].opc, "x")==0 || strcmp(p[0].opc, "X")==0 ){
                    strcpy(p[0].opc, " X");
                    strcpy(p[1].opc, " O");
                    printf("%s: %s\n%s: %s\n\n",p[0].player,p[0].opc,p[1].player,p[1].opc);
                }
                else{
                    if(strcmp(p[0].opc, "o")!=0 || strcmp(p[0].opc, "O")!=0 || strcmp(p[0].opc, "x")!=0 || strcmp(p[0].opc, "O")!=0 ){
                        printf("Opcao invalida!\n");
                        erro++;
                    }
                }
            }
        }
        
        char play[10];    
        printf(" | 1 | 2 | 3 |\nA | a1 | a2 | a3 |\nB | b1 | b2 | b3 |\nC | c1 | c2 | c3 |\n");
       
        char ttt[9][3] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
        char tttAUX[9][3] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
       
        //jogadas
        int playing=0;
       
        while(playing<9){
            
            int erro2 = 1;
            for(int i=0;i<erro2;i++){
               
                printf("%s, escolha uma letra e um numero: ",p[0].player);
                scanf("%s",play);
                int counter=0;
               
                for(int a=0;a<9;a++){
                    //printf(" %s = %s\n",play,ttt[a]);
                    if(strcmp(play, ttt[a]) == 0){
                        strcpy(ttt[a], p[0].opc);
                        playing++;
                    }
                    else{
                        if(strcmp(play, ttt[a]) != 0){
                        counter++;
                        }
                    }
                    if(counter>=9){
                        erro2++;
                        printf("Jogada Invalida! Tente novamente.\n");
                    }    
                   
                }
               
            }
            
            //ganhou?
            winner(ttt,p,&playing);
           
            //print
            printar(ttt,p);
            
            // troca de jogador
           
            while(auxx==1){
       
            printf("Computador jogando...\n");
           
            playing++;
            const int opcoes[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
            int nOp = sizeof(opcoes) / sizeof(opcoes[0]);
           
            int erro3=1;
            for(int i=0;i<erro3;i++){
           
                int random = rand() % nOp;
                strcpy(play, tttAUX[random]);
                int counter=0;
           
                for(int a=0;a<9;a++){
           
                    //printf(" %s = %s\n",play,ttt[a]);
                    if(strcmp(play, ttt[a]) == 0){
                        strcpy(ttt[a], p[1].opc);
                    }
                    else{
                        if(strcmp(play, ttt[a]) != 0){
                        counter++;
                        }
                    }
                    if(counter>=9){
                        erro3++;
                        //printf("Jogada Invalida! Tente novamente.\n");
                    }    
                }
            }
            
            //ganhou?
            winner(ttt,p,&playing);
           
            //print
            printar(ttt,p);
            
            }//fim do aux
        }//fim do playing
    
        if(playing==9){
            printf("Deu velha! Ninguem ganhou.");
        }
    
    }}}//fim do jogador um
    
    if(menu != 0){
        printf("Fim do Jogo!");
        printf("Deseja jogar novamente?\nDigite 1 para Sim ou 2 para Nao:\n");
        scanf("%d",&menu);
        usleep(2000000);
        printf("\033[H\033[J");
    }
   
    }// menu
    if(menu == 2){
        printf("Obrigada por Jogar!\nAte a proxima!");
    }
    
return 0;
}
main.c
Displaying main.c.
