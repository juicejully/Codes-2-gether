
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int last(int a, char data[4][3][20]){
    
    int res, aux = 0;
    
    //printf("TEST1");
    
    for (int i = 0; i < 3; i++){ //testar as tres posicoes
        if (strcmp(data[a][i],"--") != 0){
    	    aux++;
    	}
    }
    //printf("aux: %d\n",aux);
    
    if (aux == 3){
        res = 0;
    }
    else{
        res = 1;
    }
    //printf("res: %d\n",res);
    return res;
}

void thelast(char winner[4][20], int a, char data[4][3][20]){
    
    //printf("Test2");
    
    for (int i = 0; i < 3; i++){ //testar as tres posicoes
        if (strcmp(data[a][i],"--") != 0){
            strcpy (winner[a], data[a][i]);
            strcpy (data[a][i], "--");
            //printf("final: %s\n",data[a][i]);
    	}
    }
}

int main (){
    int n;
    char data[4][3][20];

    printf ("Escolha três pretendentes: \n");
    for (int i = 0; i < 3; i++){
        printf ("%d: ", i + 1);
        scanf (" %19[^\n]", data[3][i]);
    }   

    printf ("Escolha três cidades: \n");
    for (int i = 2; i >= 0; i--){
        printf ("%d: ",-(i)+3);
        scanf (" %19[^\n]", data[1][i]);
    }
    
    int erro=1;
    while(erro==1){
        printf ("Com qual idade, você vai casar? (18 ~ 99)\n");
        scanf ("%d", &n);
        if(n<18 || n>99){
            printf("Escolha uma idade dentro da margem!!!!!!!\n");
        }
        if(n>=18 && n<=99){
            erro=0;
        }
    }

    strcpy (data[2][2], "pobre");
    strcpy (data[2][1], "rico");
    strcpy (data[2][0], "milionario");
    strcpy (data[0][0], "um filho");
    strcpy (data[0][1], "dois filhos");
    strcpy (data[0][2], "três filhos");

    char winner[4][20];

    int doze = 0;
    int a = 0, b = 0;	//stop will stop the looping when count=n; a and b will run the char data;
    
    while(doze<8){
        
        for (int count = 0; count < n;){	//this will be counting n times.
    
        //printf("BBB: ");
         
        //printf("%s\n",data[a][b]);
    
        if (strcmp(data[a][b],"--") != 0){	//testa se existe dados no vetor.
    	    count++;//se existe dados entao a contagem eh valida.
    	    //printf ("a: %d, b: %d, %s\n", a, b, data[a][b]);
    	}
    
        if (count == n){ //ultimo da contagem
    	    //printf("CCC");
    	    if (last (a, data) == 0){
    	        printf ("Eliminado: %s\n", data[a][b]);
    	        strcpy (data[a][b], "--");
    	    }
    	    else if (last (a, data) == 1){
    	        printf ("Eliminado: %s\n", data[a][b]);
    	        strcpy (data[a][b], "--");
    	        thelast(winner, a, data);
    	    }
    	}
        b++;
        if (b == 3){
    	    b = 0;
    	    a++;
    	}
            if (a == 4){
    	        a = 0;
    	    }
        }
        doze++;
    }
    printf("Voce vai casar com %s e morar em %s. Terão %s e serão %s.",winner[3],winner[1],winner[0],winner[2]);


    return 0;
}
