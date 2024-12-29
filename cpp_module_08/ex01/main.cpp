#include "Span.hpp"

int main() {
    Span a = Span(5);
    
    for (int i = 0; i < 6; i++) {
        try {
            a.addNumber(i);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "Shortest span: " << a.shortestSpan() << "\n";
    std::cout << "Longest span: " << a.longestSpan() << "\n\n";

    Span b = Span(9999);
    b.addNumber(9999, time(0));
    std::cout << "Shortest span: " << b.shortestSpan() << "\n";
    std::cout << "Longest span: " << b.longestSpan() << "\n\n";
    return 0;
}