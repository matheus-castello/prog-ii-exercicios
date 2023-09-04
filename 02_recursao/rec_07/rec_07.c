# include <stdio.h>

int somaDigitos(int n);

int somaDigitos(int n) {
    int soma = n % 10;
    int m = n / 10;
    if (m == 0) {
        return soma;
    }
    return soma + somaDigitos(m);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", somaDigitos(n));
    
    return 0;
}
