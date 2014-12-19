#include "triangle.h"
#include "debug.h"
#include <iostream>

#define IFDEBUG(x) if (debug>0) x;

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
}

bool side(const Point& A, const Point& B, const Point& C)
{
	return true;
}
