# include <stdio.h>

int palindromo(char *string, int tamanho);

int palindromo(char *string, int tamanho) {
    if (tamanho <= 1) {
        return 1;
    }

    if (string[0] == string[tamanho - 1]) {
        return palindromo(&string[1], tamanho - 2);
    } else {
        return 0;
    }
}

int main(void) {
    char palavra[33];
    int i;
    
    while(scanf("%s", palavra) == 1) {
        for (i = 0; palavra[i] != '\0'; i++) {}

        if (palindromo(palavra, i) == 1) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}
