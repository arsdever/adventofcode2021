#include <iostream>
#include <fstream>
#include <vector>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: day1_2 <input>" << std::endl;
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
	while (input >> number)
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
	dirs.resize(input_data.size() - 2);
	dirs[0] = direction::initial;
	for (int i = 3; i < input_data.size(); ++i)
	{
		int group_1 = input_data[i - 3] + input_data[i - 2] + input_data[i - 1];
		int group_2 = input_data[i - 2] + input_data[i - 1] + input_data[i];

		if (group_2 < group_1)
			dirs[i - 2] = direction::decrease;
		else if (group_2 > group_1)
			dirs[i - 2] = direction::increase;
		else
			dirs[i - 2] = direction::same;
	}

	std::cout << std::count(dirs.begin(), dirs.end(), direction::increase) << std::endl;
	return 0;
}
