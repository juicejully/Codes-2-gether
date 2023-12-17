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

void hor2same(int *erro4, int *auxx,char ttt[9][3],struct players p[2]){
    
    //printf("ERRO1");
    
    //computing can win?
    for(int i=0;i<9;i+=3){
        if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[i+1]) == 0 && strcmp(ttt[2+i],p[1].opc) != 0 && strcmp(ttt[2+i],p[0].opc) != 0){
                            
            strcpy(ttt[2+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[i+1],p[1].opc) == 0 && strcmp(ttt[i+1],ttt[i+2]) == 0 && strcmp(ttt[0+i],p[1].opc) != 0 && strcmp(ttt[0+i],p[0].opc) != 0){
            strcpy(ttt[0+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[i+2]) == 0 && strcmp(ttt[1+i],p[1].opc) != 0 && strcmp(ttt[1+i],p[0].opc) != 0){
            strcpy(ttt[1+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
    }
    
    //player can win?
    if(*erro4==0){
        for(int i=0;i<9;i+=3){
            if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[i+1]) == 0 && strcmp(ttt[2+i],p[1].opc) != 0 && strcmp(ttt[2+i],p[0].opc) != 0){
                                
                strcpy(ttt[2+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[i+1],p[0].opc) == 0 && strcmp(ttt[i+1],ttt[i+2]) == 0 && strcmp(ttt[0+i],p[1].opc) != 0 && strcmp(ttt[0+i],p[0].opc) != 0){
                strcpy(ttt[0+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[i+2]) == 0 && strcmp(ttt[1+i],p[1].opc) != 0 && strcmp(ttt[1+i],p[0].opc) != 0){
                strcpy(ttt[1+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
        }
    }
    
}

void vert2same(int *erro4, int *auxx,char ttt[9][3],struct players p[2]){
    
    //printf("ERRO2");
    
    //computer can win?
    for(int i=0;i<3;i++){
        if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[i+3]) == 0 && strcmp(ttt[6+i],p[1].opc) != 0 && strcmp(ttt[6+i],p[0].opc) != 0){
            strcpy(ttt[6+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[i+6]) == 0 && strcmp(ttt[3+i],p[1].opc) != 0 && strcmp(ttt[3+i],p[0].opc) != 0){
            strcpy(ttt[3+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[i+3],p[1].opc) == 0 && strcmp(ttt[i+3],ttt[i+6]) == 0 && strcmp(ttt[0+i],p[1].opc) != 0 && strcmp(ttt[0+i],p[0].opc) != 0){
            strcpy(ttt[0+i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
    }
    
    //player can win?
    if(*erro4==0){
        
        for(int i=0;i<3;i++){
            if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[i+3]) == 0 && strcmp(ttt[6+i],p[1].opc) != 0 && strcmp(ttt[6+i],p[0].opc) != 0){
                strcpy(ttt[6+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[i+6]) == 0 && strcmp(ttt[3+i],p[1].opc) != 0 && strcmp(ttt[3+i],p[0].opc) != 0){
                strcpy(ttt[3+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[i+3],p[0].opc) == 0 && strcmp(ttt[i+3],ttt[i+6]) == 0 && strcmp(ttt[0+i],p[1].opc) != 0 && strcmp(ttt[0+i],p[0].opc) != 0){
                strcpy(ttt[0+i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
        }
    }
}

void diag2same(int *erro4, int *auxx,char ttt[9][3],struct players p[2]){
    
    //printf("ERRO3");
    
    //computer can win?
    for(int i=0;i<3;i+=2){
        if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[4]) == 0 && strcmp(ttt[8-i],p[1].opc) != 0 && strcmp(ttt[8-i],p[0].opc) != 0){
            strcpy(ttt[8-i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[4],p[1].opc) == 0 && strcmp(ttt[4],ttt[8-i]) == 0 && strcmp(ttt[i],p[1].opc) != 0 && strcmp(ttt[i],p[0].opc) != 0){
            strcpy(ttt[i],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
        else if(strcmp(ttt[i],p[1].opc) == 0 && strcmp(ttt[i],ttt[8-i]) == 0 && strcmp(ttt[4],p[1].opc) != 0 && strcmp(ttt[4],p[0].opc) != 0){
            strcpy(ttt[4],p[1].opc);
            *erro4=1;
            *auxx=0;
            i=10;
        }
    }
    
    //player can win?
    if(*erro4==0){
        for(int i=0;i<3;i+=2){
            if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[4]) == 0 && strcmp(ttt[8-i],p[1].opc) != 0 && strcmp(ttt[8-i],p[0].opc) != 0){
                strcpy(ttt[8-i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[4],p[0].opc) == 0 && strcmp(ttt[4],ttt[8-i]) == 0 && strcmp(ttt[i],p[1].opc) != 0 && strcmp(ttt[i],p[0].opc) != 0){
                strcpy(ttt[i],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
            else if(strcmp(ttt[i],p[0].opc) == 0 && strcmp(ttt[i],ttt[8-i]) == 0 && strcmp(ttt[4],p[1].opc) != 0 && strcmp(ttt[4],p[0].opc) != 0){
                strcpy(ttt[4],p[1].opc);
                *erro4=1;
                *auxx=0;
                i=10;
            }
        }
    }
}

void not2same(int *erro4, int *auxx,char ttt[9][3],struct players p[2]){
    
    //printf("ERRO4");
    if(strcmp("b2",ttt[4]) == 0){
        strcpy(ttt[4], p[1].opc);
        *auxx=0;
        *erro4=1;
    }
    else{
        int vector[8] = {0,2,6,8,1,3,5,7};
        for(int a=0;a<8;a++){
            if(strcmp(ttt[vector[a]],p[1].opc) != 0 && strcmp(ttt[vector[a]],p[0].opc) != 0){
                strcpy(ttt[vector[a]], p[1].opc);
                *auxx=0;
                *erro4=1;
                a=100;
            }
        }
    }
}

void onePlayerEasy(struct players p[2]){
    
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
        printf("  | 1  | 2  | 3  |\nA | a1 | a2 | a3 |\nB | b1 | b2 | b3 |\nC | c1 | c2 | c3 |\n");
       
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
                        auxx=1;
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
            
            while(auxx==1 && playing<9){
       
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
                        auxx=0;
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
            
            printf("\033[H\033[J");
           
            //print
            printar(ttt,p);
            
            }//fim do aux
        }//fim do playing
    
        if(playing==9){
            printf("Deu velha! Ninguem ganhou.");
        }
}

void onePlayerHard(struct players p[2]){
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
    printf("  | 1  | 2  | 3  |\nA | a1 | a2 | a3 |\nB | b1 | b2 | b3 |\nC | c1 | c2 | c3 |\n");
       
    char ttt[9][3] = {"a1", "a2", "a3", "b1", "b2", "b3", "c1", "c2", "c3"};
        
    //jogadas
    int playing=0;
       
    while(playing<9){
            
        int erro2 = 1;
        int erro4=0;
            
        for(int i=0;i<erro2;i++){
               
            printf("%s, escolha uma letra e um numero: ",p[0].player);
            scanf("%s",play);
            int counter=0;
               
            for(int a=0;a<9;a++){
                //printf(" %s = %s\n",play,ttt[a]);
                if(strcmp(play, ttt[a]) == 0){
                    strcpy(ttt[a], p[0].opc);
                    playing++;
                    auxx=1;
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
        
        while(auxx==1 && playing<9){
            
            printf("Computador jogando...\n");
            playing++;
            
            printf("erro41: %d\n",erro4);
            //hor 2same
            if(erro4==0){
                hor2same(&erro4,&auxx,ttt,p);
            }
            
            printf("erro42: %d\n",erro4);        
            //vert 2same
            if(erro4==0){
                vert2same(&erro4,&auxx,ttt,p);        
            }
            
            printf("erro43: %d\n",erro4);        
            //dia 2same
            if(erro4==0){
                diag2same(&erro4,&auxx,ttt,p);       
            }
            
            printf("erro44: %d\n",erro4);        
            //not 2same
            if(erro4==0){
                not2same(&erro4,&auxx,ttt,p);        
                    
            }
            
            printf("erro45: %d\n",erro4);
            //printf("\033[H\033[J");
            
            //ganhou?
            winner(ttt,p,&playing);
                
            //print
            printar(ttt,p);
            
        }//fim do aux
        
            
    }//fim do playing
    
    if(playing==9){
        printf("Deu velha! Ninguem ganhou.");
    }
    
}

void twoPlayer(struct players p[2]){
    for(int a=0;a<2;a++){
            printf("Escreva o nome do Jogador %d: ",a+1);
            scanf(" %29[^\n]",p[a].player);
            printf("%s, cadastrado!\n",p[a].player);
        }
        
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
        usleep(20000);
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
            usleep(20000);
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
}

int main() {
    int np,one;//numero de jogadores e nivel de jogo;
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
        twoPlayer(p);
        usleep(20000);
    
        
    } //fim dois jogadores
    
    else{ //um jogador
    if(np == 1){
        printf("Qual versão?\n1- Facil\n2- Dificil\n");
        scanf("%d",&one);
        if(one==1){
            onePlayerEasy(p);
        }
        else if(one==2){
            onePlayerHard(p);
        }
       
        
    }}}//fim do jogador um
    
    if(menu != 0){
        printf("Fim do Jogo!");
        printf("Deseja jogar novamente?\n1-Sim\n2-Nao\n");
        scanf("%d",&menu);
        usleep(20000);
        printf("\033[H\033[J");
    }
   
    }// menu
    if(menu == 2){
        printf("Obrigada por Jogar!\nAte a proxima!");
    }
    
return 0;
}




