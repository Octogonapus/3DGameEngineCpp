#ifndef FREELOOK_H_INCLUDED
#define FREELOOK_H_INCLUDED

#include "math3d.h"
#include "modifier.h"

class FreeLook : public Modifier
{
public:
	FreeLook(const Vector2f& windowCenter, float sensitivity = 0.5f, int unlockMouseKey = Input::KEY_ESCAPE) :
		m_sensitivity(sensitivity),
		m_unlockMouseKey(unlockMouseKey),
		m_mouseLocked(false),
		m_windowCenter(windowCenter) {}
	
	virtual void ProcessInput(const Input& input, float delta);
protected:
private:
	float    m_sensitivity;
	int      m_unlockMouseKey;
	bool     m_mouseLocked;
	Vector2f m_windowCenter;
};

#endif
