#ifndef PHYSICSOBJCETMODIFIER_H_INCLUDED
#define PHYSICSOBJCETMODIFIER_H_INCLUDED

#include "modifier.h"
#include "physicsEngine.h"

class PhysicsObjectModifier : public Modifier
{
public:
	PhysicsObjectModifier(const PhysicsObject* object) :
		m_physicsObject(object) {}

	virtual void Update(float delta);
protected:
private:
	const PhysicsObject* m_physicsObject;
};

#endif