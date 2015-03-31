#ifndef REPETITIVEROTATIONALMOTIONMODIFIER_H_INCLUDED
#define REPETITIVEROTATIONALMOTIONMODIFIER_H_INCLUDED

#include "modifier.h"

class RepetitiveRotationalMotionModifier : public Modifier
{
public:
	RepetitiveRotationalMotionModifier(const Vector3f& axis, float amplitude, float moveSpeed, bool shouldOscillate = false) :
		m_axis(axis),
		m_amplitude(amplitude),
		m_moveSpeed(moveSpeed),
		m_shouldOscillate(shouldOscillate) {}

	virtual void Update(float delta);
protected:
private:
	Vector3f m_axis;
	float    m_amplitude;
	float    m_moveSpeed;
	float    m_totalMoved = 0;
	bool     m_shouldOscillate;
};

#endif