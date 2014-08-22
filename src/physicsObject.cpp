#include "physicsObject.h"
#include <cassert>
#include <cstring>

PhysicsObject::PhysicsObject(const PhysicsObject& other) :
	m_position(other.m_position),
	m_oldPosition(other.m_oldPosition),
	m_velocity(other.m_velocity),
	m_collider(other.m_collider) { m_collider->AddReference(); }

PhysicsObject PhysicsObject::operator=(PhysicsObject other)
{
	char* temp[sizeof(PhysicsObject) / sizeof(char)];
	memcpy(temp, this, sizeof(PhysicsObject));
	memcpy(this, &other, sizeof(PhysicsObject));
	memcpy(&other, temp, sizeof(PhysicsObject));
	return *this;
}

PhysicsObject::~PhysicsObject()
{
	if (m_collider->RemoveReference())
	{
		delete m_collider;
	}
}

void PhysicsObject::Integrate(float delta)
{
	m_position += m_velocity * delta;
}

void PhysicsObject::Test()
{
	PhysicsObject test(new BoundingSphere(Vector3f(0.0f, 1.0f, 0.0f), 1.0f), Vector3f(1.0f, 2.0f, 3.0f));
	
	test.Integrate(20.0f);

	Vector3f testPos = test.GetPosition();
	Vector3f testVel = test.GetVelocity();

	assert(testPos.GetX() == 20.0f);
	assert(testPos.GetY() == 41.0f);
	assert(testPos.GetZ() == 60.0f);

	assert(testVel.GetX() == 1.0f);
	assert(testVel.GetY() == 2.0f);
	assert(testVel.GetZ() == 3.0f);
}