#include "../header/Parser.hpp"

std::string base64Chars = 
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            	"abcdefghijklmnopqrstuvwxyz"
            	"0123456789+/";

static inline bool isBase64(unsigned char c)
{
  return (isalnum(c) || (c == '+') || (c == '/'));
}

/**
* @brief
* 	Decode a base64 string.
*	I found this function on StackOverflow to help me decode the images.
*	You can find the original post here: https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c, with the relative documentation.
* @param encodedStr
* 	The base64 string to decode.
* @return
* 	The decoded string.
*/
std::string base64Decode(const std::string& encodedStr)
{
	int i = 0;
	int j = 0;
	int h = 0;
	int lenStr = encodedStr.size();
	unsigned char array4[4], array3[3];
	std::string result;
	while (lenStr-- && ( encodedStr[h] != '=') && isBase64(encodedStr[h]))
	{
		array4[i++] = encodedStr[h];
		h++;
		if (i ==4)
		{
			for (i = 0; i <4; i++)
			  array4[i] = base64Chars.find(array4[i]);
			array3[0] = (array4[0] << 2) + ((array4[1] & 0x30) >> 4);
			array3[1] = ((array4[1] & 0xf) << 4) + ((array4[2] & 0x3c) >> 2);
			array3[2] = ((array4[2] & 0x3) << 6) + array4[3];
			for (i = 0; (i < 3); i++)
			  result += array3[i];
			i = 0;
		}
	}
	if (i)
	{
		for (j = i; j <4; j++)
		  array4[j] = 0;
		for (j = 0; j <4; j++)
		  array4[j] = base64Chars.find(array4[j]);
		array3[0] = (array4[0] << 2) + ((array4[1] & 0x30) >> 4);
		array3[1] = ((array4[1] & 0xf) << 4) + ((array4[2] & 0x3c) >> 2);
		array3[2] = ((array4[2] & 0x3) << 6) + array4[3];
		for (j = 0; (j < i - 1); j++)
			result += array3[j];
	}
	return result;
}
