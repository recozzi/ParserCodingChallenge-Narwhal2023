#include "../header/Parser.hpp"

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: wrong number of arguments" << std::endl;
		std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
		return 1;
	}
	std::ifstream file(argv[1], std::ios::binary);
	if (!file.is_open() || !file.good())
	{
		std::cerr << "Error: Could not open file " << argv[1] << std::endl;
		return 1;
	}
	try{
		parseBox(file, 0);
	} catch (const std::runtime_error& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	file.close();
	return 0;
}
