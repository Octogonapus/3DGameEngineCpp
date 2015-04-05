#ifndef PHYSICSOBJECT_H_INCLUDED
#define PHYSICSOBJECT_H_INCLUDED

#include "math3d.h"
#include "entity.h"
#include "collider.h"

class PhysicsObject
{
public:
	PhysicsObject(Entity* entity, Collider* collider, const Vector3f& velocity, const Vector3f& accel, const bool hasGravity) :
		m_entity(entity),
		m_velocity(velocity),
		m_accel(accel),
		m_collider(collider),
		m_hasGravity(hasGravity) {}

	PhysicsObject(const PhysicsObject& other);
	PhysicsObject& operator=(PhysicsObject other);

	//Simulate forces to update position and velocity
	void Simulate(float delta);

	inline void SetVelocity(const Vector3f& velocity) { m_velocity = velocity; }
	inline const Vector3f& GetVelocity() const { return m_velocity; }
	inline Entity* GetEntity() const { return m_entity; }

	inline Collider* GetCollider()
	{
		m_collider->SetCenter(*m_entity->GetTransform()->GetPos());
		return m_collider;
	}
protected:
private:
	Entity*  m_entity;
	Collider* m_collider;
	Vector3f m_velocity;
	Vector3f m_accel;
	bool     m_hasGravity;
	const Vector3f m_gravity = Vector3f(0, -0.2f, 0);
};

#endif