#ifndef BOUNDINGSPHERE_H_INCLUDED
#define BOUNDINGSPHERE_H_INCLUDED

#include "collider.h"
#include "math3d.h"
#include "intersectData.h"

class BoundingSphere : public Collider
{
public:
	BoundingSphere(const Vector3f& centerPosition, const float radius) :
		Collider(Collider::TYPE_SPHERE),
		m_centerPosition(centerPosition),
		m_radius(radius) {}

	IntersectData IntersectWithBoundingSphere(const BoundingSphere& other);
	virtual void Translate(const Vector3f& translation);

	Vector3f GetCenter() const { return m_centerPosition; }
	void SetCenter(const Vector3f& center) { m_centerPosition = center; }
	inline float GetRadius() const { return m_radius; }
protected:
private:
	Vector3f m_centerPosition;
	float    m_radius;
};

#endif