**BIBLIOTECA DE ALEJANDRIA**

**Sophia Vieira**

**Isabella Piñero**

**Fabiana Machado**

Las bibliotecas son la forma más antigua de organizamiento que tenemos como sociedad, lugares en los que recolectamos nuestras mejores historias para categorizarlas, recordarlas y compartirlas. La manera en la que se organiza, aun en su forma más primitiva, es un algoritmo. Con cada década que pasa y nuevas formas de consumir historias son descubiertas es necesario crear un lugar donde organizar todos estos métodos distintos, es por ello tuvimos la idea de una biblioteca multimedia.

**OBJETIVO:** Crear una base de datos multimedia que recoja miles de entradas distintas (películas, libros, álbumes de música), identifique correctamente el tipo de cada una y permita al usuario introducir, eliminar o agrupar por tipo de dato.

**MOTIVACION:** entender el manejo de tipos de dato abstracto y cómo podemos interactuar con ellos, sin tener que llegar a un nivel de abstracción primordial ni quitando información valiosa de los datos al volvernos a “nuestro idioma”

**DESCRIPCION;** mediante módulos claves que contengan funciones similares y nodos puntuales que puedan mutar dependiendo de para qué son necesitados, el programa será capaz de recorrer una lista de datos de cualquier longitud, identificar cada tipo que consigue e introducirlo en la categoría que le pertenece.

El usuario a través de la consola podrá pedir ver todos los datos que correspondan a cierta categoría (por ejemplo, todos los libros que empiecen por la letra M) e introducir uno sin especificar donde ira esta nueva entrada, pues el programa lo identificará por sí solo. Del mismo modo, dando solo una identificación (nombre, ID, duración o número de páginas) el usuario será capaz de eliminar un objeto por completo. Se usará el algoritmo “merge/quick sort” para organizar correctamente la lista, sumado a los arboles AVT para la colocación eficiente de los índices.

Mediante un módulo _main()_ se manejara la eficacia de cada función y el tiempo de cuanto tarda en realizarse cada acción, garantizando de este modo una complejidad temporal de O(log n), asegurándonos de crear una interfaz rápida, limpia y fácil de entender para el usuario.