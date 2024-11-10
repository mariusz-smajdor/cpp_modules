#pragma once

#include <iostream>

class Animal
{
    protected:
        std::string _type;
    public:
        // Constructors and Destructor
        Animal(void);
        Animal(const std::string &type);
        Animal(const Animal &copy);
        virtual ~Animal(void);

        // Operators
        const Animal &operator=(const Animal &copy);

        // Getters and Setters
        const std::string &getType(void) const;
        void setType(const std::string &type);

        // Member functions
        virtual void makeSound(void) const;    
};
