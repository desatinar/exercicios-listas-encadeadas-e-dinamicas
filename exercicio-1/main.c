// Dada uma lista sequencial ordenada estática L1, escreva métodos em C que:
// a. Verifique se L1 está ordenada ou não (a ordem pode ser crescente ou decrescente)
// b. Faça uma cópia da lista L1 em uma outra lista L2;
// c. Faça uma cópia da Lista L1 em L2, eliminando elementos repetidos;
// d. Inverta L1 colocando o resultado em L2;
// e. Inverta L1 colocando o resultado na própria L1;
// f. Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 são ordenadas.
// g. Gere uma lista L2 onde cada registro contém dois campos de informação: elem contém um elemento de L1, 
// e count contém quantas vezes este elemento aparece em L1.
// h. Elimine de L1 todas as ocorrências de um elemento dado, L1 ordenada.
// i. Assumindo que os elementos da lista L1 são inteiros positivos, forneça os elementos que 
// aparecem o maior e o menor número de vezes (forneça os elementos e o número de vezes correspondente)

#include <stdio.h>
#include <string.h>

typedef struct {
    int dados[50];
    int tamanho;
} ListaEstatica;

void verificarOrdenacao(ListaEstatica l) {
    int crescente = 1, decrescente = 1;
    for (int i = 0; i < l.tamanho - 1; i++) {
        if (l.dados[i] > l.dados[i + 1]) crescente = 0;
        if (l.dados[i] < l.dados[i + 1]) decrescente = 0;
    }
    if (crescente) printf("Crescente\n");
    else if (decrescente) printf("Decrescente\n");
    else printf("Nao ordenada\n");
}

void copiarLista(ListaEstatica l1, ListaEstatica *l2) {
    l2->tamanho = l1.tamanho;
    for (int i = 0; i < l1.tamanho; i++) {
        l2->dados[i] = l1.dados[i];
    }
}

void copiarSemRepetir(ListaEstatica l1, ListaEstatica *l2) {
    l2->tamanho = 0;
    for (int i = 0; i < l1.tamanho; i++) {
        int repetido = 0;
        for (int j = 0; j < l2->tamanho; j++) {
            if (l2->dados[j] == l1.dados[i]) repetido = 1;
        }
        if (!repetido) l2->dados[l2->tamanho++] = l1.dados[i];
    }
}

void inverterLista(ListaEstatica l1, ListaEstatica *l2) {
    l2->tamanho = l1.tamanho;
    for (int i = 0; i < l1.tamanho; i++) {
        l2->dados[i] = l1.dados[l1.tamanho - 1 - i];
    }
}

void inverterListaPropria(ListaEstatica *l1) {
    for (int i = 0; i < l1->tamanho / 2; i++) {
        int temp = l1->dados[i];
        l1->dados[i] = l1->dados[l1->tamanho - 1 - i];
        l1->dados[l1->tamanho - 1 - i] = temp;
    }
}

void intercalarListas(ListaEstatica l1, ListaEstatica l2, ListaEstatica *l3) {
    int i = 0, j = 0, k = 0;
    while (i < l1.tamanho && j < l2.tamanho) {
        if (l1.dados[i] < l2.dados[j]) l3->dados[k++] = l1.dados[i++];
        else l3->dados[k++] = l2.dados[j++];
    }
    while (i < l1.tamanho) l3->dados[k++] = l1.dados[i++];
    while (j < l2.tamanho) l3->dados[k++] = l2.dados[j++];
    l3->tamanho = k;
}

void contarElementos(ListaEstatica l1, ListaEstatica *l2) {
    l2->tamanho = 0;
    for (int i = 0; i < l1.tamanho; i++) {
        int index = -1;
        for (int j = 0; j < l2->tamanho; j++) {
            if (l2->dados[j] == l1.dados[i]) index = j;
        }
        if (index == -1) {
            l2->dados[l2->tamanho++] = l1.dados[i];
        }
    }
}

void eliminarElemento(ListaEstatica *l1, int elemento) {
    int k = 0;
    for (int i = 0; i < l1->tamanho; i++) {
        if (l1->dados[i] != elemento) {
            l1->dados[k++] = l1->dados[i];
        }
    }
    l1->tamanho = k;
}

void maiorEMenorFrequencia(ListaEstatica l1) {
    int frequencia[50] = {0}, maior = 0, menor = l1.tamanho + 1, elemMaior, elemMenor;
    for (int i = 0; i < l1.tamanho; i++) {
        int pos = l1.dados[i];
        frequencia[pos]++;
    }
    for (int i = 0; i < 50; i++) {
        if (frequencia[i] > maior) {
            maior = frequencia[i];
            elemMaior = i;
        }
        if (frequencia[i] < menor && frequencia[i] > 0) {
            menor = frequencia[i];
            elemMenor = i;
        }
    }
    printf("Maior frequencia: %d (%d vezes)\n", elemMaior, maior);
    printf("Menor frequencia: %d (%d vezes)\n", elemMenor, menor);
}
