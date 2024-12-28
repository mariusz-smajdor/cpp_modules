#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>

template <typename T>
void iter(T *arr, int len, void (*f)(T &)) {
    for (int i = 0; i < len; i++) {
        f(arr[i]);
    }
}
