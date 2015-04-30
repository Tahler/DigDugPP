
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Core.h"

namespace Physics
{
	struct Gravity
	{
		static float acceleration;
	};

	// In a typical convention, this would be called Vector2f (vector - 2 dimensional - float)
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
	
	Vector operator+(const Vector&, const Vector&);

	struct Line
	{
		Point a;
		Point b;

		Line();
		Line(Point pa, Point pb);
	};

	//	a - upper left point, b - lower right point	
	struct Rectangle
	{
		Point a, b;

		Rectangle() {}
		Rectangle(Point, Point);
		
		void setPoints(Point, Point);

		bool contains(Point&);
		bool intersects(Rectangle&);

		virtual void draw(Core::Graphics& g);
	};
}

#endif