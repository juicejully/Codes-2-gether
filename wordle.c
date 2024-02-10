#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
   
    char nameAux[100]; // definindo a palavra a ser adivinhada
    printf("Escolha uma palavra:\n");
    scanf(" %s",nameAux);

    int n = strlen(nameAux), win = 0, N = 0, correct = 0, tent = 0; // variáveis
    char name[n+1], guess[n+1], secret[n+1], secret2[n+1];
    strcpy(name,nameAux);

    //printf("%s - %d",name,n);

    for(int i = 0; i < n; i++){
        secret[i] = '-';
    }
    for(int i = 0; i < n; i++){
        secret2[i] = '+';
    }

    secret[n] = '\0';
    secret2[n] = '\0';
    
    system("clear || cls");
    printf("A palavra secreta é:\n%s\n",secret);
    
    // ínício do jogo
    while(win == 0 || tent < (n+1)){
        correct = 0;

        printf("Tente adivinhar a palavra [%dª tentativa]: ", tent+1);
        scanf(" %s", guess);
        N = strlen(guess);

        // checar se o "tentativa" é válida
        if(N!=n){
            printf("A palavra inserida não é compatível. Ele deve ter %d letras!\n", n);
            continue;
        }
    
        system("clear || cls");
        tent++;

        for(int i=0;i<n;i++){
            secret2[i] = name[i];
        }   
         
        for(int i=0;i<n;i++){
            if(name[i]==guess[i]){ 
                secret2[i] = '+';
            }
        }   
        
        // iterar sobre as strings    
        for(int i=0;i<=n;i++){

            if(name[i]==guess[i]){ // verificar se a letra está na posição certa
                
                printf("\033[32m");
                printf("%c",guess[i]);
                printf("\033[0m");
                correct++;
            }
            else{
                int has=0;
                for(int a=0;a<n;a++){ // verificar se a letra existe mas não está na posição correta
                    if(guess[i]==secret2[a] && guess[i]!=name[i]){
                        
                        printf("\033[33m");
                        printf("%c",guess[i]);
                        printf("\033[0m");
                        has=1;
                        secret2[a]='+';
                        a=(n+1);
                        
                    }
                }
                if(has==0){
                    printf("%c",guess[i]);
                }
            }

        }
        printf("\n");

        // verificar se ganhou
        if(correct-1 == n){
            printf("Parabéns!! Você acertou a palavra na %dª tentativa.", tent);
            win = 1;
            tent = n+1;
        }
        else{
            N = 0;
        }

    }

    return 0;
}
