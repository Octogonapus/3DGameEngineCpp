#ifndef INTERSECTDATA_H_INCLUDED
#define INTERSECTDATA_H_INCLUDED

class IntersectData
{
public:
	IntersectData(const bool doesIntersect, const float distance) :
		m_doesIntersect(doesIntersect),
		m_distance(distance) {}

	inline bool GetDoesIntersect() const { return m_doesIntersect; }
	inline float GetDistance() const { return m_distance; }
protected:
private:
	const bool m_doesIntersect;
	const float m_distance;
};

#endif