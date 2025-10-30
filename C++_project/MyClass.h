#pragma once
#include <string>

class MyClass {
public:
	MyClass(std::string text_in);
	void function() const;
	void function(std::string out) const;
private:
	std::string text;
};