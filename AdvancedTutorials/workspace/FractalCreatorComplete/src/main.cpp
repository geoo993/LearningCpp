//============================================================================
// Name        : FractalCreatorComplete.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FractalGenerator.h"

using namespace std;
using namespace bitmaptutorial;

int main() {

	FractalGenerator fractalGenerator(800, 600);

	fractalGenerator.addRange(0.0, RGB(0, 0, 255) );
	fractalGenerator.addRange(0.3, RGB(255, 255, 0) );
	fractalGenerator.addRange(0.5, RGB(0, 255, 0) );
	fractalGenerator.addRange(1.0, RGB(0, 0, 255) );

	fractalGenerator.addZoom( Zoom(295, 202, 0.1) );
	fractalGenerator.addZoom( Zoom(312, 304, 0.1) );
	fractalGenerator.run("test.bmp");

	cout << "Finished" << endl;

	return 0;
}
