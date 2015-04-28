
#include "Physics.h"
using namespace Physics;

float Gravity::acceleration = 0.1f;

Vector::Vector()
{
	x = 0;
	y = 0;
}
Vector::Vector(float nx, float ny)
{
	x = nx;
	y = ny;
}

Point operator+(const Point& left, const Vector& right)
{
	return Point(left.x + right.x, left.y + right.y);
}
void drawLine(Core::Graphics& g, const Vector& left, const Vector& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}

Rectangle::Rectangle(Point pa, Point pb)
{
	a = pa, b = pb;
}
bool Rectangle::contains(Point& p)
{
	return (p.x >= a.x && p.x <= b.x)  // within x-axis boundaries
		&& (p.y >= a.y && p.y <= b.y); // within y-axis boundaries
}
bool Rectangle::intersects(Rectangle& r)
{
	if(b.x < r.a.x || a.x > r.b.x) return false;
	if(b.y < r.a.y || a.y > r.b.y) return false;

	// if any of its Points are inside then true
	//return (contains(r.a) || contains(r.b) || contains(Point(r.a.x, r.b.y)) || contains(Point(r.b.x, r.a.y)));
	return true;
}
bool Rectangle::touchesTop(Rectangle& r)
{
	return ((r.a.x >= a.x && r.a.x <= b.x || r.b.x >= a.x && r.b.x <= b.x) && // within x-axis boundaries
		a.y == r.b.y); // touches bottom of other rectangle
}

void Rectangle::draw(Core::Graphics& g)
{
	g.DrawLine(a.x, a.y, b.x, a.y);
	g.DrawLine(b.x, a.y, b.x, b.y);
	g.DrawLine(b.x, b.y, a.x, b.y);
	g.DrawLine(a.x, b.y, a.x, a.y);
}

Triangle::Triangle(Point pLowerLeft, Point pTop, Point pLowerRight)
{
	lowerLeft = pLowerLeft;
	top = pTop;
	lowerRight = pLowerRight;
}

Physics::Rectangle Triangle::getBoundingBox()
{
	return Rectangle(Point(lowerLeft.x, top.y), lowerRight);
}
void Triangle::draw(Core::Graphics& g)
{
	drawLine(g, lowerLeft, top);
	drawLine(g, top, lowerRight);
	drawLine(g, lowerRight, lowerLeft);
}
void Triangle::move()
{
	velocity.y += Gravity::acceleration;

	lowerLeft = lowerLeft + velocity;
	top = top + velocity;
	lowerRight = lowerRight + velocity;
}
