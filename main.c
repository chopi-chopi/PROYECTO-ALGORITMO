#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "def.h"
#include "orden.h"

Nodo* insertar_registro_lista(Nodo* nodo, registro datos) {
    if (nodo == NULL) {
        return crear_nodo(datos);
    }

    if (datos.time < nodo->time) {
        nodo->izq = insertar_registro_lista(nodo->izq, datos);
    } else if (datos.time > nodo->time) {
        nodo->der = insertar_registro_lista(nodo->der, datos);
    } else {
        nodo->der = insertar_registro_lista(nodo->der, datos);
    }

    return nodo;
}

void insertar_registro_usuario(Nodo** raiz) {
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

    *raiz = insertar_registro(*raiz, nuevo);

    FILE *f = fopen("LIBRERIA.txt", "a");
    if (!f) {
        perror("No se pudo abrir LIBRERIA.txt");
        return;
    }
    fprintf(f, "%d,%c,%s,%d\n", nuevo.id, nuevo.tipo, nuevo.nom, nuevo.duracion);
    fclose(f);

    printf("Registro agregado correctamente.\n");
}

int main() {
    int opcion;
    Nodo* raiz = NULL; 

    raiz = cargar_en_arbol("LIBRERIA.txt");

    printf("BIENVENIDO A LA BIBLIOTECA DE ALEJANDRIA\n");

        do {
        printf("\nSeleccione una opcion:\n");
        printf("0. Salir \n");
        printf("1. Insertar registro\n");
        printf("2. Eliminar registro\n");
        printf("3. Buscar por rango\n");
        printf("4. Ordenar registros\n"); 
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1: 
                insertar_registro_usuario(&raiz);
                break;

            case 2: {
                int id;
                printf("Ingrese ID a eliminar: ");
                scanf("%d", &id);
                raiz = eliminar_registro(raiz, (uint64_t)id);
                break;
            }
            
            case 3: {
                int inicio, fin;
                printf("Ingrese rango de IDs (inicio fin): ");
                scanf("%d %d", &inicio, &fin);
                buscar_por_rango(raiz, (uint64_t)inicio, (uint64_t)fin);
                break;
            }

            case 4: {
                merge_sort(&raiz);
                printf("Registros ordenados por ID:\n");
                imprimir_inorder(raiz);
                break;
            }

            case 0:
                printf("Saliendo del programa...\n");
                break;

        default:
            printf("Opcion invalida.\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}

