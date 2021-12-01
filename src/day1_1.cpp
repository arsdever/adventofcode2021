#include <iostream>
#include <fstream>
#include <vector>

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

	std::vector<int> input_data;
	int number;
	while (input >> number;)
	{
		input_data.push_back(number);
	}
	input.close();

	enum direction
	{
		initial,
		increase,
		same,
		decrease
	};

	std::vector<direction> dirs;
	dirs.resize(input_data.size());
	dirs[0] = direction::initial;
	for (int i = 1; i < dirs.size(); ++i)
	{
		if (input_data[i] < input_data[i - 1])
			dirs[i] = direction::decrease;
		else if (input_data[i] > input_data[i - 1])
			dirs[i] = direction::increase;
		else
			dirs[i] = direction::same;
	}

	std::cout << std::count(dirs.begin(), dirs.end(), direction::increase) << std::endl;
	return 0;
}
