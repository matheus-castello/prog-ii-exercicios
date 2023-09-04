# include <stdio.h>

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado);

int ContaOcorrencias(int* vet, int numElementos, int numeroProcurado) {
    if (numElementos == 0) {
        return 0;
    }

    int soma = 0;
    if (vet[0] == numeroProcurado) {
        soma ++;
    }

    return soma + ContaOcorrencias(&vet[1], numElementos - 1, numeroProcurado);
}

int main(void) {
    int i, j, qtdVet;
    scanf("%d", &qtdVet);
    int numProcurado[qtdVet];
    int numElementos[qtdVet];
    int vetores[qtdVet][10];

    for (i = 0; i < qtdVet; i++) {
        scanf("%d", &numProcurado[i]);
        scanf("%d", &numElementos[i]);
        for (j = 0; j < numElementos[i]; j++) {
            scanf("%d", &vetores[i][j]);
        }
        printf("%d\n", ContaOcorrencias(vetores[i], numElementos[i], numProcurado[i]));
    }
    
    return 0;
}
