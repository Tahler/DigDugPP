
#include "Core.h"
#include <iostream>
using std::cout;

struct Point
{
	float x;
	float y;
	Point(float x = 0.0f, float y = 0.0f) :
		x(x), y(y) {}
};

Point operator+(const Point& left, const Point& right)
{
	return Point(left.x + right.x, left.y + right.y);
}

void drawLine(Core::Graphics& g, const Point& left, const Point& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}

struct Gravity
{
	static float acceleration;
};
float Gravity::acceleration = 0.1f;

namespace Shapes
{	
	/*
		A - upper left
		B - lower right
	*/
	struct Rectangle
	{
		Point a, b;

		Rectangle(Point pa, Point pb)
		{
			a = pa, b = pb;
		}

		bool contains(Point p)
		{
			return (p.x >= a.x && p.x <= b.x)  // within x-axis boundaries
				&& (p.y >= a.y && p.y <= b.y); // within y-axis boundaries
		}
		bool intersects(Rectangle r)
		{
			// if any of its points are inside then true
			return (contains(r.a) || contains(r.b) || contains(Point(r.a.x, r.b.y)) || contains(Point(r.b.x, r.a.y)));
		}
		bool touchesTop(Rectangle r)
		{
			return ((r.a.x >= a.x && r.a.x <= b.x || r.b.x >= a.x && r.b.x <= b.x) && // within x-axis boundaries
				a.y == r.b.y); // touches bottom of other rectangle
		}

		void draw(Core::Graphics& g)
		{
			g.DrawLine(a.x, a.y, b.x, a.y);
			g.DrawLine(b.x, a.y, b.x, b.y);
			g.DrawLine(b.x, b.y, a.x, b.y);
			g.DrawLine(a.x, b.y, a.x, a.y);
		}
	};

	struct Triangle
	{
		Point lowerLeft;
		Point top;
		Point lowerRight;

		Point velocity;

		Triangle(Point pLowerLeft, Point pTop, Point pLowerRight)
		{
			lowerLeft = pLowerLeft;
			top = pTop;
			lowerRight = pLowerRight;
		}

		Rectangle hitbox()
		{
			return Rectangle(Point(lowerLeft.x, top.y), lowerRight);
		}
		void draw(Core::Graphics& g)
		{
			drawLine(g, lowerLeft, top);
			drawLine(g, top, lowerRight);
			drawLine(g, lowerRight, lowerLeft);
		}
		void move()
		{
			velocity.y += Gravity::acceleration;
			
			lowerLeft = lowerLeft + velocity;
			top = top + velocity;
			lowerRight = lowerRight + velocity;
		}
	};
}

Shapes::Rectangle rect(Point(350, 500), Point(450, 600));
Shapes::Triangle tri(Point(350, 400), Point(400, 350), Point(450, 400));

void checkKeyInput()
{
	float pushAcceleration = 0.2;
	
	if (Core::Input::IsPressed(Core::Input::KEY_UP))
	{
		if (!tri.hitbox().touchesTop(rect)) // check the top
		{
			tri.velocity.y -= pushAcceleration;
		}
	}

	if (Core::Input::IsPressed(Core::Input::KEY_DOWN))
		tri.velocity.y += pushAcceleration;

	if (Core::Input::IsPressed(Core::Input::KEY_LEFT))
		tri.velocity.x -= pushAcceleration;

	if (Core::Input::IsPressed(Core::Input::KEY_RIGHT))
		tri.velocity.x += pushAcceleration;
}
////////////////////////////////////////////////////////////
bool update(float dt)
{
	checkKeyInput();
	//if (!(tri.hitbox().intersects(rect)))
	//{
		tri.move();
	//}
	//if (!rect.contains(tri.lowerLeft)) tri.move();
	return false;
}

void draw(Core::Graphics& graphics)
{
	rect.draw(graphics);
	tri.draw(graphics);
}

void main()
{
	Core::Init("My Game", 800, 800);
	Core::RegisterUpdateFn(update);
	Core::RegisterDrawFn(draw);
	Core::GameLoop();
}