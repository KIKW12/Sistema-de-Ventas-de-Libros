# Proyecto_TC1031: Sistema de Venta de Libros

## Avance 1
### Funcionalidades:
- Orenar libros por calificacion en formato descendente.
- Ordenar los libros por precio en formato ascendente.
- Mostrar la lista de los libros ordenas de acuerdo al criterio seleccionado.

### Selección de Algoritmo
Para este proyecto se ha decidido utilizar el algoritmo **std::sort** propio del lenguaje C++, ya que se combina con el uso del arbol AVL para el ordenamiento de nuestros libros. Este métod de ordenamiento preestablecido trabaja con una variante de **QuickSort** llamado **IntroSort**, combinando QuickSort, HeapSort e InsertionSort.

### Análisis de complejidad
#### 1. Análisis de complejidad para **Bubble Sort:**
- **Peor caso (O(n log n))**: Si bien el peor caso originalmente sería O(n²) debido a QuickSort, pero el método **IntroSort** cambia a HeapSort cuando detecta particiones desbalanceadas. Aunque los libros se encuentren completamente desorderdenados, el algoritmo mantiene el mismo tiempo haciendo cambios y reorganizando los datos en cada paso.
- **Mejor de los casos (O(n log n)):** Este se considera el mejor de los casos ya cuando todos los elementos, en este caso, los libros ya se encuentran ordenados o casi ordenados, haciendo particiones, gracias a QuickSort se logra mantener el tiempo..

#### 2. Análisis de complejidad del programa:
La complegidad del programa se puede representar de la siguiente manera:
1. En la parte de ordenamientos, se tiene una complegidad de O(n log n) debido al ordenamiento de los libros.
2. En la parte de la impresión de los libros ordenados, se tiene una complejidad de O(n) debido al recorrido sobre la lista ordenada.

Una vez esto, la complejidad del programa está determinada por el algoritmo de ordenamiento utlizado, en este caso sería de O(n log n) debido al algoritmo de **std::sort**. que viene preestablecido en C++.

## Avance 2
### Funcionalidades:
- Ordena libros por calificacion.
- Ordena libros por precio.
- Permite buscar un libro por titulo.
- Muestra todos los libros.
- Cargar informacion de libros a partir de un archivo .txt

### Seleccion de algoritmo:
Para este segundo avance se decidio la utilizacion de un Arbol AVL gracias a su capacidad de mantener datos balanceados, y mejorando el tiempo de busqueda, insercion o eleminiacion comparandolo ocn un arreglo (la estructura de datos presentada en el avance 1). El uso de AVL es de gran utilidad debido a la necesidad de realizar multiples busquedas por titulo.

### Mecanismo para lectura de archivos:
Para este segundo avance, se decidio trabajar con un archivo .txt, debido a su facil comprension y uso, haciendo que las personas puedan agregar mas libros a su conveniencia. Es importante señalar la estructura del archivo como : titulo,calificacion,precio.

### Analisis de complejidad:
#### 1. Analisis de complejidad para **AVL TREE:**
- **Peor caso O(log(n))**: Este se considera el peor de los casos cuando el arbol se encuentra desbalanceado, implicando la realizacion de rotaciones. Este caso aplica para la insersion, eliminacion y busqueda.

- **Mejor caso O(log(n))**: Este se considera el mejor caso cuando el arbol se encuentra balanceado. Este caso aplica para la insresion, eliminacion y busqueda.

#### 2. Analisis de complejidad para la carga de datos:
La lectura y carga de archivos tiene una complejidad de O(n), ya que se procesa cada line del archivo para insertar los libros en los nodos del Arbol AVL.

### 3. Analisis de complejidad del programa:
Una vez contando con los analisis de complejidad de los casos de nuestro programa, se sabe que la complejidad de este esta determinada por el algoritmo de mas alta complejidad, siendo el AVL Tree, es por ello que la complejidad completa del programa es O(log(n)).

## Avance 3
### Funcionalidades:
En este avance se implemetó una función que permite al usuario obtener una lista en formato .txt de los libros de acuerdo al último criterio de ordenamiento seleccionado por él.

## Correciones 3
Se implementa la función para que el usuario pueda agregar nuevos libros, y se haga todo el proceso de ordenamiento y almacenamiento en un nuevo archivo .txt.

## Referencias:
[https://www.naukri.com/code360/library/internal-implementation-of-stdsort](https://www.naukri.com/code360/library/internal-implementation-of-stdsort)
