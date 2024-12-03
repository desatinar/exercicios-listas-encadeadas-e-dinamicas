// Escreva uma função que verifique se uma lista encadeada que contém números inteiros está em ordem crescente.

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No *proximo;
} No;

int listaOrdenadaCrescente(No *inicio) {
    No *atual = inicio;
    while (atual != NULL && atual->proximo != NULL) {
        if (atual->valor > atual->proximo->valor) {
            return 0;
        }
        atual = atual->proximo;
    }
    return 1;
}

No *criarNo(int valor) {
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;
    return novo;
}

int main() {
    No *inicio = criarNo(1);
    inicio->proximo = criarNo(3);
    inicio->proximo->proximo = criarNo(5);

    if (listaOrdenadaCrescente(inicio)) {
        printf("A lista está em ordem crescente\n");
    } else {
        printf("A lista não está em ordem crescente\n");
    }

    No *atual = inicio;
    while (atual != NULL) {
        No *temp = atual;
        atual = atual->proximo;
        free(temp);
    }

    return 0;
}
