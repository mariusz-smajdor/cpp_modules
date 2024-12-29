#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &src) {
	*this = src;
}

RPN::~RPN() {}

RPN &RPN::operator= (const RPN &src) {
	(void)src;
	return *this;
}

float RPN::result(const std::string expr) {
	std::list<float> elems;
	bool is_space = false;

	for (std::string::const_iterator it = expr.begin(); it != expr.end(); it++) {
		if (*it != ' ' && !is_space && elems.size() != 0)
			throw RPN::BadExpressionException();
		is_space = *it == ' ';
		if (*it == ' ') {
			continue;
        }
		if (isdigit(*it)) {
			elems.push_back(*it - '0');
		} else {
			if (elems.size() < 2) {
				throw RPN::BadExpressionException();
            }
			float l1 = elems.back();
			elems.pop_back();
			float l2 = elems.back();
			elems.pop_back();
			switch (*it) {
                case '+':
                    elems.push_back(l2 + l1);
                    break;
                case '-':
                    elems.push_back(l2 - l1);
                    break;
                case '/':
                    if (l1 == 0)
                        throw RPN::BadDivision();
                    elems.push_back(l2 / l1);
                    break;
                case '*':
                    elems.push_back(l2 * l1);
                    break;
                default:
                    throw RPN::BadExpressionException();
                    break;
			}
		}
	}
	if (elems.size() != 1)
    {
		throw RPN::RemainingOperators();
    }
	return elems.front();
}

const char *RPN::BadExpressionException::what() const throw() {
	return ("error: malformed expression");
}

const char *RPN::BadDivision::what() const throw() {
	return ("error: division by 0 is not allowed");
}

const char *RPN::RemainingOperators::what() const throw() {
	return ("error: remainging operators");
}
