#include <stdio.h>
#include <stdlib.h>
#include "def.h"


static Nodo* merge(Nodo* a, Nodo* b) {
    if (!a) return b;
    if (!b) return a;
    Nodo* resultado = NULL;
    if (a->time <= b->time) {
        resultado = a;
        resultado->der = merge(a->der, b);
    } else {
        resultado = b;
        resultado->der = merge(a, b->der);
    }
    return resultado;
}

static Nodo* obtener_medio(Nodo* cabeza) {
    if (!cabeza) return NULL;
    Nodo* lento = cabeza;
    Nodo* rapido = cabeza->der;
    while (rapido && rapido->der) {
        lento = lento->der;
        rapido = rapido->der->der;
    }
    return lento;
}

void merge_sort(Nodo** ref_cabeza) {
    Nodo* cabeza = *ref_cabeza;
    if (cabeza == NULL || cabeza->der == NULL) {
        return;
    }
    Nodo* medio = obtener_medio(cabeza);
    Nodo* siguiente_medio = medio->der;
    medio->der = NULL;

    merge_sort(&cabeza);
    merge_sort(&siguiente_medio);

    *ref_cabeza = merge(cabeza, siguiente_medio);
}
