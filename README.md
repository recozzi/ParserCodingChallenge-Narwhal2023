# Narwhal Parser Coding Challenge 2023
## Introduction
This project is a coding challenge for the 2023 Narwhal team. The goal of this challenge is to
implement a simple parser for a MPEG 4 Part 12 ISO Base Media File Format. 
The parser should be able to parse the file and print out the boxes contained in the file. The boxes should be printed in a tree-like structure, with the box type and size printed out.
If the box contains other boxes, the sub-boxes should be printed out as well. When encountering a mdat box, the parser should print out its content, that is, the media data. 
As a bonus tasks decode the mdat content into an image file (PNG).
## Usage
The project is written in C++ and uses Make as a build system. The project can be built by
running the following commands:
- Clone the repository:
`` git clone git@github.com:recozzi/ParserCodingChallenge-Narwhal2023.git``
- Move to the project directory:
`` cd Parser ``
- Compile the project with Makefile rule:
`` make ``
- Run the executable:
`` <./executable> <filename> ``
## About the implementation
The parser is implemented in the parseBox() function. The function takes two parameters: the file stream and a variable that represents the depth of the box in the tree structure. It reads the box size and type from the file stream and prints them out. If the box is a container box, the function calls itself recursively to parse the sub-boxes.

The std::streampos variable is used to keep track of the current position in the file stream, using the tellg() function. The seekg() function is used to move the file stream to the next box.

During the reading of the file, the parser searches the bytes containing the information about size and type of the box.
The size is stored in a 32-bit unsigned integer, while the type is stored in a string. The size and the type are read using the read() function, that takes as parameters the address of the variable where the data is stored and the number of bytes to read.

The parseBox() function is called in the main() function, it uses a try-catch block to perform and check if the file is a valid MPEG 4 Part 12 ISO Base Media File Format, if the file is empty or the box size is over the maximum size allowed. If one of these conditions is true, the program throws an exception.
## Bonus task 1

## Info
For more information about the project, please refer to the subject file [here](https://github.com/recozzi/ParserCodingChallenge-Narwhal2023/blob/master/subject/Parser%20Coding%20Challenge%20-%20Narwhal%202023.pdf).
## License
[here](https://github.com/recozzi/ParserCodingChallenge-Narwhal2023/blob/master/LICENSE.md).
