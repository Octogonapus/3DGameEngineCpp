#include "physicsObjectModifier.h"

void PhysicsObjectModifier::Update(float delta)
{
	GetTransform()->SetPos(m_physicsObject->GetPosition());
}