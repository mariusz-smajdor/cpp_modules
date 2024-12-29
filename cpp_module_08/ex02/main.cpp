#include "MutantStack.hpp"
#include "MutantStack.tpp"

int main() {
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
		std::cout << std::endl;
	}
	{
		MutantStack<char> charStack;
		charStack.push('a');
		charStack.push('b');
		charStack.push('c');
		charStack.push('d');
		charStack.push('e');
		std::cout << "Normal iterator" << std::endl;
		MutantStack<char>::iterator it = charStack.begin();
		MutantStack<char>::iterator ite = charStack.end();
		while (it != ite) {
			std::cout << *it << std::endl;
			++it;
		}
		std::cout << "Const iterator" << std::endl;
		MutantStack<char>::const_iterator cit = charStack.begin();
		MutantStack<char>::const_iterator cite = charStack.end();
		while (cit != cite) {
			std::cout << *cit << std::endl;
			++cit;
		}
	}
	return 0;
}
