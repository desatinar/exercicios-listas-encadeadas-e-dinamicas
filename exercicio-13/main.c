// Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a subárvore direita pela subárvore esquerda de todos os nós da árvore

#include <stdio.h>
#include <stdlib.h>

struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
};

struct No* criarNo(int valor) {
    struct No* novo = (struct No*)malloc(sizeof(struct No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

void espelhar(struct No* raiz) {
    if (raiz == NULL) {
        return;
    }

    struct No* temp = raiz->esquerda;
    raiz->esquerda = raiz->direita;
    raiz->direita = temp;

    espelhar(raiz->esquerda);
    espelhar(raiz->direita);
}

void imprimirEmOrdem(struct No* raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

int main() {
    struct No* raiz = criarNo(1);
    raiz->esquerda = criarNo(2);
    raiz->direita = criarNo(3);
    raiz->esquerda->esquerda = criarNo(4);
    raiz->esquerda->direita = criarNo(5);
    raiz->direita->esquerda = criarNo(6);
    raiz->direita->direita = criarNo(7);

    printf("Árvore original em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    espelhar(raiz);

    printf("Árvore espelhada em ordem: ");
    imprimirEmOrdem(raiz);
    printf("\n");

    return 0;
}
