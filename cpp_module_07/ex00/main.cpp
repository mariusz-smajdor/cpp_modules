#include "templates.hpp"

int main() {
    std::cout << "Integers:\n";
    {
        int a = 2;
        int b = 3;

        std::cout << "Before swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n";
        ::swap(a, b);
        std::cout << "After swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n\n";

        std::cout << "Max of 2 and 3:\n";
        std::cout << "max(2, 3) = " << ::max(a, b) << "\n";
        std::cout << "Min of 2 and 3:\n";
        std::cout << "min(2, 3) = " << ::min(a, b) << "\n\n";
    }
    std::cout << "Floats:\n";
    {
        float a = 2.5f;
        float b = 3.5f;

        std::cout << "Before swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n";
        ::swap(a, b);
        std::cout << "After swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n\n";

        std::cout << "Max of 2.5 and 3.5:\n";
        std::cout << "max(2.5, 3.5) = " << ::max(a, b) << "\n";
        std::cout << "Min of 2.5 and 3.5:\n";
        std::cout << "min(2.5, 3.5) = " << ::min(a, b) << "\n\n";
    }
    std::cout << "Chars:\n";
    {
        char a = 'a';
        char b = 'b';

        std::cout << "Before swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n";
        ::swap(a, b);
        std::cout << "After swap:\n";
        std::cout << "a = " << a << ", b = " << b << "\n\n";

        std::cout << "Max of 2 and 3:\n";
        std::cout << "max(2, 3) = " << ::max(a, b) << "\n";
        std::cout << "Min of 2 and 3:\n";
        std::cout << "min(2, 3) = " << ::min(a, b) << "\n\n";
    }
    return 0;
}