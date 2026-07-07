#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define ARCHIVO "LIBRERIA.txt"

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

void leer_archivo(registro *bd) {
    (void)bd;

    FILE *f = fopen(ARCHIVO, "r");
    if (!f) {
        perror("Error al abrir el archivo");
        exit(1);
    }

     int id; 
    char tipo; 
    char nom[50];
    int duracion;

    while (fscanf(ARCHIVO, "%d,%c,%[^,],%d\n", &id, &tipo, nom, &duracion) != EOF) {
        
        registro nuevo;
        nuevo.id = id;
        nuevo.tipo = tipo;
        strcpy(nuevo.nom, nom);
        nuevo.duracion = duracion;

        // Mostrar el formato según el tipo de medio
        if (nuevo.tipo == 'L') {
            printf("[LIBRO] ID: %d | Título: %s | Páginas: %d\n", nuevo.id, nuevo.nom, nuevo.duracion);
        } else if (nuevo.tipo == 'P') {
            printf("[PELÍCULA] ID: %d | Título: %s | Duración: %d min\n", nuevo.id, nuevo.nom, nuevo.duracion);
        } else if (nuevo.tipo == 'M') {
            printf("[MÚSICA] ID: %d | Título: %s | Duración: %d min\n", nuevo.id, nuevo.nom, nuevo.duracion);
        }
    }

    fclose(f);
}

Nodo* crear_nodo(registro datos) {
    Nodo *n = (Nodo*)malloc(sizeof(Nodo));
    if (!n) return NULL;
    n->time = datos.time;
    n->datos = datos;
    n->izq = NULL;
    n->der = NULL;
    n->altura = 1;
    return n;
}


Nodo* insertar_registro_lista(Nodo* nodo, registro datos); 
void insertar_registro(void);
Nodo* eliminar_registro(Nodo* nodo, uint64_t time);
void buscar_por_rango(Nodo* raiz, uint64_t inicio, uint64_t final);
