#include "Array.hpp"
#include "Array.tpp"

int main() {
    Array<int> arr(5);
    Array<int> copy(arr);

    for (unsigned int i = 0; i < arr.size(); i++) {
        arr[i] = i + 1;
    }
    for (unsigned int i = 0; i < copy.size(); i++) {
        std::cout << copy[i] << "\n";
    }

    Array<int> assign;
    assign = arr;

    for (unsigned int i = 0; i < assign.size(); i++) {
        std::cout << assign[i] << "\n";
    }
    try {
        arr[5] = 42;
    } catch (std::exception &e) {
        std::cout << e.what() << "\n";
    }

    std::cout << assign << "\n";
    return 0;
}