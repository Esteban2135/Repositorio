#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;
    Nodo* anterior;

    Nodo(int valor) : dato(valor), siguiente(nullptr), anterior(nullptr) {}
};

class ListaDoblementeEnlazada {
private:
    Nodo* cabeza;

public:
    ListaDoblementeEnlazada() : cabeza(nullptr) {}

    void agregar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    void insertar(int valor, int posicion) {
        if (posicion < 0) {
            std::cout << "La posicion no puede ser negativa." << std::endl;
            return;
        }

        Nodo* nuevoNodo = new Nodo(valor);

        if (!cabeza) {
            cabeza = nuevoNodo;
        } else if (posicion == 0) {
            nuevoNodo->siguiente = cabeza;
            cabeza->anterior = nuevoNodo;
            cabeza = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            int indice = 0;
            while (indice < posicion - 1 && actual->siguiente) {
                actual = actual->siguiente;
                indice++;
            }
            nuevoNodo->siguiente = actual->siguiente;
            nuevoNodo->anterior = actual;
            if (actual->siguiente) {
                actual->siguiente->anterior = nuevoNodo;
            }
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrar() {
        Nodo* actual = cabeza;
        while (actual) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    bool buscar(int valor) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void eliminar(int valor) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valor) {
                if (actual->anterior) {
                    actual->anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                if (actual->siguiente) {
                    actual->siguiente->anterior = actual->anterior;
                }
                delete actual;
                return;
            }
            actual = actual->siguiente;
        }
        std::cout << "El valor no se encontro en la lista." << std::endl;
    }

    void actualizar(int valorAnterior, int valorNuevo) {
        Nodo* actual = cabeza;
        while (actual) {
            if (actual->dato == valorAnterior) {
                actual->dato = valorNuevo;
                return;
            }
            actual = actual->siguiente;
        }
        std::cout << "El valor anterior no se encontro en la lista." << std::endl;
    }

    ~ListaDoblementeEnlazada() {
        Nodo* actual = cabeza;
        while (actual) {
            Nodo* siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        }
    }
};

int main() {
    ListaDoblementeEnlazada lista;

    std::cout << "Ingresa 5 valores para agregar a la lista:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        int valor;
        std::cout << "Valor " << i + 1 << ": ";
        std::cin >> valor;
        lista.agregar(valor);
    }

    std::cout << "Lista: ";
    lista.mostrar();

    int valorBuscado;
    std::cout << "Ingresa un valor para buscar en la lista: ";
    std::cin >> valorBuscado;
    if (lista.buscar(valorBuscado)) {
        std::cout << "El valor " << valorBuscado << " se encuentra en la lista." << std::endl;
    } else {
        std::cout << "El valor " << valorBuscado << " no se encuentra en la lista." << std::endl;
    }

    int valorEliminar;
    std::cout << "Ingresa un valor para eliminar de la lista: ";
    std::cin >> valorEliminar;
    lista.eliminar(valorEliminar);

    int valorAnterior, valorNuevo;
    std::cout << "Ingresa el valor anterior y el nuevo valor para actualizar en la lista: ";
    std::cin >> valorAnterior >> valorNuevo;
    lista.actualizar(valorAnterior, valorNuevo);

    int valorInsertar, posicionInsertar;
    std::cout << "Ingresa un valor y una posicion para insertar en la lista: ";
    std::cin >> valorInsertar >> posicionInsertar;
    lista.insertar(valorInsertar, posicionInsertar);

    std::cout << "Lista actualizada: ";
    lista.mostrar();

    return 0;
}
