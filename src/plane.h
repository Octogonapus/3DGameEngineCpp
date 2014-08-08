#ifndef PLANE_H_INCLUDED
#define PLANE_H_INCLUDED

#include "math3d.h"
#include "boundingSphere.h"
#include "intersectData.h"

class Plane
{
public:
	Plane(const Vector3f& normal, float distance) :
		m_normal(normal),
		m_distance(distance) {}

	Plane Normalized() const;
	IntersectData IntersectSphere(const BoundingSphere& other) const;

	inline const Vector3f& GetNormal() const { return m_normal; }
	inline float GetDistance() const { return m_distance; }
protected:
private:
	const Vector3f m_normal;
	const float m_distance;
};

#endif