#include "MyClass.h"
#include <iostream>
#include <utility>

MyClass::MyClass(std::string text_in)
	:
	text(std::move(text_in))
{}

void MyClass::function() const
{
	std::cout << text;
}

void MyClass::function(std::string out) const
{
	std::cout << out;
}
