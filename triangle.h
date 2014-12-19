#ifndef TRIANGLE_H
#define TRIANGLE_H

struct Point{
	Point();
	Point(int,int);
	void print()const;
	int x;
	int y;
};

struct Triangle{
	Triangle();
	Triangle(const Point&, const Point&, const Point&);
	Triangle(int *);
	void print()const;
	Point A;
	Point B;
	Point C;
};

bool origin_in_triangle(const Triangle&);

// Check that C is same side of AB as the origin
bool side(const Point& A, const Point& B, const Point& C);

// Return C.y - position of line at C.x
double side(double m, double c, const Point& C);

// The same as above, where C is the origin
double side(double m, double c);

#endif
