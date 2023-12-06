#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	// std::cout << "--------------- Animal ---------------" << std::endl;

    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // std::cout << "J Type: " << j->getType() << " " << std::endl;
    // std::cout << "I Type: " << i->getType() << " " << std::endl;
    // i->makeSound();
    // j->makeSound();
    // meta->makeSound();

    // delete  meta;
    // delete  j;
    // delete  i;
    size_t  count = 4;

    Animal  *animals[count];

    // Create animals
    std::cout << "--------------- Create Animals ---------------" << std::endl;
    for (size_t i = 0; i < count; i++)
    {
        if (i < count / 2) {
            animals[i] = new Cat();
        }
        else {
            animals[i] = new Dog();
        }
        animals[i]->makeSound();
    }

    // Give animals some ideas
    ((Cat *)animals[0])->getBrain()->ideas[0] = "Idea 1";
    ((Cat *)animals[0])->getBrain()->ideas[1] = "Idea 2";
    ((Cat *)animals[0])->getBrain()->ideas[2] = "Idea 3";
    ((Cat *)animals[0])->getBrain()->ideas[3] = "Idea 4";
    ((Cat *)animals[0])->getBrain()->ideas[4] = "Idea 5";

    ((Dog *)animals[2])->getBrain()->ideas[0] = "Idea 1";
    ((Dog *)animals[2])->getBrain()->ideas[1] = "Idea 2";
    ((Dog *)animals[2])->getBrain()->ideas[2] = "Idea 3";

    // Copy animals
    std::cout << "--------------- Copy Animals ---------------" << std::endl;
    Cat *cat1copy = new Cat(*(Cat *)animals[0]);
    Dog *dog1copy = new Dog(*(Dog *)animals[2]);

    // Check if animals are the same
    std::cout << "--------------- Check If Animals Are The Same ---------------" << std::endl;
    std::cout << "Cat 1: " << cat1copy->getType() << std::endl;
    std::cout << "Dog 1: " << dog1copy->getType() << std::endl;

    // Check if animals have the same ideas
    std::cout << "--------------- Check If Animals Have The Same Ideas ---------------" << std::endl;
    std::cout << "Cat 1 Ideas: " << std::endl;
    for (size_t i = 0; i < 5; i++)
    {
        std::cout << "Idea " << i + 1 << ": " << cat1copy->getBrain()->ideas[i] << std::endl;
    }

    std::cout << "Dog 1 Ideas: " << std::endl;
    for (size_t i = 0; i < 3; i++)
    {
        std::cout << "Idea " << i + 1 << ": " << dog1copy->getBrain()->ideas[i] << std::endl;
    }

    // Delete copies
    std::cout << "--------------- Delete Copies ---------------" << std::endl;
    delete cat1copy;
    delete dog1copy;

    // Delete animals
    std::cout << "--------------- Delete Animals ---------------" << std::endl;
    for (size_t i = 0; i < count; i++)
    {
        delete animals[i];
    }

    return 0;
}
