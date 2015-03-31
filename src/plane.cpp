#include "plane.h"
#include <cassert>

Plane Plane::Normalized() const
{
	float magnitude = m_normal.Length();
	return Plane(m_normal / magnitude, m_distance / magnitude);
}

IntersectData Plane::IntersectSphere(const BoundingSphere& other) const
{
	float distanceFromSphereCenter = fabs(m_normal.Dot(other.GetCenter()) + m_distance);
	float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();
	return IntersectData(distanceFromSphere < 0, m_normal * distanceFromSphere);
}

void Plane::Test()
{
	BoundingSphere sphere1(Vector3f(0.0f, 0.0f, 0.0f), 1.0f);
	BoundingSphere sphere2(Vector3f(0.0f, 3.0f, 0.0f), 1.0f);
	BoundingSphere sphere3(Vector3f(0.0f, 0.0f, 2.0f), 1.0f);
	BoundingSphere sphere4(Vector3f(1.0f, 0.0f, 0.0f), 1.0f);

	Plane plane1(Vector3f(0.0f, 1.0f, 0.0f), 0.0f);
	
	IntersectData plane1IntersectSphere1 = plane1.IntersectSphere(sphere1);
	IntersectData plane1IntersectSphere2 = plane1.IntersectSphere(sphere2);
	IntersectData plane1IntersectSphere3 = plane1.IntersectSphere(sphere3);
	IntersectData plane1IntersectSphere4 = plane1.IntersectSphere(sphere4);

	assert(plane1IntersectSphere1.GetDoesIntersect() == true);
	assert(plane1IntersectSphere1.GetDistance() == 1.0f);

	assert(plane1IntersectSphere2.GetDoesIntersect() == false);
	assert(plane1IntersectSphere2.GetDistance() == 2.0f);

	assert(plane1IntersectSphere3.GetDoesIntersect() == true);
	assert(plane1IntersectSphere3.GetDistance() == 1.0f);

	assert(plane1IntersectSphere4.GetDoesIntersect() == true);
	assert(plane1IntersectSphere4.GetDistance() == 1.0f);

	//std::cout << "Plane1 intersect Sphere1: " << plane1IntersectSphere1.GetDoesIntersect() 
	//          << ", Distance: "               << plane1IntersectSphere1.GetDistance() << std::endl;
	//
	//std::cout << "Plane1 intersect Sphere2: " << plane1IntersectSphere2.GetDoesIntersect() 
	//          << ", Distance: "               << plane1IntersectSphere2.GetDistance() << std::endl;
	//
	//std::cout << "Plane1 intersect Sphere3: " << plane1IntersectSphere3.GetDoesIntersect() 
	//          << ", Distance: "               << plane1IntersectSphere3.GetDistance() << std::endl;
	//
	//std::cout << "Plane1 intersect Sphere4: " << plane1IntersectSphere4.GetDoesIntersect() 
	//          << ", Distance: "               << plane1IntersectSphere4.GetDistance() << std::endl;
}