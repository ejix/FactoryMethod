// FactoryMethod.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Animal {
public:
	virtual void get_voice() const = 0;
	virtual ~Animal() {};

};
class Dog :public Animal
{
public:
	void get_voice() const
		{
		std::cout << "Hau Hau" << std::endl;
	}
};
class Cat : public Animal
{
	void get_voice() const {
		std::cout << "Meow Meow" << std::endl;
	}
};


class AnimalFactory {
public:
	static Animal* create_Animal(const std::string&type) {
		if (type == "Dog")return new Dog();
		else if (type == "Cat")return new Cat();
	}
};
int main()
{
	AnimalFactory factory;
	auto ptr = factory.create_Animal("Dog");
	ptr->get_voice();
	ptr=factory.create_Animal("Cat");
	ptr->get_voice();
    return 0;
}

