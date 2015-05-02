
#include "Physics.h"
using namespace Physics;

float Gravity::acceleration = 0.1f;

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
Vector& Vector::operator-()
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
void Rectangle::setPoints(Point& pa, Point& pb)
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
void Rectangle::operator+=(const Vector& shift)
{
	a += shift;
	b += shift;
}