#ifndef REPETITIVELINEARMOTIONMODIFIER_H_INCLUDED
#define REPETITIVELINEARMOTIONMODIFIER_H_INCLUDED

#include "modifier.h"

class RepetitiveLinearMotionModifier : public Modifier
{
public:
	RepetitiveLinearMotionModifier(const Vector3f& axis, float amplitude, float moveSpeed) :
		m_axis(axis),
		m_amplitude(amplitude),
		m_moveSpeed(moveSpeed) {}

	virtual void Update(float delta);
protected:
private:
	Vector3f m_axis;
	float    m_amplitude;
	float    m_moveSpeed;
	float    m_totalMoved = 0;
};

#endif