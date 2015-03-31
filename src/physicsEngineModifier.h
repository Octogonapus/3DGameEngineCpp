#ifndef PHYSICSENGINEMODIFIER_H_INCLUDED
#define PHYSICSENGINEMODIFIER_H_INCLUDED

#include "modifier.h"
#include "physicsEngine.h"

//Temporary
class PhysicsEngineModifier : public Modifier
{
public:
	PhysicsEngineModifier(const PhysicsEngine& engine) :
		m_physicsEngine(engine) {}

	virtual void Update(float delta);

	inline const PhysicsEngine& GetPhysicsEngine() { return m_physicsEngine; }
protected:
private:
	PhysicsEngine m_physicsEngine;
};

#endif