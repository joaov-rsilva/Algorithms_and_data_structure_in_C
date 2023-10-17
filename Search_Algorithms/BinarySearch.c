#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//Para mudar o tamanho do vetor e da faixa de valores pseudoaleatórios basta alterar
//o valor das constantes abaixo
#define MAX_VECTOR_SIZE 100
#define RANGE_OF_RANDOM_VALUES 100

void FSelectSort(int a[]){
    int swap;
    for(int i = 0; i < (MAX_VECTOR_SIZE - 1); i++){
       for(int j = (i+1); j < MAX_VECTOR_SIZE; j++){
            if(a[i] > a[j]){
                swap = a[i];
                a[i] = a[j];
                a[j] = swap;
            }
       }
    }
}

int main(){

    int ListOfValues[MAX_VECTOR_SIZE];
    srand(time(NULL)); //Usado para inicializar o gerador de valores pseudoaleatórios

    for(int i = 0; i < MAX_VECTOR_SIZE; i++){              //Bloco com propósito de preencher
        ListOfValues[i] = rand() % RANGE_OF_RANDOM_VALUES; //nosso vetor com os valores
    }                                                      //pseudoaleatórios

    //Para que seja possivel realizarmos a busca binária primeiro temos de ordenar o vetor
    //onde será realizado a busca, para tal fiz o uso do algoritmo de ordenação Select Sort
    FSelectSort(ListOfValues);

    //Após ralizarmos a ordenção podemos começar a busca binária

    int SearchValue;
    printf("Digite o valor que deseja buscar no vetor: ");
    scanf("%d", &SearchValue);

    int Flag = 0, Min = 0, Max = MAX_VECTOR_SIZE, Middle;
    while((Flag == 0) && (Min <= Max)){
        //Aqui encontramos o meio do vetor
        Middle = (int)((Min + Max)/2);
        //Logo em seguida verificamos se o vetor na posição Middle (Meio) é igual ao valor de busca.
        //Caso sim, encerramos o laço de repetição aqui.
        if(ListOfValues[Middle] == SearchValue){
            Flag = 1;
            break;
        }else{
            //Caso não, verificamos se o valor de busca é menor do que o valor presente na posição 
            //Middle (Meio)
            if(SearchValue < ListOfValues[Middle]){
                //Caso o valor de busca seja menor, descartamos todos os valores de Middle (Meio)
                //'para cima' do vetor e atribuimos a variével Max o valor de Middle - 1,
                //para então verificarmos os valores de Min = 0 até Mix = Middle - 1
                Max = Middle - 1;
            }else{
                //Caso o valor de busca seja maior, descartamos todos os valores de Middle (Meio)
                //'para baixo' do vetor e atribuimos a variével Min o valor de Middle + 1,
                //para então verificarmos os valores de Min = Middle + 1 até Max = MAX_VECTOR_SIZE
                Min = Middle + 1;
            }
        }
        //O loop se repete até que o valor de busca seja encontrado, mudando o valor da variável 
        //Flag ou Min > Max (que indica que o valor de busca não foi entrado dentro do vetor)

    }

    if(Flag == 1){
        printf("A primeira ocorrência do valor encontra-se na posição %d do vetor.\n", Middle);
    }else{
        printf("O valor digitado não encontra-se no vetor.\n");
    }

    return 0;
}
