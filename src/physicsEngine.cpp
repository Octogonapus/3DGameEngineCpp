#include "physicsEngine.h"
#include "boundingSphere.h"

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

void PhysicsEngine::HandleCollisions()
{
	//For each object, handle a collision with each other object
	for (int i = 0; i < m_objects.size(); i++)
	{
		for (int j = i + 1; j < m_objects.size(); j++)
		{
			IntersectData data = m_objects[i].GetCollider()->HandleIntersection(*m_objects[j].GetCollider());

			if (data.GetDoesIntersect())
			{
				//For now, just swap the velocities
				Vector3f temp = m_objects[i].GetVelocity();
				m_objects[i].SetVelocity(m_objects[j].GetVelocity());
				m_objects[j].SetVelocity(temp);
			}
		}
	}
}