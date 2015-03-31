#include "repetitiveRotationalMotionModifier.h"

void RepetitiveRotationalMotionModifier::Update(float delta)
{
	m_totalMoved += m_moveSpeed * delta;

	if (m_shouldOscillate)
	{
		//TODO: Fix rotation, weird scaling issue probably to do with w component of quaternion
		Quaternion tempRot = GetTransform()->GetRot()->Normalized();

		tempRot.SetX(tempRot.GetX() + (m_axis.GetX() * sin(m_totalMoved)));
		tempRot.SetY(tempRot.GetY() + (m_axis.GetY() * sin(m_totalMoved)));
		tempRot.SetZ(tempRot.GetZ() + (m_axis.GetZ() * sin(m_totalMoved)));

		GetTransform()->SetRot(tempRot);
	}
	else
	{
		Quaternion newRot = Quaternion(m_axis, m_totalMoved + 90);
		GetTransform()->SetRot(GetTransform()->GetRot()->SLerp(newRot, m_moveSpeed * delta, true));
	}
}