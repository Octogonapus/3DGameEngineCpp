#include "repetitiveLinearMotionModifier.h"

void RepetitiveLinearMotionModifier::Update(float delta)
{
	m_totalMoved += m_moveSpeed * delta;

	GetTransform()->SetPos(*GetTransform()->GetPos() + (m_axis * (m_amplitude * sin(m_totalMoved))));
}