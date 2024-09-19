/*
 *
 * Proyecto Sistema de Venta de Libros
 * Juan Enrique Ayala Zapata
 * A01711235
 * 04/06/2024
 * Este archivo contiene la función principal del proyecto de 
 * Sistema de Ventas de Libros, en el cual se presenta la interfaz de usuario 
 * para ordenar los libros por calificación o por precio.
 */

#include <iostream>
#include "ordenarLibros.h"

int main() {
    // Instancia de la clase Libreria, con libros ya precargados
    Libreria libreria; 

    //Seleccion de criterio a ordenar los libros
    int opcion;
    std::cout << "Seleccione el criterio de ordenamiento:\n";
    std::cout << "1. Ordenar por calificación\n";
    std::cout << "2. Ordenar por precio\n";
    std::cin >> opcion;

    //Ordenamiento de los libros de acuerdo a criterio seleccionado
    if (opcion == 1) {
        libreria.ordenarPorCalificacion();
    } else if (opcion == 2) {
        libreria.ordenarPorPrecio();
    } else {
        std::cout << "Opción no válida.\n";
        return 1;
    }


    //Mostrar los libros ordenados
    libreria.mostrarLibros();

    return 0;
}
