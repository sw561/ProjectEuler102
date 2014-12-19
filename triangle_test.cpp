#include "triangle.h"
#include "test.h"

short unsigned int debug = 0;

bool T(int * data)
{
	Triangle T = Triangle(data);
	return origin_in_triangle(T);
}

bool T1()
{
	int data[6] = {-340,495,-153,-910,835,-947};
	return T(data);
}

bool T2()
{
	int data[6] = {-175,41,-421,-714,574,-645};
	return T(data);
}

int main()
{
	TestSuite s = TestSuite(__FILE__);

	s.test("T1",&T1,true);
	s.test("T2",&T2,false);
}
