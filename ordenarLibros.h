/*
 *
 * Proyecto Sistema de Venta de Libros - Clase ordenaLibros
 * Juan Enrique Ayala Zapata
 * A01711235
 * 18/09/2024
 * Esta clase define el constructor de los libros existentes en la librería,
 * así como la clase Libreria, en la cual está el método de ordenamiento Bubble
 * Sort, que ordena los libros por calificación o por precio.z
 */

#ifndef ORDENALIBROS_H_
#define ORDENALIBROS_H_

#include <iostream>
#include <vector>
#include <string>

/**
 * Clase representativa de un libro dentro del sistema,
 * 
 * @param titulo: titulo del libro
 * @param calificacion: calificación del libro
 * @param precio: precio del libro
 */

class Libro {
private:
    std::string titulo;
    float calificacion;
    float precio;

public:

    /**
     * Constructor para inicializar los datos del libro
     * 
     * @param titulo: titulo del libro
     * @param calificacion: calificación del libro
     * @param precio: precio del libro
     */
    Libro(const std::string& titulo, float calificacion, float precio)
        : titulo(titulo), calificacion(calificacion), precio(precio) {}

    
    //Metodos para acceder a los atributos privados del libro
    
    /**
     * Obtiene el titulo del libro
     * @return titulo
     */
    std::string getTitulo() const{return titulo;}

    /**
     * Obtiene la calificación del libro
     * @return calificacion
     */
    float getCalificacion() const{return calificacion;}

    /**
     * Obtiene el precio del libro
     * @return precio
     */
    float getPrecio() const{return precio;}
};

/**
 * Clase representativa de la librería, en la cual se encuentran los libros
 * y los métodos para ordenarlos por calificación o por precio.
 */
class Libreria{
private:
    std::vector<Libro> libros;

    /**
     * Método de ordenamiento Bubble Sort, que ordena los libros
     * de acuerdo al criterio seleccionado.
     * 
     * @param criterio: criterio de ordenamiento
     */

    void bubbleSort(const std::string& criterio){
        for (int i = 0; i < libros.size() - 1; i++) {
            for (int j = 0; j < libros.size() - i - 1; j++) {
                if (criterio == "calificacion") {
                    if (libros[j].getCalificacion() < libros[j + 1].getCalificacion()) {
                        std::swap(libros[j], libros[j + 1]);
                    }
                } else if (criterio == "precio") {
                    if (libros[j].getPrecio() > libros[j + 1].getPrecio()) {
                        std::swap(libros[j], libros[j + 1]);
                    }
                }
            }
        }
    }

public:
    /**
     * Constructor de la librería, en el cual se inicializan los libros
     * con sus respectivos datos.
     */
    Libreria(){
        libros.push_back(Libro("El principito", 4.5, 100.0));
        libros.push_back(Libro("Cien años de soledad", 4.0, 150.0));
        libros.push_back(Libro("El alquimista", 4.8, 200.0));
        libros.push_back(Libro("El código Da Vinci", 4.2, 250.0));
        libros.push_back(Libro("El señor de los anillos", 4.7, 300.0));
    }

    /**
     * Método para ordenar los libros por calificación
     */
    void ordenarPorCalificacion(){
        bubbleSort("calificacion");
    }

    /**
     * Método para ordenar los libros por precio
     */
    void ordenarPorPrecio(){
        bubbleSort("precio");
    }

    void mostrarLibros(){
        for (const auto& libro : libros) {
            std::cout << "Titulo: " << libro.getTitulo() << std::endl;
            std::cout << "Calificacion: " << libro.getCalificacion() << std::endl;
            std::cout << "Precio: " << libro.getPrecio() << std::endl;
            std::cout << std::endl;
        }
    }
};

#endif // !ORDENALIBROS_H_