#include "Serializer.hpp"

// Constructors and Destructor
Serializer::Serializer(void) {
    std::cout << "Serializer constructor called" << std::endl;
}

Serializer::Serializer(const Serializer &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Serializer::~Serializer(void) {
    std::cout << "Serializer destructor called" << std::endl;
}

// Operators

Serializer &Serializer::operator=(const Serializer &copy) {
    (void)copy;

    std::cout << "Assignation operator called" << std::endl;
    return (*this);
}

// Member functions

uintptr_t Serializer::serialize(Data *ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data *Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data *>(raw));
}
