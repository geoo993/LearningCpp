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

	int width = 800;
	int height = 620;
	bool smooth_coloring = true;
	string output = "window"; //bitmap or window
	FractalGenerator fractalGenerator(width, height, smooth_coloring, output);

	fractalGenerator.run();
	cout << "Finished" << endl;


	return 0;
}