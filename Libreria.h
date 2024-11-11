/**
 * Proyecto Sistema de venta de libros
 * Juan Enrique Ayala Zapata
 * A01711235
 */

#ifndef LIBRERIA_H
#define LIBRERIA_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "libro.h"
#include "avl.h"

class Libreria {
private:
    ArbolAVL arbol;

public:
    /**
    * Constructor por defecto de la clase Libreria.
    * Inicializa el árbol AVL utilizando "calificación" 
    * como criterio de ordenación por defecto.
    */
    Libreria() : arbol("calificacion") {}

    /**
    * Método para cargar libros desde un archivo de texto.
    * El archivo debe contener líneas en el formato "titulo,calificación,precio".
    * Cada libro se inserta en el árbol AVL.
    *
    * @param nombreArchivo: nombre del archivo desde donde se cargarán los libros
    * @throws std::runtime_error si el archivo no se puede abrir
    */
void cargarLibrosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        throw std::runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }

    std::string linea;
    int contador = 0;
    while (std::getline(archivo, linea)) {
        std::istringstream iss(linea);
        std::string titulo;
        float calificacion, precio;

        if (std::getline(iss, titulo, ',') && 
            iss >> calificacion && 
            iss.ignore() && 
            iss >> precio) {
            arbol.insertar(Libro(titulo, calificacion, precio));
            contador++;
            std::cout << "Libro insertado: " << titulo << std::endl; // Mensaje de depuración
        } else {
            std::cerr << "Error al leer la línea: " << linea << std::endl;
        }
    }

    std::cout << "Total de libros leídos: " << contador << std::endl;
}

    

    /**
    * Método para cambiar el criterio de ordenación del árbol a "calificación".
    * Reordena el árbol AVL de acuerdo a las calificaciones de los libros.
    */
    void ordenarPorCalificacion() {
        arbol.cambiarCriterio("calificacion");
    }

    /**
    * Método para cambiar el criterio de ordenación del árbol a "precio".
    * Reordena el árbol AVL de acuerdo a los precios de los libros.
    */
    void ordenarPorPrecio() {
        arbol.cambiarCriterio("precio");
    }

    /**
    * Método para buscar un libro por su título en el árbol AVL.
    * Si no se encuentra el libro, lanza una excepción.
    *
    * @param titulo: título del libro a buscar
    * @return Libro: objeto del libro encontrado
    * @throws std::runtime_error si no se encuentra el libro
    */
    Libro buscarPorTitulo(const std::string& titulo) {
        try {
            return arbol.buscarPorTitulo(titulo);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error al buscar libro: " << e.what() << std::endl;
            throw;
        }
    }

    /**
    * Método para mostrar en consola todos los libros almacenados en el árbol AVL.
    * Los libros se muestran en el orden actual definido por el 
    * criterio (calificación o precio).
    */
    void mostrarLibros() const {
        std::vector<Libro> libros = arbol.obtenerLibrosOrdenados();
        for (const auto& libro : libros) {
            std::cout << "Titulo: " << libro.getTitulo() << std::endl;
            std::cout << "Calificacion: " << libro.getCalificacion() << std::endl;
            std::cout << "Precio: $" << libro.getPrecio() << std::endl;
            std::cout << std::endl;
        }
    }

    /**
    * Método para generar un archivo .txt con todos los libros ordenados
    * según el criterio seleccionado por el usuario.
    *
    * @param nombreArchivo: nombre del archivo donde se guardarán los libros
    * @throws std::runtime_error si el archivo no se puede abrir
    */
    void generarArchivoLibrosOrdenados(const std::string& nombreArchivo) const {
        std::ofstream archivo(nombreArchivo);
        if (!archivo) {
            throw std::runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
        }

        std::vector<Libro> libros = arbol.obtenerLibrosOrdenados();
        for (const auto& libro : libros) {
            archivo << libro.getTitulo() << "," 
                    << libro.getCalificacion() << "," 
                    << libro.getPrecio() << "\n";
        }
    }
};

#endif // LIBRERIA_H
