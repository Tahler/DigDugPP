
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
	};

	// They hold the same data, but have different meaning:
	// Point = location
	// Vector = displacement
	typedef Vector Point; 
	
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
		bool touchesTop(Rectangle& r);
		void draw(Core::Graphics& g);
	};

	struct Triangle
	{
		Point lowerLeft;
		Point top;
		Point lowerRight;

		Vector velocity;

		Triangle(Point pLowerLeft, Point pTop, Point pLowerRight);

		Rectangle getBoundingBox();
		void draw(Core::Graphics& g);
		void move();
	};
}

#endif