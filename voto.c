# include <stdio.h>
# include "voto.h"

tVoto inicializaVotos() {
    tVoto votos;
    votos.brancosP = 0, votos.nulosP = 0;
    votos.brancosM = 0, votos.nulosM = 0;
    votos.dij = 0, votos.tur = 0, votos.sha = 0;
    votos.ber = 0, votos.lin = 0, votos.lov = 0;
    return votos;
}

float porcentagem(int valor, int total) {
    return 100.0 * valor / total;
}

tVoto contabilizaVotoPrisidente(tVoto votos, int votoP) {
    switch (votoP) {
        case DIJKSTRA:
            votos.dij++;
            return votos;
        case TURING:
            votos.tur++;
            return votos;
        case SHAW:
            votos.sha++;
            return votos;
        case BRANCO:
            votos.brancosP++;
            return votos;
        default:
            votos.nulosP++;
            return votos;
    }
}

tVoto contabilizaVotoPMinistro(tVoto votos, int votoM) {
    switch (votoM) {
        case BERNERS:
            votos.ber++;
            return votos;
        case LINUS:
            votos.lin++;
            return votos;
        case LOVELACE:
            votos.lov++;
            return votos;
        case BRANCO:
            votos.brancosM++;
            return votos;
        default:
            votos.nulosM++;
            return votos;
    }
}

int vencedorPresidente(tVoto votos) {
    int max = 0, maxID = 0;

    if (votos.dij > max) {
        max = votos.dij;
        maxID = DIJKSTRA;
    } else if (votos.dij == max) {
        maxID = EMPATE;
    }
    if (votos.tur > max) {
        max = votos.tur;
        maxID = TURING;
    } else if (votos.tur == max) {
        maxID = EMPATE;
    }
    if (votos.sha > max) {
        max = votos.sha;
        maxID = SHAW;
    } else if (votos.sha == max) {
        maxID = EMPATE;
    }
    if (votos.brancosP + votos.nulosP > votos.dij + votos.tur + votos.sha) {
        maxID = SEM_DECISAO;
    }

    return maxID;
}

int vencedorPMinistro(tVoto votos) {
    int max = 0, maxID = 0;

    if (votos.ber > max) {
        max = votos.ber;
        maxID = BERNERS;
    } else if (votos.ber == max) {
        maxID = EMPATE;
    }
    if (votos.lin > max) {
        max = votos.lin;
        maxID = LINUS;
    } else if (votos.lin == max) {
        maxID = EMPATE;
    }
    if (votos.lov > max) {
        max = votos.lov;
        maxID = LOVELACE;
    } else if (votos.lov == max) {
        maxID = EMPATE;
    }
    if (votos.brancosM + votos.nulosM > votos.ber + votos.lin + votos.lov) {
        maxID = SEM_DECISAO;
    }

    return maxID;
}

int obtemTotalVotosPresidente(tVoto votos) {
    return votos.dij + votos.tur + votos.sha + votos.nulosP + votos.brancosP;
}

int obtemTotalVotosPMinistro(tVoto votos) {
    return votos.ber + votos.lin + votos.lov + votos.nulosM + votos.brancosM;
}

void printaResultado(tVoto votos, int totalP, int totalM, int vencedorP, int vencedorM, int counterQtd, int qtd) {
    if (counterQtd > qtd) {
        printf("ELEICAO ANULADA\n");
    } else {
        printf("FIM DA ELEICAO\n");

        printf("- PRESIDENTE ELEITO: ");
        switch (vencedorP) {
            case DIJKSTRA:
                printf("Edsger Dijkstra (Partido do Melhor Caminho (PMC)), %d, %5.2f%%\n", votos.dij, porcentagem(votos.dij, totalP));
                break;
            case TURING:
                printf("Alan Turing (Partido dos Avanço Intelectual (PAI)), %d, %5.2f%%\n", votos.tur, porcentagem(votos.tur, totalP));
                break;
            case SHAW:
                printf("Carol Shaw (Mulheres Programadoras Unidas (MPU)), %d, %5.2f%%\n", votos.sha, porcentagem(votos.sha, totalP));
                break;
            case EMPATE:
                printf("EMPATE\n");
                break;
            default:
                printf("SEM DECISAO\n");
                break;
        }

        printf("- PRIMEIRO MINISTRO ELEITO: ");
        switch (vencedorM) {
            case BERNERS:
                printf("Tim Berners-Lee (World Wide Web (WWW)), %d, %5.2f%%\n", votos.ber, porcentagem(votos.ber, totalM));
                break;
            case LINUS:
                printf("Linus Torvalds (Linux (Linux)), %d, %5.2f%%\n", votos.lin, porcentagem(votos.lin, totalM));
                break;
            case LOVELACE:
                printf("Ada Lovelace (Gamers Unidos (GU)), %d, %5.2f%%\n", votos.lov, porcentagem(votos.lov, totalM));
                break;
            case EMPATE:
                printf("EMPATE\n");
                break;
            default:
                printf("SEM DECISAO\n");
                break;
        }

        printf("- COMPARECIMENTO: %5.2f%%\n", porcentagem(counterQtd, qtd));
        printf("- NULOS E BRANCOS: %d, %d\n", votos.nulosP + votos.brancosP, votos.nulosM + votos.brancosM);
    }
}