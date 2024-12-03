// Utilize uma lista estática como a que implementamos em sala de aula, com 50 slots;
// a. Crie uma nova função de inserção de dados na lista de inteiros, garantindo que o novo elemento x seja inserido antes do valor 
// maior que ele e depois do valor menor que ele, para que a lista sempre fique em ordem crescente;
// b. Crie uma outra função que garanta a inserção de números em ordem decrescente. Inspire-se na letra anterior;

#include <stdio.h>
#include <string.h>

void inserirOrdenadoCrescente(ListaEstatica *l1, int elemento) {
    int i = l1->tamanho;
    while (i > 0 && l1->dados[i - 1] > elemento) {
        l1->dados[i] = l1->dados[i - 1];
        i--;
    }
    l1->dados[i] = elemento;
    l1->tamanho++;
}

void inserirOrdenadoDecrescente(ListaEstatica *l1, int elemento) {
    int i = l1->tamanho;
    while (i > 0 && l1->dados[i - 1] < elemento) {
        l1->dados[i] = l1->dados[i - 1];
        i--;
    }
    l1->dados[i] = elemento;
    l1->tamanho++;
}