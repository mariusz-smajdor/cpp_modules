#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

void useVector() {
    std::vector<int> vec;

    std::cout << "Vector:" << std::endl;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
    }
    try {
        easyfind(vec, 5);
        easyfind(vec, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void useList() {
    std::list<int> lst;

    std::cout << "List:" << std::endl;
    for (int i = 0; i < 10; i++) {
        lst.push_back(i);
    }
    try {
        easyfind(lst, 6);
        easyfind(lst, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

void useDeque() {
    std::deque<int> deq;

    std::cout << "Deque:" << std::endl;
    for (int i = 0; i < 10; i++) {
        deq.push_back(i);
    }
    try {
        easyfind(deq, 7);
        easyfind(deq, 10);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    useVector();
    useList();
    useDeque();
    return 0;
}
