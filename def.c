#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "def.h"
#define ARCHIVO "LIBRERIA.txt"

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

    while (fscanf(f, "%d,%c,%[^,],%d\n", &id, &tipo, nom, &duracion) == 4) {
        
        registro nuevo;
        nuevo.id = id;
        nuevo.tipo = tipo;
        strcpy(nuevo.nom, nom);
        nuevo.duracion = duracion;

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

Nodo* cargar_en_arbol(const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (!f) {
        perror("Error al abrir el archivo");
        return NULL;
    }

    Nodo* raiz = NULL;
    int id;
    char tipo;
    char nom[50];
    int duracion;

    while (fscanf(f, "%d,%c,%49[^,],%d\n", &id, &tipo, nom, &duracion) == 4) {
        registro nuevo;
        nuevo.id = id;
        nuevo.tipo = tipo;
        strcpy(nuevo.nom, nom);
        nuevo.duracion = duracion;
        nuevo.time = (uint64_t)id;

        raiz = insertar_registro(raiz, nuevo);
    }

    fclose(f);
    return raiz;
}

void mostrar_registros(const char *archivo) {
    FILE *f = fopen(archivo, "r");
    if (!f) {
        perror("Error al abrir el archivo");
        return;
    }

    int id;
    char tipo;
    char nom[50];
    int duracion;

    while (fscanf(f, "%d,%c,%49[^,],%d\n", &id, &tipo, nom, &duracion) == 4) {
        registro nuevo;
        nuevo.id = id;
        nuevo.tipo = tipo;
        nuevo.time = 0;
        strcpy(nuevo.nom, nom);
        nuevo.duracion = duracion;

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

void introducir_registro(const char *archivo) {
    registro nuevo;
    printf("\nIngresa los datos del nuevo registro:\n");
    printf("ID: ");
    scanf("%d", &nuevo.id);
    printf("Tipo (L=Libro, P=Pelicula, M=Musica): ");
    scanf(" %c", &nuevo.tipo);
    printf("Título: ");
    scanf(" %49[^\n]", nuevo.nom);
    printf("Duración: ");
    scanf("%d", &nuevo.duracion);
    nuevo.time = 0;

    FILE *f = fopen(archivo, "a");
    if (!f) {
        perror("Error al abrir el archivo");
        return;
    }

    fprintf(f, "%d,%c,%s,%d\n", nuevo.id, nuevo.tipo, nuevo.nom, nuevo.duracion);
    fclose(f);

    printf("Registro agregado correctamente.\n");
}

void cargar_libreria(const char *archivo) {
    mostrar_registros(archivo);
}

Nodo* insertar_registro(Nodo* nodo, registro datos) {
    if (nodo == NULL) {
        return crear_nodo(datos);
    }

    if (datos.time < nodo->time) {
        nodo->izq = insertar_registro(nodo->izq, datos);
    } else if (datos.time > nodo->time) {
        nodo->der = insertar_registro(nodo->der, datos);
    } else {
        nodo->der = insertar_registro(nodo->der, datos);
    }

    return nodo;
}

Nodo* eliminar_registro(Nodo* nodo, uint64_t time) {
    if (nodo == NULL) return NULL;

    if (time < nodo->time) {
        nodo->izq = eliminar_registro(nodo->izq, time);
    } else if (time > nodo->time) {
        nodo->der = eliminar_registro(nodo->der, time);
    } else {
        if (nodo->izq == NULL) {
            Nodo* temp = nodo->der;
            free(nodo);
            return temp;
        } else if (nodo->der == NULL) {
            Nodo* temp = nodo->izq;
            free(nodo);
            return temp;
        } else {
            Nodo* sucesor = nodo->der;
            while (sucesor->izq != NULL) {
                sucesor = sucesor->izq;
            }
            nodo->datos = sucesor->datos;
            nodo->time = sucesor->time;
            nodo->der = eliminar_registro(nodo->der, sucesor->time);
        }
    }
    return nodo;
}

void buscar_por_rango(Nodo* merge, uint64_t inicio, uint64_t final) {
    if (merge == NULL) return;

    if (merge->time > inicio) {
        buscar_por_rango(merge->izq, inicio, final);
    }

    if (merge->time >= inicio && merge->time <= final) {
        printf("ID: %d | Tipo: %c | Nombre: %s | Duración: %d\n",
               merge->datos.id, merge->datos.tipo, merge->datos.nom, merge->datos.duracion);
    }

    if (merge->time < final) {
        buscar_por_rango(merge->der, inicio, final);
    }
}

void imprimir_inorder(Nodo* raiz) { //porsia
    if (raiz == NULL) return;

    imprimir_inorder(raiz->izq);
    printf("ID: %d | Tipo: %c | Nombre: %s | Duración: %d\n",
           raiz->datos.id, raiz->datos.tipo, raiz->datos.nom, raiz->datos.duracion);
    imprimir_inorder(raiz->der);
}

