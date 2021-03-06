/*
 * BitmapInfoHeader.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef BITMAPINFOHEADER_H_
#define BITMAPINFOHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmaptutorial {

struct BitmapInfoHeader {

	int32_t headerSize{40};//size of struct
	int32_t width;//width of actual bitmap
	int32_t height;//height of actual bitmap
	int16_t planes{1};
	int16_t bitsPerPixel{24}; //we are going one bite of 8 bit color in a bitmap, so 3*8 = 24, so its going to be rgb color with each being 8 bits
	int32_t compression{0};
	int32_t dataSize{0};//the size of data that we write to the bitmap file
	int32_t horizontalResolution{2400};// this means 2400 bits per pixel
	int32_t verticalResolution{2400};//this means 2400 bits per pixel
	int32_t colors{0};
	int32_t importantColors{0};

};

}

#endif /* BITMAPINFOHEADER_H_ */
