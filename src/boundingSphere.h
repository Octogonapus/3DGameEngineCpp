#ifndef BOUNDINGSPHERE_H_INCLUDED
#define BOUNDINGSPHERE_H_INCLUDED

#include "math3d.h"
#include "intersectData.h"
#include "collider.h"

class BoundingSphere : public Collider
{
public:
	BoundingSphere(const Vector3f& center, float radius) :
		Collider(Collider::TYPE_SPHERE),
		m_center(center),
		m_radius(radius) {}

	IntersectData IntersectBoundingSphere(const BoundingSphere& other);
	virtual void Transform(const Vector3f& translation);

	virtual Vector3f GetCenter() const { return m_center; }
	inline float GetRadius() const { return m_radius; }

	static void Test();
protected:
private:
	Vector3f m_center;
	float m_radius;
};

#endif