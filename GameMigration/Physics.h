
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

	/*
		A - upper left
		B - lower right
	*/
	struct Rectangle
	{
		Vector a, b;
		Rectangle(Vector pa, Vector pb);

		bool contains(Vector &p);
		bool intersects(Rectangle &r);
		bool touchesTop(Rectangle &r);
		void draw(Core::Graphics &g);
	};

	struct Triangle
	{
		Vector lowerLeft;
		Vector top;
		Vector lowerRight;

		Vector velocity;

		Triangle(Vector pLowerLeft, Vector pTop, Vector pLowerRight);

		Rectangle getBoundingBox();
		void draw(Core::Graphics &g);
		void move();
	};
}

#endif