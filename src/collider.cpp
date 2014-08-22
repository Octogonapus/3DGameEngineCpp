#include "collider.h"
#include "boundingSphere.h"
#include <iostream>
#include <cstdlib>

IntersectData Collider::Intersect(const Collider& other) const
{
	if (m_type == TYPE_SPHERE && other.GetType() == TYPE_SPHERE)
	{
		BoundingSphere *self = (BoundingSphere*) this;
		return self->IntersectBoundingSphere((BoundingSphere&) other);
	}

	std::cerr << "Error: Collision could not be calculated between colliders" << std::endl;
	exit(1);

	//Should never reach this point
	return IntersectData(false, 0);
}