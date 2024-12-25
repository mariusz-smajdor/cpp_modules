#include "ScalarConverter.hpp"

// Constructors and Destructor

ScalarConverter::ScalarConverter(void) {
    std::cout << "ScalarConverter created" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy) {
    std::cout << "ScalarConverter was copied" << std::endl;
    *this = copy;
}

ScalarConverter::~ScalarConverter(void) {
    std::cout << "ScalarConverter destroyed" << std::endl;
}

// Operators

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy) {
    (void)copy;
    return *this;
}

// Member functions

void print(float representation) {
	const char char_value = static_cast<char>(representation);
	const long long_value = static_cast<long>(representation);
	bool end_in_zero = static_cast<int>(representation) - representation == 0;

	std::cout << "char: ";
	if (representation < CHAR_MIN || representation > CHAR_MAX || std::isnan(representation))
		std::cout << "impossible" << std::endl;
	else if (!isprint(representation))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << char_value << "'" << std::endl;

	std::cout << "int: ";
	if (long_value < INT_MIN || long_value > INT_MAX || std::isnan(representation))
		std::cout << "impossible" << std::endl;
	else
		std::cout << long_value << std::endl;

	std::cout << "float: " << representation;
	if (end_in_zero)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << static_cast<double>(representation);
	if (end_in_zero)
		std::cout << ".0";
	std::cout << std::endl;
}

void print(double representation) {
	const char char_value = static_cast<char>(representation);
	const long long_value = static_cast<long>(representation);
	bool end_in_zero = static_cast<int>(representation) - representation == 0;

	std::cout << "char: ";
	if (representation < CHAR_MIN || representation > CHAR_MAX || isnan(representation))
		std::cout << "impossible" << std::endl;
	else if (!isprint(representation))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << char_value << "'" << std::endl;

	std::cout << "int: ";
	if (long_value < INT_MIN || long_value > INT_MAX || isnan(representation))
		std::cout << "impossible" << std::endl;
	else
		std::cout << long_value << std::endl;

	std::cout << "float: " << static_cast<float>(representation);
	if (end_in_zero)
		std::cout << ".0";
	std::cout << "f" << std::endl;

	std::cout << "double: " << representation;
	if (end_in_zero)
		std::cout << ".0";
	std::cout << std::endl;
}

void print(int representation) {
	const char char_value = static_cast<char>(representation);

	std::cout << "char: ";
	if (representation < CHAR_MIN || representation > CHAR_MAX)
		std::cout << "impossible" << std::endl;
	else if (!isprint(representation))
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << char_value << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(representation) << std::endl;
	std::cout << "float: " << static_cast<float>(representation) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(representation) << ".0" << std::endl;
}

void print(char representation) {
	std::cout << "char: '" << representation << "'" << std::endl;
	std::cout << "int: " << static_cast<int>(representation) << std::endl;
	std::cout << "float: " << static_cast<float>(representation) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(representation) << ".0" << std::endl;
}

bool is_double(const std::string &str) {
    return (str.find_first_not_of("0123456789.-") == std::string::npos && str.find(".") != std::string::npos
		&& (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == "-inf" || str == "+inf" || str == "nan");
}

bool is_float(const std::string &str) {
    return (str.find_first_not_of("0123456789.f-") == std::string::npos && str.find(".") != std::string::npos
		&& str.find("f", str.length() - 1)!= std::string::npos && (str.find("-") == 0 || str.find("-") == std::string::npos))
		|| ( str == "-inff" || str == "+inff" || str == "nanf") ;
}

bool is_int(const std::string &str) {
    return str.find_first_not_of("0123456789.-") == std::string::npos && ((str.find("-") == 0 && str.length() > 1 ) || str.find("-") == std::string::npos);
}

void ScalarConverter::convert(const std::string &representation) {
	if (is_float(representation))
		print(std::atof(representation.c_str()));
	else if (is_double(representation))
		print((double)std::atof(representation.c_str()));
	else if (is_int(representation))
		print(std::atoi(representation.c_str()));
	else if (representation.length() == 1)
		print(representation[0]);
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}