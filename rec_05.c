# include <stdio.h>

int fatorial(int n);

int fatorial(int n) {
    if (n == 1) {
        return 1;
    }

    return n * fatorial(n - 1);
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", fatorial(n));

    return 0;
}