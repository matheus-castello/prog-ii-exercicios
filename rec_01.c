# include <stdio.h>

void ImprimeInvertido(char* string);

void ImprimeInvertido(char* string) {
    int i;
    for (i = 0; string[i] != '\0'; i++) {}

    if (i > 0) {
        printf("%c", string[i - 1]);
        string[i - 1] = '\0';
        ImprimeInvertido(string);
    } else {
        printf(" ");
    }
}

int main(void) {
    char palavras[500][1001];
    int i, n = 0;

    while (scanf("%s", palavras[n]) == 1) {
        n++;
    }

    for (i = 0; i < n; i++) {
        ImprimeInvertido(palavras[i]);
    }

    return 0;
}