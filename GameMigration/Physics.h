
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Core.h"

namespace Physics
{
	struct Gravity
	{
		static float acceleration;
	};

	struct Point
	{
		float x;
		float y;
		Point();
		Point(float x, float y);
	};

	struct Vector
	{
		Point p;
		float magnitude;
		Vector();
		Vector(float x, float y, float m);
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
		bool touchesTop(Rectangle& r);
		void draw(Core::Graphics& g);
	};

	struct Triangle
	{
		Point lowerLeft;
		Point top;
		Point lowerRight;

		Point velocity;

		Triangle(Point pLowerLeft, Point pTop, Point pLowerRight);

		Rectangle hitbox();
		void draw(Core::Graphics& g);
		void move();
	};
}

#endif