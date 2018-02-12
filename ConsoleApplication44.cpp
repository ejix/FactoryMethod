// ConsoleApplication44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>


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
	static std::unique_ptr<Animal> create_Animal(const std::string&type) {
		if (type == "Dog") return std::make_unique<Dog>();
		else if (type == "Cat")return std::make_unique<Cat>();
	}
};
int main()
{
	//AnimalFactory factory;
	std::unique_ptr<Animal> ptr{ move(AnimalFactory::create_Animal("Dog")) };
	ptr->get_voice();
    return 0;
}

