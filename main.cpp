#include <iostream>
#include <sstream>
#include <fstream>
#include <stdlib.h>
#include "triangle.h"

// Global variable used to toggle run-time debugging
short unsigned int debug;

int main(int argc, char* argv[])
{
	// Debug variable
	if (argc>=3) std::istringstream(argv[2]) >> debug;
	else debug = 0;
//--------------------------------------------------//
	
	std::ifstream input;
	input.open("p102_triangles.txt");

	// Number of triangles which contain origin
	int count = 0;

	std::string line;
	std::string number;
	int x;
	int index;
	int data[6];

	while (std::getline(input,line))
	{
		// Convert comma delimited line to an array of integers called data
		index = 0;
		std::stringstream line_stream(line);
		while (std::getline(line_stream,number,',')){
			x = atoi(number.c_str());
			data[index++] = x;
		}
		
		// Check if the triangle contains origin
		Triangle T(data);
		if (origin_in_triangle(T)) count++;
	}

	std::cout << count << std::endl;

	input.close();
		
	return 0;
}
