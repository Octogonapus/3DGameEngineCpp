#ifndef AABB_H_INCLUDED
#define AABB_H_INCLUDED

#include "math3d.h"
#include "intersectData.h"

class AABB
{
public:
	AABB(const Vector3f& minExtents, const Vector3f& maxExtents) :
		m_minExtents(minExtents),
		m_maxExtents(maxExtents) {}

	IntersectData IntersectAABB(const AABB& other);

	inline const Vector3f& GetMinExtents() const { return m_minExtents; }
	inline const Vector3f& GetMaxExtents() const { return m_maxExtents; }
protected:
private:
	const Vector3f m_minExtents;
	const Vector3f m_maxExtents;
};

#endif