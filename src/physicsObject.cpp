#include "physicsObject.h"

PhysicsObject::PhysicsObject(const PhysicsObject& other) :
	m_entity(other.m_entity),
	m_collider(other.m_collider),
	m_velocity(other.m_velocity),
	m_accel(other.m_accel),
	m_hasGravity(other.m_hasGravity) { m_collider->AddReference(); }

PhysicsObject& PhysicsObject::operator=(PhysicsObject other)
{
	char* temp[sizeof(PhysicsObject) / sizeof(char)];
	memcpy(temp, this, sizeof(PhysicsObject));
	memcpy(this, &other, sizeof(PhysicsObject));
	memcpy(&other, temp, sizeof(PhysicsObject));
	return *this;
}

void PhysicsObject::Simulate(float delta)
{
	if (m_hasGravity)
	{
		m_entity->GetTransform()->SetPos(*m_entity->GetTransform()->GetPos() + (m_velocity + (m_accel / 2) * delta) * delta);
		m_velocity += (m_accel * delta) + (m_gravity * delta);
	}
	else
	{
		m_entity->GetTransform()->SetPos(*m_entity->GetTransform()->GetPos() + (m_velocity + (m_accel / 2) * delta) * delta);
		m_velocity += m_accel * delta;
	}
}