#include "tdapila.h"

void iniciap(TPILA *p) {
   p->tope = 0;
}

int vaciap(TPILA pila) {
    return pila.tope == 0;
}

int llenap(TPILA pila) {
    return pila.tope == MAXPILA;
}

void ponep(TPILA *p, TELEMENTOP elem) {
    if (p->tope != MAXPILA)
        p->vp[(p->tope)++] = elem;
}

void sacap(TPILA *p, TELEMENTOP *pelem) {
    if  (p->tope != 0)
        *pelem = p->vp[--p->tope];
}

void consultap(TPILA pila, TELEMENTOP *pelem) {
    if (pila.tope != 0)
        *pelem = pila.vp[pila.tope -1];
}
