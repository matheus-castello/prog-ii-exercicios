# include <stdio.h>
# include "vetor.h"

int Adicao(int a, int b) {
    return a + b;
}

int Multiplicacao(int a, int b) {
    return a * b;
}

int main(void) {
    Operation adicao = Adicao;
    Operation multiplicacao = Multiplicacao;
    Vetor vetor;

    LeVetor(&vetor);
    
    printf("Soma: %d\n", AplicarOperacaoVetor(&vetor, adicao));
    printf("Produto: %d\n", AplicarOperacaoVetor(&vetor, multiplicacao));

    return 0;
}
