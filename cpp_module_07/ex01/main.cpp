#include "iter.hpp"

void toUpper(char &c) {
    if (c >= 'a' && c <= 'z') {
        c -= 32;
    }
}

void addOne(int &n) {
    n++;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};

    ::iter(arr, 5, addOne);
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << "\n";
    }

    char *str = strdup("Hello");
    ::iter(str, 6, toUpper);
    for (int i = 0; i < 6; i++) {
        std::cout << str[i];
    }
    std::cout << "\n";
    free(str);

    return 0;
}