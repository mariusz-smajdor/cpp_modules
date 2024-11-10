#include <iostream>

class Brain {
	private:
		std::string	_ideas[100];
	public:
		// Constructors and Destructors
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		// Assignment operator
		const Brain &operator=(const Brain &copy);

		// Getters and Setters
		const std::string &getIdea(const int &index) const;
		void setIdea(const std::string &idea, const int &index);
};
