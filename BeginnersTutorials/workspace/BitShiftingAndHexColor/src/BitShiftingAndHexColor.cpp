//============================================================================
// Name        : BitShiftingAndHexColor.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>

using namespace std;

int main() {

	//argb color (a: 34, r: 255, g: 158, b: 98)
	//to covert color numbers to hex, you need to get their decimal values and covert to hex value, meaning
	//To convert from decimal to hex, where hex (also known as base 16, or hexadecimal) is a positional numeral system with a radix, or base, of 16. It uses sixteen distinct symbols
	//which are                       [0, 1, 2, 3, 4, 5, 6, 7, 8, 9,  A,  B,  C,  D,  E,  F ]
	//similarly, decimal base go from [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15.]
	//by mirroring the hex and decimal table, you are then able to easily convert the argb color values above to hex in the following way
	//first understand binary rules and powers
	//16 bits[       1,       1,      1,      1,      1,      1,      1,     1,     1,     1,     1,     1,     1,     1,     1,     1 ]
	//powers [      2^15,    2^14,   2^13,   2^12,   2^11,   2^10,   2^9,   2^8,   2^7,   2^6,   2^5,   2^4,   2^3,   2^2,   2^1,   2^0]
	//result [      32768,   16384,  8192,   4096,   2048,   1024,   512,   256,   128,   64,     32,    16,    8,     4,     2,     1 ]

	//to computer color numbers to hex we need to only refer to [4096, 256, 16, 1] from the binary system

	//a: 34  === 22 in hex, meaning from the binary bits system above, only 16 or 2^4 can go into 34, it does it 2 times, which is our first decimal. so from the hex table above 2 == 2, and because (16x2=32) the remainder from 34 is 2 (34-32=2), which gives us our 2,2 hex decimal found from the number 34 which was in alpha
	//r: 255 === FF in hex, meaning 16 is the value that can go inside 255, we first get 15 from 255 (255/16= 15.xxxx) and then we you do 255 - 240(15x16) to get the remainder which is also 15, so 15 in hex table gives us f, which is why we have FF from 255 number
	//g: 158 === 9D in hex,first we get 9 when we calculate (255/16) and the remainder will be 14, and 14 in hex table is E
	//b: 98 === 62 in hex
	//now or hex color value from (a: 34, r: 255, g: 158, b: 98) is 0x22FF9E62

	//bit shifting
	// 0xFF123456
	unsigned char alpha = 0xFF;
	unsigned char red = 0x12;
	unsigned char green = 0x34;
	unsigned char blue = 0x56;

	unsigned int color = 0;

	color += alpha;

	//color = color << 8; same as color <<= 8; the bit shift << in cpp is very useful, where you would often want to shift bits and bites around, this is a great low level programming example.
	//color = color << 24;
	color <<= 8;
	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;

	//cout << color << endl;
	//cout << hex << color << endl;
	cout << setfill('0') << setw(8) << hex << color << endl;


	color >>= 8; //there is also a right bit operator >>
	color -= alpha;

	cout << setfill('0') << setw(8) << hex << color << endl;

	return 0;

}
