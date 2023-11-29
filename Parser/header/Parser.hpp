#ifndef PARSER_HPP
# define PARSER_HPP

# include <iostream>
# include <fstream>
# include <vector>
# include <string>
# include <cstdint>
# include <filesystem>

# define MAX_BOX_SIZE 1048576

struct s_box
{
    uint32_t size;
    std::string type;
    std::vector<char> data;
};

void parseBox(std::ifstream& file, int indent);
void decodeImages(const std::vector<char>& data);
void printBox(const s_box& box, int indent);
std::string base64Decode(const std::string& encodedStr);

#endif
