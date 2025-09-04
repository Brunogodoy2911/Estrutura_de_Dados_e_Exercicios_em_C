// 5. Passagem de Vetores por Referência
// • Objetivo: Entender que vetores são sempre passados por referência em C e como isso permite que funções os manipulem diretamente [Modularização.pdf, 389-394].
// • Tarefa: Crie um programa em C que:
//     1. Defina uma função inicializar_vetor que recebe como parâmetros um ponteiro para um vetor de inteiros (int *vet) e o tamanho do vetor (int n) [Modularização.pdf, 391].
//     2. Dentro de inicializar_vetor, use um laço de repetição para preencher todos os elementos do vetor com o valor 0.
//     3. Defina uma função imprimir_vetor que também recebe um ponteiro para um vetor de inteiros e seu tamanho, e imprime todos os seus elementos.
//     4. Na função main:
//         ▪ Declare um vetor de inteiros de tamanho fixo (ex: 5 posições, int meuVetor;).
//         ▪ Chame inicializar_vetor passando o vetor e seu tamanho para preenchê-lo.
//         ▪ Chame imprimir_vetor para exibir o conteúdo do vetor após a inicialização, confirmando que os valores foram alterados.
// • Dica: Em C, quando um vetor é passado como argumento para uma função, o que é efetivamente passado é o endereço de seu primeiro elemento, ou seja, uma passagem por referência [Modularização.pdf, 391].

#include <stdio.h>

void inicializar_vetor(int *vet, int n);

void imprimir_vetor(int *vet, int n);

int main()
{

    int vetor[5] = {0, 1, 2, 3, 4};
    int tamanho = 5;

    imprimir_vetor(vetor, tamanho);

    inicializar_vetor(vetor, tamanho);

    printf("--------- DADOS ALTERADOS ----------- \n");

    imprimir_vetor(vetor, tamanho);

    return 0;
}

void inicializar_vetor(int *vet, int n)
{

    int i;

    for (i = 0; i < n; i++)
    {
        vet[i] = 0;
    }
}

void imprimir_vetor(int *vet, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Indice[%d] = %d \n", i, vet[i]);
    }
}
