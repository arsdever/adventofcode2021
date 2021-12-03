#include <iostream>
#include <fstream>
#include <vector>

#define max(a, b) ( ( a > b ) ? ( a ) : ( b ) )

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

	std::vector<int> enabled_bits_count;
	std::string val;
	int count;

	while (input >> val)
	{
		enabled_bits_count.resize(max(val.size(), enabled_bits_count.size()));
		int i = 0;
		for (char ch : val)
		{
			enabled_bits_count[i++] += ch - '0';
		}
		++count;
	}

	int gamma = 0;
	int epsilon = 0;

	for (int i = 0; i < enabled_bits_count.size(); ++i)
	{
		int idx = enabled_bits_count.size() - i - 1;
		bool common = enabled_bits_count[ idx ] > count / 2;
		gamma |= common << i;
		epsilon |= (!common) << i;
	}

	std::cout << gamma * epsilon << std::endl;

	return 0;
}
