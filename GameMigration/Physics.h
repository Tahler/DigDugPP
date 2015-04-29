
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Core.h"

namespace Physics
{
	struct Gravity
	{
		static float acceleration;
	};

	// In a typical convention, this would be called Vector2f (vector - 2d - float)
	struct Vector
	{
		float x;
		float y;
		Vector();
		Vector(float nx, float ny);
		
		void operator=(const Vector&);
		void operator+=(const Vector&);
	};

	// They hold the same data, but have different meaning:
	// Point = location
	// Vector = displacement
	typedef Vector Point; 
	
	struct Line
	{
		Point a;
		Point b;

		Line();
		Line(Point pa, Point pb);
	};

	/*
		A - upper left
		B - lower right
	*/
	struct Rectangle
	{
		Point a, b;
		Rectangle(Point pa, Point pb);

		bool contains(Point& p);
		bool intersects(Rectangle& r);

		void draw(Core::Graphics& g);
	};
}

#endif