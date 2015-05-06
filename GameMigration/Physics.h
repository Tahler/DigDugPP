
#ifndef PHYSICS_H
#define PHYSICS_H

#include "Core.h"

namespace Physics
{
	struct Gravity
	{
		static float acceleration;
		static int deathHeightInBlocks; // How high the character can fall from without dying
		const static float deathVelocity;
	};

	// In a typical convention, this would be called Vector2f (vector - 2 dimensional - float)
	struct Vector
	{
		float x;
		float y;
		Vector() :
			x(0), y(0)
		{}
		Vector(float x, float y) :
			x(x), y(y)
		{}
		
		Vector operator-();
		void operator=(const Vector&);
		void operator+=(const Vector&);
		void operator-=(const Vector&);
	};
	
	// They hold the same data, but have different meaning:
	// Point = location
	// Vector = displacement
	typedef Vector Point; 
	
	bool operator==(const Vector&, const Vector&);
	Vector operator+(const Vector&, const Vector&);
	Vector operator-(const Vector&, const Vector&);

	struct Line
	{
		Point a;
		Point b;

		Line() : 
			a(0, 0), b(0, 0)
		{}
		Line(Point a, Point b) : 
			a(a), b(b)
		{}
	};

	//	a - upper left point, b - lower right point	
	struct Rectangle
	{
		virtual ~Rectangle() {}

		Point a, b;

		Rectangle() :
			a(0, 0), b(0, 0)
		{}
		Rectangle(Point a, Point b) : 
			a(a), b(b) 
		{}
		
		Point getCenterPoint();

		bool contains(Point&);
		bool intersects(Rectangle&);

		virtual void draw(Core::Graphics&);
		virtual void drawAt(Core::Graphics&, Vector&);

		void operator+=(const Vector&);
	};
}

#endif