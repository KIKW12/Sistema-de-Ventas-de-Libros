/**
 * Proyecto Sistema de venta de libros
 * Juan Enrique Ayala Zapata
 * A01711235
 */

#ifndef BUSCADORLIBROS_H
#define BUSCADORLIBROS_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include "libro.h"

class BuscadorLibros {
public:
    /**
    * Busca un libro por su título en un vector de libros.
    *
    * @param libros: vector que contiene los libros a buscar.
    * @param titulo: el título del libro que se quiere buscar.
    * @return Libro: el libro encontrado.
    * @throws std::runtime_error si no se encuentra el libro con el 
    * título especificado.
    */
    Libro buscarPorTitulo(const std::vector<Libro>& libros, 
    const std::string& titulo) const {
        // Utiliza std::find_if para buscar el libro por título en el vector
        auto it = std::find_if(libros.begin(), libros.end(), 
        [&titulo](const Libro& libro) {
            return libro.getTitulo() == titulo;
        });

        if (it != libros.end()) {
            return *it;
        }

        throw std::runtime_error("Libro no encontrado: " + titulo);
    }
};

#endif // BUSCADORLIBROS_H
