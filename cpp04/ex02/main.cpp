#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#define COUNT 3

int main()
{
	{
		const	AAnimal *j = new Dog();
		const	AAnimal *i = new Cat();

		delete j;
		delete i;
	}
	std::cout << "=== Polymorphic array test ===" << std::endl;
	AAnimal			*animals[COUNT];

	for (size_t i = 0; i < COUNT; ++i)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;
	for (size_t i = 0; i < COUNT; ++i)
	{
		std::cout << animals[i]->getType() << " makes sound: ";
		animals[i]->makeSound();
	}

	std::cout << std::endl;
	for (size_t i = 0; i < COUNT; ++i)
		delete animals[i];

	std::cout << std::endl;
	std::cout << "=== Deep copy behavior check ===" << std::endl;
	{
		std::cout << "\n-- Cat copy constructor --" << std::endl;
		Cat	original;
		Cat	copy(original);
	}
	{
		std::cout << "\n-- Cat copy assignment --" << std::endl;
		Cat	original;
		Cat	assigned;
		assigned = original;
	}
	{
		std::cout << "\n-- Dog copy constructor --" << std::endl;
		Dog	original;
		Dog	copy(original);
	}
	{
		std::cout << "\n-- Dog copy assignment --" << std::endl;
		Dog	original;
		Dog	assigned;
		assigned = original;
	}

	std::cout << std::endl;
	std::cout << "=== WrongAnimal polymorphism check ===" << std::endl;
	const WrongAnimal	*wrong = new WrongCat();
	std::cout << wrong->getType() << " makes sound: ";
	wrong->makeSound();
	delete wrong;

	return (0);
}
