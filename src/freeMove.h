#ifndef FREEMOVE_H
#define FREEMOVE_H

#include "math3d.h"
#include "entityComponent.h"

class FreeMove : public EntityComponent
{
public:
	FreeMove(float speed = 10.0f, int forwardKey = Input::KEY_W, int backKey = Input::KEY_S, int leftKey = Input::KEY_A, int rightKey = Input::KEY_D, int upKey = Input::KEY_Z, int downKey = Input::KEY_X)  :
		m_speed(speed),
		m_forwardKey(forwardKey),
		m_backKey(backKey),
		m_leftKey(leftKey),
		m_rightKey(rightKey),
		m_upKey(upKey),
		m_downKey(downKey) {}
	
	virtual void ProcessInput(const Input& input, float delta);
protected:
private:
	void Move(const Vector3f& direction, float amt);

	float m_speed;
	int m_forwardKey;
	int m_backKey;
	int m_leftKey;
	int m_rightKey;
	int m_upKey;
	int m_downKey;
};

#endif
