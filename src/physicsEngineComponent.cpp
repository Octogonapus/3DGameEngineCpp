#include "physicsEngineComponent.h"

void PhysicsEngineComponent::Update(float delta)
{
	m_physicsEngine.Simulate(delta);
}