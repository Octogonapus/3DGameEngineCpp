#include "boundingSphere.h"

IntersectData BoundingSphere::IntersectWithBoundingSphere(const BoundingSphere& other)
{
	float radiusDistance = m_radius + other.m_radius;
	float centerDistance = (other.m_centerPosition - m_centerPosition).Length();

	return IntersectData(centerDistance < radiusDistance, centerDistance - radiusDistance);
}

void BoundingSphere::Translate(const Vector3f& translation)
{
	m_centerPosition += translation;
}