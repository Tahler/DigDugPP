
#include "Physics.h"
using namespace Physics;

float Gravity::acceleration = 0.6f;

// Vector //
Vector Physics::operator+(const Vector& left, const Vector& right)
{
	return Vector(left.x + right.x, left.y + right.y);
}
Vector Physics::operator-(const Vector& left, const Vector& right)
{
	return Vector(left.x - right.x, left.y - right.y);
}
bool Physics::operator==(const Vector& left, const Vector& right)
{
	return ((left.x == right.x) && (left.y == right.y));
}
Vector Vector::operator-()
{
	return Vector(-x, -y);
}
void Vector::operator=(const Vector& v)
{
	x = v.x;
	y = v.y;
}
void Vector::operator+=(const Vector& right)
{
	x += right.x;
	y += right.y;
}
void Vector::operator-=(const Vector& right)
{
	x -= right.x;
	y -= right.y;	
}
void drawLine(Core::Graphics& g, const Vector& left, const Vector& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}

// Rectangle //
Point Rectangle::getCenterPoint()
{
	return Point(a.x + (b.x - a.x) / 2, a.y + (b.y - a.y) / 2);
}
bool Rectangle::contains(Point& p)
{
	return (p.x >= a.x && p.x <= b.x)  // within x-axis boundaries
		&& (p.y >= a.y && p.y <= b.y); // within y-axis boundaries
}
bool Rectangle::intersects(Rectangle& r)
{
	return !(b.x < r.a.x || a.x > r.b.x || b.y < r.a.y || a.y > r.b.y);
}
void Rectangle::draw(Core::Graphics& g)
{
	g.DrawLine(a.x, a.y, b.x, a.y);
	g.DrawLine(b.x, a.y, b.x, b.y);
	g.DrawLine(b.x, b.y, a.x, b.y);
	g.DrawLine(a.x, b.y, a.x, a.y);
}
void Rectangle::drawAt(Core::Graphics& g, Vector& displacement)
{
	Point p1 = a - displacement;
	Point p2 = b - displacement;
	g.DrawLine(p1.x, p1.y, p2.x, p1.y);
	g.DrawLine(p2.x, p1.y, p2.x, p2.y);
	g.DrawLine(p2.x, p2.y, p1.x, p2.y);
	g.DrawLine(p1.x, p2.y, p1.x, p1.y);
}
void Rectangle::operator+=(const Vector& shift)
{
	a += shift;
	b += shift;
}