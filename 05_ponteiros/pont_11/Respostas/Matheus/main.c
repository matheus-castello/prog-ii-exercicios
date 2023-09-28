#include <stdio.h>
#include "calculadora.h"

float Adicao(float num1, float num2) {
    return num1 + num2;
}

float Subtracao(float num1, float num2) {
    return num1 - num2;
}

float Multiplicacao(float num1, float num2) {
    return num1 * num2;
}

float Divisao(float num1, float num2) {
    return num1 / num2;
}

int main(void) {
    char operacao;
    scanf("%c\n", &operacao);
    float num1, num2;
    CalculatoraCallback callback = NULL;

    while (operacao != 'f') {
        scanf("%f%f\n", &num1, &num2);

        printf("%.2f ", num1);
        switch (operacao) {
            case 'a':
                callback = Adicao;
                printf("+");
                break;
            case 's':
                callback = Subtracao;
                printf("-");
                break;
            case 'm':
                callback = Multiplicacao;
                printf("x");
                break;
            case 'd':
                callback = Divisao;
                printf("/");
                break;
            default:
                return 1;
        }
        printf(" %.2f = ", num2);

        printf("%.2f\n", Calcular(num1, num2, callback));
        scanf("%c\n", &operacao);
    }

    return 0;
}
