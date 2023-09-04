# include <stdio.h>

int SomaElementosPares(int* vet, int numElementos);

int SomaElementosPares(int* vet, int numElementos) {
    if (numElementos == 0) {
        return 0;
    }

    int soma = 0;
    if (vet[0] % 2 == 0) {
        soma += vet[0];
    }

    return soma + SomaElementosPares(&vet[1], numElementos - 1);
}

int main(void) {
    int i, j, qtdVet;
    scanf("%d", &qtdVet);
    int numElementos[qtdVet];
    int vetores[qtdVet][7];

    for (i = 0; i < qtdVet; i++) {
        scanf("%d", &numElementos[i]);
        for (j = 0; j < numElementos[i]; j++) {
            scanf("%d", &vetores[i][j]);
        }
        printf("%d\n", SomaElementosPares(vetores[i], numElementos[i]));
    }
    
    return 0;
}