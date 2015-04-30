
#include "Physics.h"
using namespace Physics;

float Gravity::acceleration = 0.1f;

// Vector //
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
Vector operator+(const Vector& left, const Vector& right)
{
	return Vector(left.x + right.x, left.y + right.y);
}
//Point operator+(Point& left, Vector& right)
//{
//	return Point(left.x + right.x, left.y + right.y);
//}
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
void drawLine(Core::Graphics& g, const Vector& left, const Vector& right)
{
	g.DrawLine(left.x, left.y, right.x, right.y);
}

// Line //
Line::Line()
{
	a = Point(0, 0);
	b = Point(0, 0);
}
Line::Line(Point pa, Point pb)
{
	a = pa;
	b = pb;
}

// Rectangle //
Rectangle::Rectangle(Point pa, Point pb)
{
	a = pa, b = pb;
}
void Rectangle::setPoints(Point pa, Point pb)
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
	// Uses the "Separating Axis Theorem" method
	return !(b.x < r.a.x || a.x > r.b.x || b.y < r.a.y || a.y > r.b.y);

	//// Method 2 (mine)
	// if any of its Points are inside then true
	//return (contains(r.a) || contains(r.b) || contains(Point(r.a.x, r.b.y)) || contains(Point(r.b.x, r.a.y)));
}
void Rectangle::draw(Core::Graphics& g)
{
	g.DrawLine(a.x, a.y, b.x, a.y);
	g.DrawLine(b.x, a.y, b.x, b.y);
	g.DrawLine(b.x, b.y, a.x, b.y);
	g.DrawLine(a.x, b.y, a.x, a.y);
}