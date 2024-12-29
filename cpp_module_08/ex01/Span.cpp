#include "Span.hpp"

// Constructors and destructor

Span::Span() : _size(0), _pos(0) {
    std::cout << "Span default constructor called" << std::endl;
}

Span::Span(unsigned int size) : _size(size), _pos(0) {
    std::cout << "Span parameterized constructor called" << std::endl;
    this->_storage.reserve(size);
}

Span::Span(const Span &copy) {
    std::cout << "Span copy constructor called" << std::endl;
    *this = copy;
}

Span::~Span(void) {
    std::cout << "Span destructor called" << std::endl;
}

// Operator overloads

Span &Span::operator=(const Span &copy) {
    std::cout << "Span assignment operator called" << std::endl;
    if (this != &copy) {
        this->_storage = copy._storage;
        this->_size = copy._size;
        this->_pos = copy._pos;
    }
    return *this;
}

// Member functions

void Span::addNumber(int number) {
    if ((this->_pos != 0 && this->_storage.empty()) || this->_storage.max_size() < this->getSize()) {
        throw Span::InvalidVectorException();
    }
    if (this->_pos >= this->_size) {
        throw Span::StorageFullException();
    }
    this->_storage.push_back(number);
    this->_pos++;
}

void Span::addNumber(unsigned int range, time_t seed) {
    srand(seed);
    for (unsigned int i = 0; i < range; i++) {
        try {
            addNumber(rand() % 100);
        } catch (const std::exception &e) {
            std::cerr << e.what() << std::endl;
        }
    }
}

unsigned int Span::shortestSpan(void) const {
    if (this->_pos < 2) {
        throw Span::NoSpanException();
    }
    std::vector<int> sorted = this->_storage;
    std::sort(sorted.begin(), sorted.end());
    unsigned int shortest = UINT_MAX;
    for (unsigned int i = 0; i < this->_pos - 1; i++) {
        if ((unsigned int)sorted[i + 1] - (unsigned int)sorted[i] < shortest) {
            shortest = sorted[i + 1] - sorted[i];
        }
    }
    return shortest;
}

unsigned int Span::longestSpan(void) const {
    if (this->_pos < 2) {
        throw Span::NoSpanException();
    }
    std::vector<int> sorted = this->_storage;
    std::sort(sorted.begin(), sorted.end());
    return sorted[this->_pos - 1] - sorted[0];
}

// Getters

unsigned int Span::getSize(void) const {
    return this->_size;
}

unsigned int Span::getPos(void) const {
    return this->_pos;
}

// Exceptions

const char *Span::StorageFullException::what() const throw() {
    return "Storage is full";
}

const char *Span::InvalidVectorException::what() const throw() {
    return "Vector is invalid";
}

const char *Span::NoSpanException::what() const throw() {
    return "No span to calculate";
}
