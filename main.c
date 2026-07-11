#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "def.c"
#include <stdint.h>
#include "orden.c"

Nodo* insertar_registro_lista(Nodo* nodo, registro datos) {
    if (nodo == NULL) {
        return crear_nodo(datos);
    }

    if (datos.time < nodo->time) {
        nodo->izq = insertar_registro_lista(nodo->izq, datos);
    } else if (datos.time > nodo->time) {
        nodo->der = insertar_registro_lista(nodo->der, datos);
    } else {
        // Si ya existe la misma clave, lo insertamos por la derecha
        nodo->der = insertar_registro_lista(nodo->der, datos);
    }

    return nodo;
}

void insertar_registro_usuario(void) {
    registro nuevo; 

    printf("Ingrese ID: ");
    scanf("%d", &nuevo.id);

    printf("Ingrese tipo (L=libro, P=pelicula, M=musica): ");
    scanf(" %c", &nuevo.tipo);

    printf("Ingrese titulo o nombre: ");
    getchar();
    fgets(nuevo.nom, sizeof(nuevo.nom), stdin);
    nuevo.nom[strcspn(nuevo.nom, "\n")] = '\0';

    printf("Ingrese duracion: ");
    scanf("%d", &nuevo.duracion);

    nuevo.time = (uint64_t)nuevo.id;

    FILE *f = fopen(ARCHIVO, "a");
    if (!f) {
        perror("No se pudo abrir LIBRERIA.txt");
        return;
    }

    fprintf(f, "%d,%c,%s,%d\n", nuevo.id, nuevo.tipo, nuevo.nom, nuevo.duracion);
    fclose(f);

    printf("Registro agregado correctamente.\n");
}


Nodo* eliminar_registro(Nodo* nodo, uint64_t time);

void buscar_por_rango(Nodo* raiz, uint64_t inicio, uint64_t fin);


int main() {
    int opcion;
    leer_archivo(NULL);
    printf("BIENVENIDO A LA BIBLIOTECA DE ALEJANDRIA\n");
    printf("por favor, seleccione una opcion. . .\n");
    printf("0. Salir \n");
    printf("1. Insertar registro\n");
    printf("2. Eliminar registro\n");
    printf("3. Buscar por rango\n");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1: 
        insertar_registro_usuario();
        break;

       /* case 2:                 me da rabia que
        eliminar_registro();      salga como error
                                   despues lo des-comentan
        break; 

        case 3:
        buscar_por_rango();
        break; */ 

        case 0:
        printf("Saliendo del programa...\n");
        break;
    }

    return 0;
}

