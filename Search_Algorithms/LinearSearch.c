#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Para mudar o tamanho do vetor e da faixa de valores pseudoaleatórios basta alterar
//o valor das constantes abaixo
#define MAX_VECTOR_SIZE 100
#define RANGE_OF_RANDOM_VALUES 100

int main(){

    int ListOfValues[MAX_VECTOR_SIZE];

    srand(time(NULL));

    for(int i = 0; i < MAX_VECTOR_SIZE; i++){
        ListOfValues[i] = rand() % RANGE_OF_RANDOM_VALUES;
    }

    int SearchValue;
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &SearchValue);

    //Na busca linear percorremos toda extensão do vetor
    int Index = 0;
    for(int i = 0; i < MAX_VECTOR_SIZE; i++){
        //Comparamos o conteudo de cada uma das posições com o valor de busca
        if(ListOfValues[i] == SearchValue){
            //Assim que for encontrado podemos encerrar o loop
            Index = i;
            break;
        }
    }

    
    if(Index != 0){
        printf("A primeira ocorrência do valor encontra-se na posição %d do vetor.\n", Index);
    }else{
        printf("O valor digitado não encontra-se no vetor.\n");
    }

    return 0;
}