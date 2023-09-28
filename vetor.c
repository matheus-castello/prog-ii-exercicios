#include <stdio.h>
#include "vetor.h"

void LeVetor(Vetor *vetor){
    int i;

    scanf("%d", &vetor->tamanhoUtilizado);

    for (i = 0; i < vetor->tamanhoUtilizado; i++) {
        scanf("%d", &vetor->elementos[i]);
    }
}

int AplicarOperacaoVetor(Vetor *vetor, Operation op) {
    int i, valor = op(vetor->elementos[0], vetor->elementos[1]);

    for (i = 2; i < vetor->tamanhoUtilizado; i++) {
        valor = op(valor, vetor->elementos[i]);
    }

    return valor;
}