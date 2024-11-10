#include "Animal.hpp"
#include "DogCat.hpp"
#include "WrongAnimal.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog("Carnivore");
	const Animal *i = new Cat();
	const WrongAnimal *k = new WrongCat();

	i->makeSound();
	j->makeSound();
	k->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	delete k;
}
