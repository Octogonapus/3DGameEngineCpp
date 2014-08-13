#ifndef PHYSICSOBJECT_H_INCLUDED
#define PHYSICSOBJECT_H_INCLUDED

#include "math3d.h"

class PhysicsObject
{
public:
	PhysicsObject(const Vector3f& position, const Vector3f& velocity) :
		m_position(position),
		m_velocity(velocity) {}

	void Integrate(float delta);

	inline const Vector3f& GetPosition() const { return m_position; }
	inline const Vector3f& GetVelocity() const { return m_velocity; }

	static void Test();
protected:
private:
	Vector3f m_position;
	Vector3f m_velocity;
};

#endif