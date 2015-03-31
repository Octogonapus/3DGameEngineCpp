#include "physicsEngineModifier.h"

void PhysicsEngineModifier::Update(float delta)
{
	m_physicsEngine.Simulate(delta);
	m_physicsEngine.HandleCollisions();
}