/**
 * Proyecto Sistema de venta de libros
 * Juan Enrique Ayala Zapata
 * A01711235
 */

#ifndef ORDENADORLIBROS_H
#define ORDENADORLIBROS_H

#include <vector>
#include <algorithm>
#include "libro.h"

/**
 * Clase que provee funciones para ordenar libros en base a su
 * calificación o precio.
 */
class OrdenadorLibros {
public:
    /**
     * Ordena la lista de libros de mayor a menor calificación.
     * 
     * @param libros: Vector de libros que se desea ordenar.
     */
    void ordenarPorCalificacion(std::vector<Libro>& libros) {
        std::sort(libros.begin(), libros.end(), 
        [](const Libro& a, const Libro& b) {
            return a.getCalificacion() > b.getCalificacion();
        });
    }

    /**
     * Ordena la lista de libros de menor a mayor precio.
     * 
     * @param libros: Vector de libros que se desea ordenar.
     */
    void ordenarPorPrecio(std::vector<Libro>& libros) {
        std::sort(libros.begin(), libros.end(), 
        [](const Libro& a, const Libro& b) {
            return a.getPrecio() < b.getPrecio();
        });
    }
};

#endif // ORDENADORLIBROS_H
