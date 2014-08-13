#ifndef PHYSICSOBJCETCOMPONENT_H_INCLUDED
#define PHYSICSOBJCETCOMPONENT_H_INCLUDED

#include "entityComponent.h"
#include "physicsEngine.h"

class PhysicsObjectComponent : public EntityComponent
{
public:
	PhysicsObjectComponent(const PhysicsObject* object) :
		m_physicsObject(object) {}

	virtual void Update(float delta);
protected:
private:
	const PhysicsObject* m_physicsObject;
};

#endif