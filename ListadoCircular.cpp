#include <iostream>

struct Nodo {
    int dato;
    Nodo* siguiente;

    Nodo(int valor) : dato(valor), siguiente(nullptr) {}
};

class ListaEnlazadaCircular {
private:
    Nodo* cabeza;

public:
    ListaEnlazadaCircular() : cabeza(nullptr) {}

    void agregar(int valor) {
        Nodo* nuevoNodo = new Nodo(valor);
        if (!cabeza) {
            nuevoNodo->siguiente = nuevoNodo; 
            cabeza = nuevoNodo;
        } else {
            nuevoNodo->siguiente = cabeza->siguiente;
            cabeza->siguiente = nuevoNodo;
            cabeza = nuevoNodo;
        }
    }

    void insertar(int valor, int posicion) {
        if (posicion < 0) {
            std::cout << "La posición no puede ser negativa." << std::endl;
            return;
        }

        Nodo* nuevoNodo = new Nodo(valor);

        if (!cabeza) {
            nuevoNodo->siguiente = nuevoNodo; 
            cabeza = nuevoNodo;
        } else if (posicion == 0) {
            nuevoNodo->siguiente = cabeza->siguiente;
            cabeza->siguiente = nuevoNodo;
        } else {
            Nodo* actual = cabeza;
            int indice = 0;
            while (indice < posicion - 1) {
                actual = actual->siguiente;
                indice++;
            }
            nuevoNodo->siguiente = actual->siguiente;
            actual->siguiente = nuevoNodo;
        }
    }

    void mostrar() {
        if (!cabeza) {
            std::cout << "La lista está vacia." << std::endl;
            return;
        }
        Nodo* actual = cabeza->siguiente;
        do {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        } while (actual != cabeza->siguiente);
        std::cout << std::endl;
    }

    bool buscar(int valor) {
        if (!cabeza) {
            return false;
        }
        Nodo* actual = cabeza->siguiente;
        do {
            if (actual->dato == valor) {
                return true;
            }
            actual = actual->siguiente;
        } while (actual != cabeza->siguiente);
        return false;
    }

    void eliminar(int valor) {
        if (!cabeza) {
            std::cout << "La lista esta vacia." << std::endl;
            return;
        }
        Nodo* actual = cabeza;
        Nodo* anterior = nullptr;

        do {
            if (actual->dato == valor) {
                if (actual == cabeza) {
                    cabeza = cabeza->siguiente;
                }
                anterior->siguiente = actual->siguiente;
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        } while (actual != cabeza);

        std::cout << "El valor no se encontro en la lista." << std::endl;
    }

    void actualizar(int valorAnterior, int valorNuevo) {
        if (!cabeza) {
            std::cout << "La lista está vacia." << std::endl;
            return;
        }
        Nodo* actual = cabeza->siguiente;
        do {
            if (actual->dato == valorAnterior) {
                actual->dato = valorNuevo;
                return;
            }
            actual = actual->siguiente;
        } while (actual != cabeza->siguiente);

        std::cout << "El valor anterior no se encontro en la lista." << std::endl;
    }

    ~ListaEnlazadaCircular() {
        if (cabeza) {
            Nodo* actual = cabeza->siguiente;
            do {
                Nodo* siguiente = actual->siguiente;
                delete actual;
                actual = siguiente;
            } while (actual != cabeza->siguiente);
        }
    }
};

int main() {
    ListaEnlazadaCircular lista;

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
    std::cout << "Ingresa un valor y una posición para insertar en la lista: ";
    std::cin >> valorInsertar >> posicionInsertar;
    lista.insertar(valorInsertar, posicionInsertar);

    std::cout << "Lista actualizada: ";
    lista.mostrar();

    return 0;
}