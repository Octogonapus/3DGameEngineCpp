#ifndef PHYSICSOBJECT_H_INCLUDED
#define PHYSICSOBJECT_H_INCLUDED

#include <string>

#include "math3d.h"
#include "boundingSphere.h"

class PhysicsObject
{
public:
	PhysicsObject(Collider* collider, const Vector3f& velocity, const std::string name) :
		m_position(collider->GetCenter()),
		m_oldPosition(collider->GetCenter()),
		m_velocity(velocity),
		m_collider(collider),
		m_name(name) {}

	PhysicsObject(const PhysicsObject& other);
	PhysicsObject operator=(PhysicsObject other);
	virtual ~PhysicsObject();

	void Integrate(float delta);

	inline const Vector3f& GetPosition() const { return m_position; }
	inline const Vector3f& GetVelocity() const { return m_velocity; }
	inline const std::string& GetName() const { return m_name; }

	inline const Collider& GetCollider()
	{
		Vector3f translation = m_position - m_oldPosition;
		m_oldPosition = m_position;
		m_collider->Transform(translation);
		return *m_collider;
	}

	inline void SetVelocity(const Vector3f& velocity) { m_velocity = velocity; }

	static void Test();
protected:
private:
	Vector3f    m_position;
	Vector3f    m_oldPosition;
	Vector3f    m_velocity;

	Collider*   m_collider;

	std::string m_name;
};

#endif