# 📚 Book Store Management System

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![Data Structures](https://img.shields.io/badge/Data_Structures-AVL_Tree-brightgreen?style=for-the-badge)](https://en.wikipedia.org/wiki/AVL_tree)
[![Algorithms](https://img.shields.io/badge/Algorithms-O(log_n)-blue?style=for-the-badge)](https://en.wikipedia.org/wiki/Time_complexity)
[![Ask DeepWiki](https://img.shields.io/badge/Ask-DeepWiki-9B59B6?style=for-the-badge&logo=wikipedia&logoColor=white)](https://deepwiki.com/KIKW12/Sistema-de-Ventas-de-Libros)

> **A sophisticated C++ application demonstrating advanced data structures, algorithm implementation, and software engineering principles through a real-world book inventory management system.**

## 🚀 Project Overview

This project implements a comprehensive book store management system using **AVL Trees** for optimal data organization and retrieval. The system demonstrates proficiency in object-oriented programming, data structure implementation, file I/O operations, and algorithm optimization.

### 🎯 Key Features

- **🔍 Intelligent Search**: Lightning-fast book search by title using AVL tree traversal
- **📊 Dynamic Sorting**: Real-time sorting by rating (descending) or price (ascending)
- **📁 File Management**: Robust CSV file reading/writing with error handling
- **➕ Interactive Operations**: Add books dynamically with input validation
- **💾 Data Persistence**: Export sorted inventories to customizable file formats
- **🔄 Real-time Rebalancing**: Automatic tree restructuring when sorting criteria changes

## 🏗️ Technical Architecture

### Core Components

```
├── 📋 Libreria.h          # Main library management interface
├── 🌳 avl.h               # Self-balancing AVL tree implementation
├── 📖 libro.h             # Book entity with encapsulation
├── 🔍 buscarLibro.h       # Search algorithms and utilities
├── 📊 ordenarLibros.h     # Sorting algorithms wrapper
└── 🖥️ main.cpp            # Interactive CLI application
```

### Data Structures & Algorithms

| Component | Data Structure | Time Complexity | Space Complexity |
|-----------|---------------|-----------------|------------------|
| **Search Operations** | AVL Tree | O(log n) | O(n) |
| **Insert/Delete** | AVL Tree | O(log n) | O(1) |
| **Sorting** | IntroSort (std::sort) | O(n log n) | O(log n) |
| **Tree Traversal** | In-order DFS | O(n) | O(log n) |

## 🔧 Implementation Highlights

### AVL Tree Self-Balancing
```cpp
// Automatic rebalancing with rotations
NodoAVL* rotacionDerecha(NodoAVL* y) {
    NodoAVL* x = y->izquierda;
    NodoAVL* T2 = x->derecha;
    
    x->derecha = y;
    y->izquierda = T2;
    
    // Update heights and return new root
    y->altura = max(altura(y->izquierda), altura(y->derecha)) + 1;
    x->altura = max(altura(x->izquierda), altura(x->derecha)) + 1;
    
    return x;
}
```

### Dynamic Sorting Criteria
```cpp
void cambiarCriterio(const std::string& nuevoCriterio) {
    if (criterioPrincipal != nuevoCriterio) {
        criterioPrincipal = nuevoCriterio;
        // Rebuild tree with new sorting criterion
        std::vector<Libro> libros = obtenerLibrosOrdenados();
        liberarMemoria(raiz);
        raiz = nullptr;
        for (const auto& libro : libros) {
            insertar(libro);
        }
    }
}
```

### Robust File I/O with Error Handling
```cpp
void cargarLibrosDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        throw std::runtime_error("No se pudo abrir el archivo: " + nombreArchivo);
    }
    // Advanced parsing with validation...
}
```

## 📈 Performance Analysis

### Complexity Breakdown

| Operation | Best Case | Average Case | Worst Case | Notes |
|-----------|-----------|--------------|------------|-------|
| **Search** | O(log n) | O(log n) | O(log n) | AVL guarantees balance |
| **Insert** | O(log n) | O(log n) | O(log n) | Includes rebalancing |
| **Sort Switch** | O(n log n) | O(n log n) | O(n log n) | Tree reconstruction |
| **File Loading** | O(n) | O(n) | O(n) | Linear file processing |

### Memory Efficiency
- **Space Complexity**: O(n) for storing n books
- **Tree Height**: Guaranteed O(log n) due to AVL balancing
- **Memory Management**: Automatic cleanup with RAII principles

## 🛠️ Getting Started

### Prerequisites
- C++11 or higher
- Standard Template Library (STL)
- File system access for I/O operations

### Quick Start
```bash
# Clone the repository
git clone [your-repo-url]
cd book-store-system

# Compile the project
g++ -std=c++11 -o bookstore main.cpp

# Run the application
./bookstore
```

### Sample Data Format
```csv
Title,Rating,Price
Cien años de soledad,4.5,15.99
1984,4.7,12.50
El señor de los anillos,4.8,22.99
```

## 💡 Advanced Features Showcase

### 1. **Polymorphic Design Pattern**
- Abstract interfaces for different sorting strategies
- Template-based generic programming for type safety

### 2. **Exception Safety**
- Comprehensive error handling throughout the application
- RAII for automatic resource management
- Strong exception safety guarantees

### 3. **Interactive CLI Interface**
- Input validation and sanitization
- User-friendly error messages
- Robust menu system with edge case handling

### 4. **Modular Architecture**
- Single Responsibility Principle adherence
- Loose coupling between components
- High cohesion within modules

## 📊 Project Evolution

### Phase 1: Foundation
- Basic sorting algorithms using std::sort
- Simple array-based data storage
- **Complexity**: O(n log n) for sorting operations

### Phase 2: Optimization
- AVL Tree implementation for improved search performance
- File I/O integration for data persistence
- **Complexity**: O(log n) for search, insert, delete operations

### Phase 3: Enhancement
- Dynamic sorting criterion switching
- Interactive book addition functionality
- Export capabilities for different file formats

### Phase 4: Polish
- Comprehensive error handling
- Memory leak prevention
- Code documentation and optimization

## 🔍 Algorithm Deep Dive

### AVL Tree Balancing Strategy
The implementation uses four rotation cases to maintain balance:

1. **Left-Left Case**: Right rotation
2. **Right-Right Case**: Left rotation  
3. **Left-Right Case**: Left rotation on left child, then right rotation
4. **Right-Left Case**: Right rotation on right child, then left rotation

This ensures the tree height difference never exceeds 1, guaranteeing O(log n) operations.

### Sorting Algorithm Choice
The project leverages C++'s `std::sort`, which implements **IntroSort**:
- **QuickSort** for general cases
- **HeapSort** when recursion depth becomes excessive
- **InsertionSort** for small arrays

This hybrid approach ensures O(n log n) worst-case performance while maintaining practical efficiency.

## 🏆 Technical Skills Demonstrated

### **Programming Concepts**
- ✅ Object-Oriented Programming (OOP)
- ✅ Data Structure Implementation
- ✅ Algorithm Design & Analysis
- ✅ Memory Management
- ✅ Exception Handling
- ✅ File I/O Operations

### **Software Engineering**
- ✅ Modular Design Patterns
- ✅ Code Documentation
- ✅ Error Handling Strategies
- ✅ Performance Optimization
- ✅ Unit Testing Considerations
- ✅ Version Control Best Practices

### **Problem Solving**
- ✅ Complex Data Structure Navigation
- ✅ Algorithm Complexity Analysis
- ✅ Trade-off Decision Making
- ✅ Performance vs. Memory Optimization
- ✅ User Experience Design

## 📝 Code Quality Metrics

- **Cyclomatic Complexity**: Low - well-structured, easy to maintain
- **Documentation Coverage**: High - comprehensive inline documentation
- **Error Handling**: Robust - defensive programming practices
- **Memory Management**: Safe - RAII principles, no memory leaks
- **Modularity**: Excellent - clear separation of concerns

## 🤝 Contributing & Extensions

This project demonstrates scalability potential for:
- **Database Integration**: Replace file I/O with SQL/NoSQL databases
- **Web API**: RESTful service implementation
- **GUI Development**: Qt or web-based interface
- **Microservices**: Distributed system architecture
- **Testing Framework**: Unit/integration test suites

*This project represents a comprehensive understanding of computer science fundamentals, demonstrating the ability to implement complex algorithms, manage system resources efficiently, and create maintainable, professional-grade software solutions.*
