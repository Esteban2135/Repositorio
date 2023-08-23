#include <iostream>

class BinarySearch {
private:
    int* arr;
    int size;

public:
    BinarySearch(int a[], int s) : arr(a), size(s) {}

    int search(int target) {
        int left = 0;
        int right = size - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                return mid; 
            } else if (arr[mid] < target) {
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }

        return -1; 
    }
};

int main() {
    int list1[] = {1, 3, 5, 7, 9};
    int list2[] = {11, 13, 15, 17, 19};
    int list3[] = {21, 23, 25, 27, 29};
    int target;

    std::cout << "Ingrese un número impar del 1 al 30: ";
    std::cin >> target;

    BinarySearch searches[] = {BinarySearch(list1, sizeof(list1) / sizeof(list1[0])),
                               BinarySearch(list2, sizeof(list2) / sizeof(list2[0])),
                               BinarySearch(list3, sizeof(list3) / sizeof(list3[0]))};

    bool found = false;

    for (int i = 0; i < 3; ++i) {
        int index = searches[i].search(target);
        if (index != -1) {
            found = true;
            int* foundPtr = &searches[i].arr[index];  
            std::cout << "El elemento " << target << " se encuentra en la lista " << (i + 1)
                      << ", posición " << index << ". Dirección de memoria: " << foundPtr << std::endl;
        }
    }

    if (!found) {
        std::cout << "El elemento " << target << " no se encontró en ninguna lista." << std::endl;
    }

    std::cout << "Presione Enter para salir.";
    std::cin.ignore();  
    std::cin.get();     
    return 0;
}
