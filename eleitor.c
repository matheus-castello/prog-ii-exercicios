# include "eleitor.h"

tEleitor criaEleitor(int id, int votoP, int votoM) {
    tEleitor eleitor;
    eleitor.id = id;
    eleitor.votoP = votoP;
    eleitor.votoM = votoM;
    return eleitor;
}

int jaVotou(tEleitor eleitor, int idAnterior) {
    return eleitor.id == idAnterior;
}

int obtemIdEleitor(tEleitor eleitor) {
    return eleitor.id;
}

int obtemVotoPresidente(tEleitor eleitor) {
    return eleitor.votoP;
}

int obtemVotoPMinistro(tEleitor eleitor) {
    return eleitor.votoM;
}