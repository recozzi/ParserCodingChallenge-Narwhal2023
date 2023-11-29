#include "../header/Parser.hpp"

void decodeImages(const std::vector<char>& data)
{
	std::string dirPath = "../images/";
	std::filesystem::create_directory(dirPath);
	std::string filedata(data.begin(), data.end());
	size_t start = 0;
	size_t end = 0;
	int imageCount = 0;
	while ((start = filedata.find("Base64", end)) != std::string::npos)
	{
		start += 9;
		end = filedata.find("</smpte:image>", start) - 2;
		std::string imgdata(filedata, start, end - start);
		std::string image = base64Decode(imgdata);  
		std::string filename = dirPath + "image00" + std::to_string(imageCount + 1) + ".png";
		std::ofstream outfile(filename, std::ios::binary);
		outfile.write(image.c_str(), image.size());
		imageCount++;
	}
}
