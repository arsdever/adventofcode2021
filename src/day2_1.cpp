#include <iostream>
#include <fstream>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: day1_1 <input>" << std::endl;
		return 1;
	}

	std::ifstream input(argv[1]);
	if (!input.is_open())
	{
		std::cerr << "Cannot open file " << argv[1] << std::endl;
		return 2;
	}

	std::string command;
	int value;
	int v = 0;
	int h = 0;

	while (input >> command)
	{
		input >> value;
		if (command == "forward")
			h += value;
		else if (command == "up")
			v -= value;
		else if (command == "down")
			v += value;
	}

	std::cout << v * h << std::endl;

	return 0;
}
