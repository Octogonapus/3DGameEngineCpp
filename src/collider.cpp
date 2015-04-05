#include <iostream>

#include "collider.h"
#include "boundingSphere.h"

IntersectData Collider::HandleIntersection(const Collider& other) const
{
	if (m_type == TYPE_SPHERE && other.GetType() == TYPE_SPHERE)
	{
		return ((BoundingSphere*)this)->IntersectWithBoundingSphere((BoundingSphere&)other);
	}

	std::cerr << "Error: Intersection could not be handled between colliders of types " << std::to_string(m_type) << " and " << std::to_string(other.GetType()) << std::endl;
	exit(1);

	//To make the compiler happy; This should never execute
	return IntersectData(false, 0);
}