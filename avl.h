/**
 * Proyecto Sistema de venta de libros
 * Juan Enrique Ayala Zapata
 * A01711235
 */

#ifndef ARBOLAVL_H
#define ARBOLAVL_H

#include <algorithm>
#include <stdexcept>
#include <vector>
#include "libro.h"

class NodoAVL {
public:
    Libro libro;
    NodoAVL* izquierda;
    NodoAVL* derecha;
    int altura;

    /**
    * Constructor del NodoAVL.
    * Inicializa el nodo con un objeto Libro, sin hijos y con altura 1.
    *
    * @param lib: el libro que se almacenará en el nodo
    */
    NodoAVL(const Libro& lib) : libro(lib), izquierda(nullptr), 
    derecha(nullptr), altura(1) {}
};

class ArbolAVL {
private:
    NodoAVL* raiz;
    std::string criterioPrincipal;

    /**
    * Método auxiliar para obtener la altura de un nodo.
    *
    * @param N: nodo del que se quiere obtener la altura
    * @return int: altura del nodo
    */
    int altura(NodoAVL* N) {
        if (N == nullptr) return 0;
        return N->altura;
    }

    /**
    * Método auxiliar para obtener el máximo entre dos valores enteros.
    *
    * @param a: primer valor
    * @param b: segundo valor
    * @return int: valor máximo entre a y b
    */
    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    /**
    * Realiza una rotación a la derecha en un subárbol con el nodo y.
    *
    * @param y: nodo raíz del subárbol
    * @return NodoAVL*: nueva raíz del subárbol después de la rotación
    */
    NodoAVL* rotacionDerecha(NodoAVL* y) {
        NodoAVL* x = y->izquierda;
        NodoAVL* T2 = x->derecha;

        x->derecha = y;
        y->izquierda = T2;

        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;

        return x;
    }

    /**
    * Realiza una rotación a la izquierda en un subárbol con el nodo x.
    *
    * @param x: nodo raíz del subárbol
    * @return NodoAVL*: nueva raíz del subárbol después de la rotación
    */
    NodoAVL* rotacionIzquierda(NodoAVL* x) {
        NodoAVL* y = x->derecha;
        NodoAVL* T2 = y->izquierda;

        y->izquierda = x;
        x->derecha = T2;

        x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
        y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;

        return y;
    }

    /**
    * Obtiene el balance del nodo N.
    *
    * @param N: nodo del que se quiere obtener el balance
    * @return int: valor del balance, calculado como la diferencia de alturas 
    * entre los subárboles izquierdo y derecho
    */
    int getBalance(NodoAVL* N) {
        if (N == nullptr) return 0;
        return altura(N->izquierda) - altura(N->derecha);
    }

    /**
    * Inserta un libro en el árbol AVL y lo balancea si es necesario.
    *
    * @param nodo: nodo actual del árbol (puede ser nulo)
    * @param libro: el libro que se quiere insertar
    * @return NodoAVL*: el nuevo nodo raíz del subárbol balanceado
    */
    NodoAVL* insertar(NodoAVL* nodo, const Libro& libro) {
        if (nodo == nullptr)
            return new NodoAVL(libro);

        // Inserción basada en el criterio principal (calificación o precio)
        if (criterioPrincipal == "calificacion") {
            if (libro.getCalificacion() < nodo->libro.getCalificacion())
                nodo->izquierda = insertar(nodo->izquierda, libro);
            else if (libro.getCalificacion() > nodo->libro.getCalificacion())
                nodo->derecha = insertar(nodo->derecha, libro);
            else
                return nodo;
        } else { // precio
            if (libro.getPrecio() < nodo->libro.getPrecio())
                nodo->izquierda = insertar(nodo->izquierda, libro);
            else if (libro.getPrecio() > nodo->libro.getPrecio())
                nodo->derecha = insertar(nodo->derecha, libro);
            else
                return nodo;
        }

        // Actualiza la altura del nodo
        nodo->altura = 1 + max(altura(nodo->izquierda), altura(nodo->derecha));

        // Calcula el balance del nodo para determinar si se necesita rotación
        int balance = getBalance(nodo);

        // Casos de rotación (sin cambios)
        // ...

        return nodo;
    }

    /**
    * Realiza un recorrido en orden en el árbol y almacena los 
    * libros en un vector.
    *
    * @param nodo: nodo actual del árbol
    * @param libros: referencia al vector donde se almacenarán los libros
    */
    void inOrder(NodoAVL* nodo, std::vector<Libro>& libros) const {
        if (nodo != nullptr) {
            inOrder(nodo->izquierda, libros);
            libros.push_back(nodo->libro);
            inOrder(nodo->derecha, libros);
        }
    }

    /**
    * Busca un libro por su título en el árbol AVL.
    *
    * @param nodo: nodo actual del árbol
    * @param titulo: título del libro a buscar
    * @return NodoAVL*: nodo que contiene el libro encontrado, 
    * o nullptr si no se encuentra
    */
    NodoAVL* buscarPorTitulo(NodoAVL* nodo, const std::string& titulo) const {
        if (nodo == nullptr || nodo->libro.getTitulo() == titulo)
            return nodo;

        NodoAVL* encontrado = buscarPorTitulo(nodo->izquierda, titulo);
        if (encontrado != nullptr)
            return encontrado;

        return buscarPorTitulo(nodo->derecha, titulo);
    }

    /**
    * Libera la memoria ocupada por el árbol AVL.
    *
    * @param nodo: nodo actual del árbol
    */
    void liberarMemoria(NodoAVL* nodo) {
        if (nodo != nullptr) {
            liberarMemoria(nodo->izquierda);
            liberarMemoria(nodo->derecha);
            delete nodo;
        }
    }

public:
    /**
    * Constructor del árbol AVL.
    * Inicializa el árbol vacío y define el criterio principal 
    * para ordenar los libros.
    *
    * @param criterio: criterio para ordenar los libros 
    * ("calificacion" por defecto)
    */
    ArbolAVL(const std::string& criterio = "calificacion") : 
    raiz(nullptr), criterioPrincipal(criterio) {}

    /**
    * Destructor del árbol AVL.
    * Libera toda la memoria utilizada por el árbol.
    */
    ~ArbolAVL() {
        liberarMemoria(raiz);
    }

    /**
    * Inserta un libro en el árbol AVL.
    *
    * @param libro: el libro que se quiere insertar
    */
    void insertar(const Libro& libro) {
        raiz = insertar(raiz, libro);
    }

    /**
    * Obtiene los libros almacenados en el árbol AVL en el orden actual.
    *
    * @return std::vector<Libro>: vector con los libros en orden
    */
    std::vector<Libro> obtenerLibrosOrdenados() const {
        std::vector<Libro> libros;
        inOrder(raiz, libros);
        return libros;
    }

    /**
    * Busca un libro por su título.
    *
    * @param titulo: título del libro a buscar
    * @return Libro: objeto del libro encontrado
    * @throws std::runtime_error si no se encuentra el libro
    */
    Libro buscarPorTitulo(const std::string& titulo) const {
        NodoAVL* nodo = buscarPorTitulo(raiz, titulo);
        if (nodo != nullptr) {
            return nodo->libro;
        }
        throw std::runtime_error("Libro no encontrado: " + titulo);
    }

    /**
    * Cambia el criterio de ordenación del árbol AVL (por calificación o precio).
    * Rearma el árbol si se cambia el criterio.
    *
    * @param nuevoCriterio: nuevo criterio para ordenar los libros
    * @throws std::invalid_argument si el criterio es inválido
    */
    void cambiarCriterio(const std::string& nuevoCriterio) {
        if (nuevoCriterio != "calificacion" && nuevoCriterio != "precio") {
            throw std::invalid_argument(
                "Criterio inválido. Use 'calificacion' o 'precio'.");
        }
        
        if (criterioPrincipal != nuevoCriterio) {
            criterioPrincipal = nuevoCriterio;
            std::vector<Libro> libros = obtenerLibrosOrdenados();
            liberarMemoria(raiz);
            raiz = nullptr;
            for (const auto& libro : libros) {
                insertar(libro);
            }
        }
    }
};

#endif // ARBOLAVL_H
