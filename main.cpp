#include <iostream>
#include <sstream>
#include "triangle.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;
//--------------------------------------------------//
	
	int data[6] = {1,5,-6,10,0,-3};

	std::cout << origin_in_triangle(data) << std::endl;

	return 0;
}
