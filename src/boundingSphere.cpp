#include "boundingSphere.h"

IntersectData BoundingSphere::IntersectBoundingSphere(const BoundingSphere& other)
{
	float radiusDistance = m_radius + other.m_radius;
	float centerDistance = (other.m_center - m_center).Length();

	return IntersectData(centerDistance < radiusDistance, centerDistance - radiusDistance);
}