#include <iostream>
#include <fstream>
#include "json.hpp"
#include "App.h"
#include <atomic>

using json = nlohmann::json;

//void Write()
//{
//	json j; 
//	
//	j["one"] = "sentence one";
//	j["two"] = { "sentence", 1 };
//	j["two"] = { "sentence", 1, 3 };
//
//	std::ofstream file("output.json");
//	file << j.dump(4);
//}
//
//void Read()
//{
//	std::ifstream file("output.json");
//	json j;
//
//	file >> j;
//	
//	std::cout << j["one"] << "\n";
//	std::cout << j.dump(4) << "\n";
//
//	for (auto& [key, value] : j.items())
//	{
//		std::cout << "key: " << key << ", value: " << value << std::endl;
//	}
//}

int main()
{
	std::atomic<bool> running = true;
	App app(running);

	while (running) {
		app.Go();
	}

	return 0;
}