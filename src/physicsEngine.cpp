#include <algorithm>

#include "physicsEngine.h"

PhysicsEngine& PhysicsEngine::operator=(const PhysicsEngine& x)
{
	m_objects = x.m_objects;
	return *this;
}

void PhysicsEngine::AddObject(const PhysicsObject& object)
{
	m_objects.push_back(object);
}

void PhysicsEngine::SimulateAll(float delta)
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].Simulate(delta);
	}
}