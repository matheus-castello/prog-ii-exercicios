# include <stdio.h>
# include "eleitor.h"
# include "voto.h"

int main(void) {
    int i, qtd, id, votoP, votoM, counterQtd = 0, votou, fraude = 0, vencP, vencM;
    tEleitor eleitores[18];
    tVoto votos = inicializaVotos();

    scanf("%d", &qtd);

    while(scanf("%d%d%d", &id, &votoP, &votoM) == 3) {
        counterQtd++;
        votou = 0;
        for (i = 0; i < counterQtd; i++) {
            if (jaVotou(eleitores[i], id)) {
                votou = 1;
                break;
            }
        }
        if (!votou) {
            eleitores[counterQtd] = criaEleitor(id, votoP, votoM);
            votos = contabilizaVotoPrisidente(votos, votoP);
            votos = contabilizaVotoPMinistro(votos, votoM);
        } else {
            fraude = 1;
            eleitores[counterQtd] = criaEleitor(-1, 0, 0);
        }
    }

    if (counterQtd > qtd) {
        printf("ELEICAO ANULADA\n");
    } else {
        if (fraude) {
            vencP = SEM_DECISAO;
            vencM = SEM_DECISAO;
        } else {
            vencP = vencedorPresidente(votos);
            vencM = vencedorPMinistro(votos);
        }
        printaResultado(votos, obtemTotalVotosPresidente(votos), obtemTotalVotosPMinistro(votos), vencP, vencM, counterQtd, qtd);
    }
    return 0;
}
