/**
 * Proyecto Sistema de venta de libros
 * Juan Enrique Ayala Zapata
 * A01711235
 */

#ifndef LIBRO_H
#define LIBRO_H

#include <string>

class Libro {
private:
    std::string titulo;
    float calificacion;
    float precio;

public:
    /**
    * Constructor por defecto que inicializa un libro con valores vacíos o cero.
    * Título vacío, calificación y precio a 0.
    */
    Libro() : titulo(""), calificacion(0.0f), precio(0.0f) {}

    /**
    * Constructor principal que inicializa un libro con un título, 
    * calificación y precio.
    *
    * @param titulo: El título del libro.
    * @param calificacion: La calificación del libro (como un float).
    * @param precio: El precio del libro (como un float).
    */
    Libro(const std::string& titulo, float calificacion, float precio)
        : titulo(titulo), calificacion(calificacion), precio(precio) {}
    
    /**
    * Getter para obtener el título del libro.
    * 
    * @return std::string: El título del libro.
    */
    std::string getTitulo() const { return titulo; }

    /**
    * Getter para obtener la calificación del libro.
    * 
    * @return float: La calificación del libro.
    */
    float getCalificacion() const { return calificacion; }

    /**
    * Getter para obtener el precio del libro.
    * 
    * @return float: El precio del libro.
    */
    float getPrecio() const { return precio; }
};

#endif // LIBRO_H
