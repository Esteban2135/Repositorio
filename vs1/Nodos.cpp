#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaEnlazada {
private:
    Nodo* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void agregar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    ~ListaEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};

int main() {
    ListaEnlazada lista;

    std::cout << "Ingresa 5 valores para agregar a la lista:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        int valor;
        std::cout << "Valor " << i + 1 << ": ";
        std::cin >> valor;
        lista.agregar(valor);
    }

    std::cout << "Lista: ";
    lista.mostrar();

    return 0;
}
