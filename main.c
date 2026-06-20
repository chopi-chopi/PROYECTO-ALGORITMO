#include <stdio.h>
#include <stdlib.h>
#include "def.c"

Nodo* insertar_registro(Nodo* nodo, registro datos);

Nodo* eliminar_registro(Nodo* nodo, uint64_t time);

void buscar_por_rango(Nodo* raiz, uint64_t inicio, uint64_t fin);