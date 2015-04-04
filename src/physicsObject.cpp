#include "physicsObject.h"

void PhysicsObject::Simulate(float delta)
{
	m_entity->GetTransform()->SetPos(*m_entity->GetTransform()->GetPos() + (m_velocity + (m_accel / 2) * delta) * delta);
	//m_entity->GetTransform()->SetPos(*m_entity->GetTransform()->GetPos() + m_velocity * delta);
	m_velocity += m_accel * delta;
}