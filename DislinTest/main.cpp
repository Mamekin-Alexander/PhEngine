#include <iostream>
#include "discpp.h"
#include "PhObject.h"
#include "PhSystem.h"
#include "PhTypedefs.h"
#include <fstream>
#include <utility>
typedef std::pair<double, double> Point2D;
int main()
{
	int count = 2;
	Vector xs,vs,xe,ve;
	xs = { 0, 0 };
	vs = {0,0};
	xe = { 149.6e9, 0 };
	ve = { 0, 29.783e3};
	PhSystem s(6.7e-11, 10000, 2);
	PhObject Sun(xs, vs, 1.98e30);
	PhObject Earth(xe, ve, 5.97e24);
	s.add_obj(Sun);
	s.add_obj(Earth);
	const int n =100000;


	Point2D* data = new Point2D [count];
	std::ofstream out("data.dat", std::ios::binary);
	if (!out.is_open())
		return -1;
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < count; j++)
		{

			data[j].first = s.get_object(j).get_r().at(0);
			data[j].second = s.get_object(j).get_r().at(1);
		}
		out.write(reinterpret_cast<char*>(data), count * sizeof(Point2D));
		s.move();
	}

	out.close();

	return 0;
}

