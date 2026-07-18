# PROYECTO ALGORITMO

Nuestro proyecto trata sobre una biblioteca de organizamiento, donde es posible ingresar, eliminar, buscar y ordenar registros, basicamente una biblioteca interactiva.
Para poder crear nuestra biblioteca usamos codigo C, las estructuras de datos "struct registro" (representa cada registro) y "struct nodo" (representa cada nodo del arbol binario), el arbol binario de búsqueda que se usa para insertar, eliminar y buscar registros por ID, el algoritmo de mergesort implementado en orden.c para ordenar los registros, fopen/fscanf/fprintf para leer y poder escribir en la libreria, etc.

# ARCHIVOS:
main.c - es el menú principal y la lógica de interacción con el usuario del programa
def.h - define las estructuras y las funciones
def.c - implementa las funciones de manejo de registros y operaciones en el árbol
orden.c / orden.h - implementa el algoritmo merge_sort para organizar los registros por identificador o ID
LIBRERIA.txt - archivo de texto, contiene todos los registros y datos

# Que hace cada modulo?
-leer_archivo: este lee el archivo y muestra los registros en la consola
-crear_nodo: crea un nuevo nodo en el árbol con un registro
-cargar_en_arbol: carga los registros del archivo en el árbol binario
-insertar_registro: agrega un registro en el árbol según su ID
-eliminar_registro: elimina un registro del árbol por ID
-buscar_por_rango: busca y muestra registros dentro de un rango de IDs
-imprimir_inorder: recorre el árbol en orden, muestra registros ordenados
-mostrar_registros: muestra todos los registros desde el archivo
-introducir_registro: permite ingresar un nuevo registro y guardarlo en el archivo
-merge_sort: ordena los registros por ID usando MergeSort 

//Para correr el programa introducir lo siguiente en la terminal: 
//gcc -Wall -Wextra -std=c11 -c main.c
gcc -Wall -Wextra -std=c11 -c orden.c
gcc -Wall -Wextra -std=c11 -c def.c
gcc -Wall -Wextra -std=c11 main.o orden.o def.o -o biblioteca.exe
.\biblioteca.exe