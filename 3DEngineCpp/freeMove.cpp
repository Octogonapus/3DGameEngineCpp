#include "freeMove.h"

FreeMove::FreeMove(float speed, int forwardKey, int backKey, int leftKey, int rightKey, int upKey, int downKey) :
	m_speed(speed),
	m_forwardKey(forwardKey),
	m_backKey(backKey),
	m_leftKey(leftKey),
	m_rightKey(rightKey),
	m_upKey(upKey),
	m_downKey(downKey) {}
	
void FreeMove::Input(float delta)
{
	float movAmt = m_speed * delta;

	if (Input::GetKey(m_forwardKey))
		 Move(GetTransform().GetRot().GetForward(), movAmt);
	if (Input::GetKey(m_backKey))
		 Move(GetTransform().GetRot().GetBack(), movAmt);
	if (Input::GetKey(m_leftKey))
		 Move(GetTransform().GetRot().GetLeft(), movAmt);
	if (Input::GetKey(m_rightKey))
		 Move(GetTransform().GetRot().GetRight(), movAmt);
	if (Input::GetKey(m_upKey))
		Move(Vector3f(0, 1, 0), movAmt);
	if (Input::GetKey(m_downKey))
		Move(Vector3f(0, 1, 0), -movAmt);
}

void FreeMove::Move(const Vector3f& direction, float amt)
{
	GetTransform().SetPos(GetTransform().GetPos() + (direction * amt));
}
