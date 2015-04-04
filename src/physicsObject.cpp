#include "physicsObject.h"

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