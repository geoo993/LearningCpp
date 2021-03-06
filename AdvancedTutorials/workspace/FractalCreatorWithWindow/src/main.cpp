//============================================================================
// Name        : FractalCreatorWithWindow.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "FractalGenerator.h"

using namespace std;
using namespace fractalnamespace;

int main() {


	FractalGenerator fractalGenerator(800, 600);

	fractalGenerator.addRange(0.0, RGB((rand() % 256) , (rand() % 256) , (rand() % 256) ) );
	fractalGenerator.addRange(0.3, RGB((rand() % 256) , (rand() % 256) , (rand() % 256) ) );
	fractalGenerator.addRange(0.5, RGB((rand() % 256),  (rand() % 256) , (rand() % 256) ) );
	fractalGenerator.addRange(1.0, RGB((rand() % 256) , (rand() % 256) , (rand() % 256) ) );


	//fractalGenerator.addZoom( Zoom(354, 455, 0.1) );
	//fractalGenerator.addZoom( Zoom(312, 304, 0.1) );
	fractalGenerator.runBitmap("test.bmp");
	//fractalGenerator.runWindow();
	cout << "Finished" << endl;


	return 0;
}
