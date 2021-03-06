/*
 * Bitmap.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: GeorgeQuentin
 */

#include <fstream>
#include "Bitmap.h"
#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"


using namespace bitmaptutorial;
using namespace std;

namespace bitmaptutorial {

Bitmap::Bitmap(int width, int height) :
		m_width(width),
		m_height(height),
		m_pPixels(new uint8_t[width*height*3]{ }) {//3 means multiplying by rgb color values, this {} curly brackets will initialise the pixels to zero

}

bool Bitmap::write(string filename){

	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;

	int totalSize = m_width * m_height * 3;//total size of the bitmap on the screen

	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + totalSize;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;

	ofstream file;
	file.open(filename, ios::out | ios::binary);

	if(!file){ return false; }

	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixels.get(), totalSize);

	file.close();

	if(!file){ return false; }

	return true;

}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue){

	uint8_t *pPixel = m_pPixels.get();

	//lets pretend every pixel takes one bite of information
	pPixel += (y * 3) * m_width + (x * 3); //y*m_width is the number of bites in all the rows of the bitmap, once its is pointing at the right row we then increment the x position by moving the number of columns specified using x. So now we are pointing at the right pixel, but because we are using 3 pixel we have to multiply x and y by three

	//the reason why they are in reverse order is because the bitmap is a little endian file format
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;


}

Bitmap::~Bitmap() {

}

}
