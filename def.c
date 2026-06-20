#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define ARCHIVO "....text"

typedef struct registro {
    uint64_t time; 
    int id; 
    char nam[50];
    int duracion;
} registro;

typedef struct Nodo {
    uint64_t time; 
    registro datos;
    struct Nodo *izq;
    struct Nodo *der;
    int altura;
} Nodo;



void leer_archivo(registro *bd) {
    FILE *f = fopen(ARCHIVO, "r");
    if (!f) {
        perror("Error al abrir el archivo");
        exit(1);
    }
}

Nodo* insertar_registro(Nodo* nodo, registro datos);
Nodo* eliminar_registro(Nodo* nodo, uint64_t time);
void buscar_por_rango(Nodo* raiz, uint64_t inicio, uint64_t final);