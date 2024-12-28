#pragma once

#include <iostream>
#include <stdint.h>

struct Data {
    std::string type;
    int value;
};

class Serializer {
    private:
        // Constructors and Destructor
        Serializer(void);
        Serializer(const Serializer &copy);
        ~Serializer(void);

        // Operators
        Serializer &operator=(const Serializer &copy);

    public:
        // Member functions
        static uintptr_t serialize(Data *ptr);
        static Data *deserialize(uintptr_t raw);
};