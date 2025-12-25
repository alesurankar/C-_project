#include <iostream>
#include <fstream>
#include "json.hpp"


using json = nlohmann::json;

void Write()
{
	json j; 
	
	j["one"] = "sentence one";
	j["two"] = { "sentence", 1 };
	j["two"] = { "sentence", 1, 3 };

	std::ofstream file("output.json");
	file << j.dump(4);
}

void Read()
{
	std::ifstream file("output.json");
	json j;

	file >> j;
	
	std::cout << j["one"] << "\n";
	std::cout << j.dump(4) << "\n";
}

int main()
{
	Read();


	return 0;
}