#include "plane.h"

Plane Plane::Normalized() const
{
	float magnitude = m_normal.Length();
	return Plane(m_normal / magnitude, m_distance / magnitude);
}

IntersectData Plane::IntersectSphere(const BoundingSphere& other) const
{
	float distanceFromSphereCenter = fabs(m_normal.Dot(other.GetCenter()) + m_distance);
	float distanceFromSphere = distanceFromSphereCenter - other.GetRadius();
	return IntersectData(distanceFromSphere < 0, distanceFromSphere);
}