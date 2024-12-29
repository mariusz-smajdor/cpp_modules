#include "RPN.hpp"

int main(int argc, char *argv[])
{
	RPN rpn = RPN();

	if (argc != 2) {
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	try {
		std::cout << rpn.result(argv[1]) << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
    return 0;
}
