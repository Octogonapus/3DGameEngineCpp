#ifndef PHYSICSENGINE_H_INCLUDED
#define PHYSICSENGINE_H_INCLUDED

#include <vector>
#include <string>

#include "physicsObject.h"

class PhysicsEngine
{
public:
	PhysicsEngine() {}

	void AddObject(const PhysicsObject& object);
	void Simulate(float delta);
	void HandleCollisions();

	inline const PhysicsObject& GetObject(unsigned int index) const { return m_objects[index]; }
	const PhysicsObject& GetObject(const std::string& name) const;
	inline unsigned int GetNumObjects() const { return (unsigned int) m_objects.size(); }
protected:
private:
	std::vector<PhysicsObject> m_objects;
};

#endif