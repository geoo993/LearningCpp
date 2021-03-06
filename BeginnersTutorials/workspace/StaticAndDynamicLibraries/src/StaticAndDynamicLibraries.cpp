//============================================================================
// Name        : StaticAndDynamicLibraries.cpp
// Author      : George Quentin
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <Cat.h>


//creating LIBRARIES of code to allow anyone to access code is a great thing to do, this is usually done by creating static or dynamic libraries
//this allows you to distribute those libraries to other users/programmers for them to use it in their code

//other user/programmers that use your shared libraries can then use it in their program
//when you compile a c++ program, first a PREPROCESSOR runs, which is anything that begins with a hash(#) i.e #include #ifDef #define
//after PREPROCESSOR you then have, COMPILATION which produces object files i.e your source files like cpp or h files, which usually have (.o) suffix. So when you compile your program on c++ you produce a bunch of (.o) which represent the object files created for that program
//then the final part of COMPILATION is LINK, which means you combine all of your (.o) files together with any LIBRARIES that you have in your program and creates an EXECUTABLE which could have (exe) on windows or (no suffix) on linux or mac
//when you link those object files to containing your code, you can also link them with external libraries that you've used to develop your program
//these libraries in c++ program are dynamic libraries, which contain the code you want to link with external programs

//when you compile a c++ program you have a choice between using DYNAMIC or STATIC libraries

//STATIC LIBRARIES are files that contain c++ code which are actually compiled into your program, they are a bunch of c++ files of code being compiled into a BINARY file which we call a static library
//the idea is to give that BINARY FILE to other programmers, they can then LINK their program with it to create their executable by compiling the code in their program while also using these STATIC LIBRARIES
//with STATIC LIBRAIES, the actual files contains the code will have suffix of (.lib such as XYZ.lib) on Windows and on UNIX/Linux/Mac they have a suffix (.a) and start with prefix (lib) such as libXYZ.a

//DYNAMIC LIBRARIES are code that are already present when you run your program, these are libraries that contain code which the program finds (note finds and not link with them) when it actually runs, so it is not when it links. And when you use things like (cout) this is from a DYNAMIC LIBRARY
//if you use (cout), your program is going to use code in a standard DYNAMIC LIBRARY thats already going to be present in your program
//so in this case with DYNAMIC LIBRARIES, your program will find the relevant code at run time
//with DYNAMIC LIBRARIES which are standard libraries in the program, the files that contain the code will have suffix of (.dll such as XYZ.dll) on Windows and on UNIX/Linux/Mac the files have a suffix of (.so) and usually have a prefix of (lib) such as libXYZ.so and finally on only the Mac, the DYNAMIC LIBRARIES files can have a suffix of (.dylib such as XYZ.dylib)



//so libraries can be very useful, especially in case of STATIC LIBRARIES which you can create and use in different projects or c++ programs
//creating a library of code is usually a great thing to do as oppose to copying code over to other programs or projects

//in the case of DYNAMIC LIBRARIES, they are shared between programs and loaded at run time and you usually put the DYNAMIC LIBRARY'S files in the working directory of your program
//in the case of STATIC LIBRARIES, these are libraries that you actually build into your code, such as extension etc..., so at the end, if you are creating your program, you would only distribute that one file (DYNAMIC LIBRARY) which has these shared coded or static libraries that you created which can be used and shared with other users/programmers


int main() {

	catnamespace::saySomething();
	catnamespace::Cat tood;
	tood.speak();

	return 0;
}



