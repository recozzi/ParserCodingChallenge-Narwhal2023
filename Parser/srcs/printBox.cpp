#include "../header/Parser.hpp"

void printBox(const s_box& box, int indent)
{	
	if (box.type != "mdat")
	{
		for (int i = 0; i < indent; ++i)
			std::cout << ' ';
	}
	std::cout << "Box ID: " << box.type << " of size " << box.size << std::endl;
	if (box.type == "mdat")
	{
		std::cout << "Mdat content: " << std::endl << std::string(box.data.begin(), box.data.end());
		decodeImages(box.data);
	}
}
