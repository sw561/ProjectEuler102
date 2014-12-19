#include "triangle.h"
#include "debug.h"
#include <iostream>

#define IFDEBUG(x)// if (debug>0) x;

Point::Point(){
	x = 0; y = 0;
}

Point::Point(int _x, int _y){
	x = _x;
	y = _y;
}

void Point::print()const{
	std::cout << x << " " << y << std::endl;
}

Triangle::Triangle(){
	A = Point();
	B = Point();
	C = Point();
}

Triangle::Triangle(const Point& _A, const Point& _B, const Point& _C){
	A = _A;
	B = _B;
	C = _C;
}

Triangle::Triangle(int * data){
	A = Point(data[0],data[1]);
	B = Point(data[2],data[3]);
	C = Point(data[4],data[5]);
}

void Triangle::print()const{
	A.print();
	B.print();
	C.print();
}

bool origin_in_triangle(const Triangle& T)
{
	IFDEBUG(T.print());
	return side(T.A,T.B,T.C) && side(T.A,T.C,T.B) && side(T.B,T.C,T.A);
//	bool s1 = side(T.A,T.B,T.C);
//	IFDEBUG(std::cout << "Side 1: " << s1 << std::endl << std::endl)
//	bool s2 = side(T.A,T.C,T.B);
//	IFDEBUG(std::cout << "Side 2: " << s2 << std::endl << std::endl)
//	bool s3 = side(T.B,T.C,T.A);
//	IFDEBUG(std::cout << "Side 3: " << s3 << std::endl << std::endl)
//	return s1 && s2 && s3;
}

bool side(const Point& A, const Point& B, const Point& C)
{
	if (A.x == B.x){
		return (C.x - A.x) * (0 - A.x) > 0;
	}

	// The line connecting A and B
	IFDEBUG(std::cout << "Using line: ")
	IFDEBUG(A.print())
	IFDEBUG(B.print())
	double m = (A.y - B.y)/(float)(A.x - B.x);
	double c = A.y - m*A.x;
	IFDEBUG(std::cout << "m = " << m << std::endl)
	IFDEBUG(std::cout << "c = " << c << std::endl)

	return side(m,c,C)*side(m,c)>0;
}

double side(double m, double c, const Point&C)
{
	IFDEBUG(std::cout << "Checking point ")
	IFDEBUG(C.print())
	double y_line = m*C.x + c;
	IFDEBUG(std::cout << y_line << std::endl)
	return C.y - y_line;
}

double side(double m, double c)
{
	static const Point origin = Point();
	return side(m,c,origin);
}
