#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *meta = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;
	std::cout << "Animal types:" << std::endl;
	std::cout << "- meta: " << meta->getType() << std::endl;
	std::cout << "- dog : " << dog->getType() << std::endl;
	std::cout << "- cat : " << cat->getType() << std::endl;

	std::cout << std::endl;
	std::cout << "Animal sounds:" << std::endl;
	meta->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;
	WrongAnimal wrongMeta;
	WrongCat wrongKitty;
	const WrongAnimal *wrongRef = &wrongKitty;

	std::cout << "WrongAnimal types:" << std::endl;
	std::cout << "- wrongMeta : " << wrongMeta.getType() << std::endl;
	std::cout << "- wrongKitty: " << wrongKitty.getType() << std::endl;

	std::cout << std::endl;
	std::cout << "WrongAnimal sounds (expect base implementation twice):" << std::endl;
	wrongMeta.makeSound();
	wrongRef->makeSound();

	std::cout << std::endl;
	delete meta;
	delete dog;
	delete cat;

	return 0;
}
