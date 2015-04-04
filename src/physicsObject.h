#ifndef PHYSICSOBJECT_H_INCLUDED
#define PHYSICSOBJECT_H_INCLUDED

#include "collider.h"
#include "math3d.h"
#include "entity.h"

class PhysicsObject
{
public:
	PhysicsObject(Entity* entity, const Collider& collider, const Vector3f& velocity, const Vector3f& accel, const bool hasGravity) :
		m_entity(entity),
		m_collider(collider),
		m_velocity(velocity),
		m_accel(accel),
		m_hasGravity(hasGravity) {}

	//Simulate forces to update position and velocity
	void Simulate(float delta);
	inline const Vector3f& GetVelocity() { return m_velocity; }
protected:
private:
	Entity*  m_entity;
	Collider m_collider;
	Vector3f m_velocity;
	Vector3f m_accel;
	bool     m_hasGravity;
	const Vector3f m_gravity = Vector3f(0, -1, 0);
};

#endif