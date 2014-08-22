#ifndef COLLIDER_H_INCLUDED
#define COLLIDER_H_INCLUDED

#include "intersectData.h"
#include "math3d.h"
#include "referenceCounter.h"

class Collider : public ReferenceCounter
{
public:
	enum
	{
		TYPE_SPHERE,
		TYPE_AABB,
		TYPE_SIZE
	};

	Collider(int type) : 
		ReferenceCounter(),
		m_type(type) {}

	IntersectData Intersect(const Collider& other) const;
	virtual void Transform(const Vector3f& translation) {}

	inline int GetType() const { return m_type; }
	virtual Vector3f GetCenter() const { return Vector3f(0, 0, 0); }
protected:
private:
	int m_type;
};

#endif