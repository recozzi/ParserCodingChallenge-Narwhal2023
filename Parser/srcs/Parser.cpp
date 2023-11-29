#include "../header/Parser.hpp"

static s_box readBox(std::ifstream& file)
{
	s_box box;
	if (!file.read(static_cast<char*>(reinterpret_cast<void*>(&box.size)), 4))
		return box;
	box.size = __builtin_bswap32(box.size);
	char type[5] = {0};
	file.read(type, 4);
	box.type = type;
	if (box.size > 8)
	{
		if (box.size - 8 > MAX_BOX_SIZE)
			throw std::runtime_error("Box size is too big");
		box.data.resize(box.size - 8);
		file.read(box.data.data(), box.data.size());
	}
	return box;
}

/**
* @brief
* 	Parse the file and print the boxes, recursively.
* @param file
* 	The file to parse
* @param indent
* 	The indentation level
*/
void parseBox(std::ifstream& file, int indent)
{
	if (file.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("File is empty or wrong format");
	s_box box;
	while (!file.eof())
	{
		box = readBox(file);
		if (box.type.empty() || box.size < 8)
			break;
		printBox(box, indent);
		if (box.type == "moof" || box.type == "traf")
		{
			std::streampos startPos = file.tellg();
			file.seekg(startPos - std::streamoff(box.data.size()));
			parseBox(file, indent + 2);
			file.seekg(startPos + std::streamoff(box.size));
		}
	}
}
