#include <iostream>

#include "physicsEngine.h"
#include "boundingSphere.h"

void PhysicsEngine::AddObject(const PhysicsObject& object)
{
	m_objects.push_back(object);
}

void PhysicsEngine::Simulate(float delta)
{
	for (unsigned int i = 0; i < m_objects.size(); i++)
	{
		m_objects[i].Integrate(delta);
	}
}

void PhysicsEngine::HandleCollisions()
{
	for (unsigned int i = 0; i < m_objects.size(); i++)
	{
		for (unsigned int j = i + 1; j < m_objects.size(); j++)
		{
			IntersectData intersectData = m_objects[i].GetCollider().Intersect(m_objects[j].GetCollider());

			if (intersectData.GetDoesIntersect())
			{
				Vector3f direction = intersectData.GetDirection().Normalized();
				Vector3f otherDirection = Vector3f(direction.Reflect(m_objects[i].GetVelocity().Normalized()));

				m_objects[i].SetVelocity(
					Vector3f(m_objects[i].GetVelocity().Reflect(otherDirection)));
				m_objects[j].SetVelocity(
					Vector3f(m_objects[j].GetVelocity().Reflect(direction)));
			}
		}
	}
}

const PhysicsObject& PhysicsEngine::GetObject(const std::string& name) const
{
	for (int i = 0; i < m_objects.size(); i++)
	{
		if (m_objects[i].GetName().compare(name) == 0)
		{
			std::cout << "Match found for " << m_objects[i].GetName() << std::endl;
			return m_objects[i];
		}
	}

	std::cout << "No match found" << std::endl;

	return PhysicsObject(new BoundingSphere(Vector3f(0, 0, 0), 0), Vector3f(0, 0, 0), "NULL");
}