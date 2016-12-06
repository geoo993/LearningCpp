/*
 * BitmapFileHeader.h
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#ifndef BITMAPFILEHEADER_H_
#define BITMAPFILEHEADER_H_

#include <cstdint>

using namespace std;

#pragma pack(2)

namespace bitmaptutorial {

struct BitmapFileHeader {

	char header[2] {'B', 'M'};
	int32_t fileSize;
	int32_t reserved{ 0 };
	int32_t dataOffset;
};

}


#endif /* BITMAPFILEHEADER_H_ */
