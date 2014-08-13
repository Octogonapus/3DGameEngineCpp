#ifndef PHYSICSENGINECOMPONENT_H_INCLUDED
#define PHYSICSENGINECOMPONENT_H_INCLUDED

#include "entityComponent.h"
#include "physicsEngine.h"

//Temporary
class PhysicsEngineComponent : public EntityComponent
{
public:
	PhysicsEngineComponent(const PhysicsEngine& engine) :
		m_physicsEngine(engine) {}

	virtual void Update(float delta);

	inline const PhysicsEngine& GetPhysicsEngine() { return m_physicsEngine; }
protected:
private:
	PhysicsEngine m_physicsEngine;
};

#endif