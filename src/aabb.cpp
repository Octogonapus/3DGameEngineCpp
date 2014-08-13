#include "aabb.h"
#include <cassert>

IntersectData AABB::IntersectAABB(const AABB& other)
{
	Vector3f distance1 = other.m_minExtents - m_maxExtents;
	Vector3f distance2 = m_minExtents - other.m_maxExtents;
	Vector3f distances = Vector3f(distance1.Max(distance2));

	float maxDistance = distances.Max();

	return IntersectData(maxDistance < 0, maxDistance);
}

void AABB::Test()
{
	AABB aabb1(Vector3f(0.0f, 0.0f, 0.0f), Vector3f(1.0f, 1.0f, 1.0f));
	AABB aabb2(Vector3f(1.0f, 1.0f, 1.0f), Vector3f(2.0f, 2.0f, 2.0f));
	AABB aabb3(Vector3f(1.0f, 0.0f, 0.0f), Vector3f(2.0f, 1.0f, 1.0f));
	AABB aabb4(Vector3f(0.0f, 0.0f, -2.0f), Vector3f(1.0f, 1.0f, -1.0f));
	AABB aabb5(Vector3f(0.0f, 0.5f, 0.0f), Vector3f(1.0f, 1.5f, 1.0f));

	IntersectData aabb1Intersectaabb2 = aabb1.IntersectAABB(aabb2);
	IntersectData aabb1Intersectaabb3 = aabb1.IntersectAABB(aabb3);
	IntersectData aabb1Intersectaabb4 = aabb1.IntersectAABB(aabb4);
	IntersectData aabb1Intersectaabb5 = aabb1.IntersectAABB(aabb5);

	assert(aabb1Intersectaabb2.GetDoesIntersect() == false);
	assert(aabb1Intersectaabb2.GetDistance() == 0.0f);

	assert(aabb1Intersectaabb3.GetDoesIntersect() == false);
	assert(aabb1Intersectaabb3.GetDistance() == 0.0f);

	assert(aabb1Intersectaabb4.GetDoesIntersect() == false);
	assert(aabb1Intersectaabb4.GetDistance() == 1.0f);

	assert(aabb1Intersectaabb5.GetDoesIntersect() == true);
	assert(aabb1Intersectaabb5.GetDistance() == -0.5f);
}