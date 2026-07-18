#ifndef DEF_H
#define DEF_H

#include <stdint.h>

typedef struct registro {
    uint64_t time;
    int id;
    char tipo;
    char nom[50];
    int duracion;
} registro;

typedef struct Nodo {
    uint64_t time;
    registro datos;
    struct Nodo *izq;
    struct Nodo *der;
    int altura;
} Nodo;

void leer_archivo(registro *bd);
Nodo* crear_nodo(registro datos);
Nodo* cargar_en_arbol(const char *archivo);
Nodo* insertar_registro(Nodo* nodo, registro datos);
Nodo* eliminar_registro(Nodo* nodo, uint64_t time);
void buscar_por_rango(Nodo* raiz, uint64_t inicio, uint64_t final);
void imprimir_inorder(Nodo* raiz);


void mostrar_registros(const char *archivo);
void introducir_registro(const char *archivo);
void cargar_libreria(const char *archivo);

#endif
