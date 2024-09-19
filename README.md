# Proyecto_TC1031: Sistema de Venta de Libros

## Avance 1
### Funcionalidades:
- Orenar libros por calificacion en formato descendente.
- Ordenar los libros por precio en formato ascendente.
- Mostrar la lista de los libros ordenas de acuerdo al criterio seleccionado.

### Selección de Algoritmo
Para este proyecto, se decidió escoger el algoritmo de **Bubble Sort** ya que es un método de ordenamiento fácil de entender.
Así mismo, es fácil lograrlo adaptar de acuerdo a algún criterio de ordenamiento, siendo un ejemplo el lograr permitir al usuario que lo ordene por calificación o precio de manera ascendente o descendente, todo a selección del usuario.

### Análisis de complejidad
#### 1. Análisis de complejidad para **Bubble Sort:**
- **Peor caso (O(n²))**: Este se considera el peor de los casos cuando todos los libros están desordenados, haciendo que el algoritmo realice n-1 pasadas sobre la lista, realizando compraciones entre todos los elementos.
- **Mejor de los casos (O(n)):** Este se considera el mejor de los casos ya cuando todos los elementos, en este caso, los libros ya se encuentran ordenados, haciendo que el algoritmo solo de una pasada por toda la lisa.

#### 2. Análisis de complejidad del programa:
La complegidad del programa se puede representar de la siguiente manera:
1. En la parte de ordenamientos de libro, se tiene una complegidad de O(n²) debido al ordenamiento de los libros.
2. En la parte de la impresión de los libros ordenados, se tiene una complejidad de O(n) debido al recorrido sobre la lista ordenada.

Una vez esto, la complejidad del programa está determinada por el algoritmo de ordenamiento utlizado, en este caso sería de O(n^2) debido al algoritmo de **Bubble Sort**.
