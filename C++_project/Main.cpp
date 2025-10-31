#include "MyClass.h"
#include "Calculator.h"
#include <iostream>

int main() {
	Calculator cl;

	std::cout << cl.Sum(-4.2, 2.2);

	return 0;
}