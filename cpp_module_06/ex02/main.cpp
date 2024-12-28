#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void) {
	int random = rand() % 3;

	if (random == 0) {
		std::cout << "A generated\n";
		return new A();
	} else if (random == 1) {
		std::cout << "B generated\n";
		return new B();
	} else {
		std::cout << "C generated\n";
		return new C();
	}
}

void identify(Base *p) {
	if (dynamic_cast<A* >(p) != NULL) {
		std::cout << "A\n";
	} else if (dynamic_cast<B* >(p) != NULL) {
		std::cout << "B\n";
	} else if (dynamic_cast<C* >(p) != NULL) {
		std::cout << "C\n";
	}
}

void identify(Base &p) {
	Base ptr;

	try {
		ptr = dynamic_cast<A& >(p);
		std::cout << "A\n";
	} catch (std::bad_cast &e) {
		try {
			ptr = dynamic_cast<B& >(p);
			std::cout << "B\n";
		} catch (std::bad_cast &e) {
			try {
				ptr = dynamic_cast<C& >(p);
				std::cout << "C\n";
			} catch (std::bad_cast &e) {
				std::cerr << "Error: " << e.what() << "\n";
			}
		}
	}
}

int main() {
	srand(time(NULL));

	Base *base = generate();
	identify(base);
	identify(*base);
	return 0;
}
