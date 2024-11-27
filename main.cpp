#include <iostream>
#include <stdexcept>
#include <limits>
#include "Libreria.h"

/**
* Función que limpia el buffer de entrada de `std::cin`.
* Se utiliza para descartar cualquier entrada inválida y 
* permitir que el programa continúe sin errores en la lectura de datos.
*/
void limpiarBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

/**
* Función principal que ejecuta el sistema de venta de libros.
* Permite al usuario realizar varias acciones como ordenar libros por
* calificación o precio, buscar libros por título y mostrar todos los libros.
* El sistema continúa hasta que el usuario elige salir.
*
* @return int: Código de retorno, 0 si el programa finaliza correctamente.
*/
int main() {
    Libreria libreria;

    // Cargar los libros desde un archivo
    try {
        libreria.cargarLibrosDesdeArchivo("libros.txt");
    } catch (const std::exception& e) {
        std::cerr << "Error al cargar los libros: " << e.what() << std::endl;
        return 1;
    }

    int opcion;
    do {
        std::cout << "\n--- Sistema de Venta de Libros ---\n";
        std::cout << "1. Ordenar por calificación\n";
        std::cout << "2. Ordenar por precio\n";
        std::cout << "3. Buscar libro por título\n";
        std::cout << "4. Mostrar todos los libros\n";
        std::cout << "5. Generar archivo con libros ordenados\n";
        std::cout << "6. Agregar un nuevo libro\n"; // Nueva opción
        std::cout << "7. Salir\n";
        std::cout << "Seleccione una opción: ";

        // Validar entrada del usuario
        if (!(std::cin >> opcion)) {
            std::cout << "Entrada inválida. Por favor, ingrese un número.\n";
            limpiarBuffer();
            continue;
        }

        switch (opcion) {
            case 1:
                // Ordenar los libros por calificación
                libreria.ordenarPorCalificacion();
                std::cout << "Libros ordenados por calificación:\n";
                libreria.mostrarLibros();
                break;
            case 2:
                // Ordenar los libros por precio
                libreria.ordenarPorPrecio();
                std::cout << "Libros ordenados por precio:\n";
                libreria.mostrarLibros();
                break;
            case 3:
                // Buscar un libro por su título
                {
                    std::string titulo;
                    std::cout << "Ingrese el título del libro: ";
                    limpiarBuffer();
                    std::getline(std::cin, titulo);
                    try {
                        Libro libro = libreria.buscarPorTitulo(titulo);
                        std::cout << "Libro encontrado:\n";
                        std::cout << "Título: " << libro.getTitulo() << "\n";
                        std::cout << "Calificación: " << libro.getCalificacion() 
                                  << "\n";
                        std::cout << "Precio: $" << libro.getPrecio() << "\n";
                    } catch (const std::runtime_error& e) {
                        std::cout << e.what() << std::endl;
                    }
                }
                break;
            case 4:
                std::cout << "Listado de todos los libros:\n";
                libreria.mostrarLibros();
                break;
            case 5:
                // Generar archivo con libros ordenados
                {
                    std::string nombreArchivo;
                    std::cout << "Ingrese el nombre del archivo: ";
                    limpiarBuffer();
                    std::getline(std::cin, nombreArchivo);
                    try {
                        libreria.generarArchivoLibrosOrdenados(nombreArchivo);
                        std::cout << "Archivo generado exitosamente.\n";
                    } catch (const std::runtime_error& e) {
                        std::cerr << "Error al generar el archivo: " << e.what() << std::endl;
                    }
                }
                break;
            case 6:
                // Agregar un nuevo libro
                std::cout << "Agregar un nuevo libro:\n";
                libreria.agregarLibroInteractivo();
                break;
            case 7:
                std::cout << "Haz salido\n";
                break;
            default:
                std::cout << "Opción no válida. Por favor, intente de nuevo.\n";
        }
    } while (opcion != 7);
    return 0;
}