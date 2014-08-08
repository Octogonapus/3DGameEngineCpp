#include "aabb.h"

IntersectData AABB::IntersectAABB(const AABB& other)
{
	Vector3f distance1 = other.m_minExtents - m_maxExtents;
	Vector3f distance2 = m_minExtents - other.m_maxExtents;
	Vector3f distances = Vector3f(distance1.Max(distance2));

	float maxDistance = distances.Max();

	return IntersectData(maxDistance < 0, maxDistance);
}