#ifndef COLLIDER_H_INCLUDED
#define COLLIDER_H_INCLUDED

#include "referenceCounter.h"
#include "intersectData.h"
#include "math3d.h"

class Collider : public ReferenceCounter
{
public:
	enum
	{
		TYPE_AABB,
		TYPE_SPHERE
	};

	Collider(int type) :
		ReferenceCounter(),
		m_type(type) {}

	//Handle the first applicable intersection; throw an error and terminate if no intersections are applicable
	IntersectData HandleIntersection(const Collider& other) const;

	inline int GetType() const { return m_type; }
	virtual Vector3f GetCenter() const = 0;
	virtual void SetCenter(const Vector3f& center) = 0;
protected:
private:
	int m_type;
};

#endif