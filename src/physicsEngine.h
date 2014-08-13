#ifndef PHYSICSENGINE_H_INCLUDED
#define PHYSICSENGINE_H_INCLUDED

#include "physicsObject.h"
#include <vector>

class PhysicsEngine
{
public:
	PhysicsEngine() {}

	void AddObject(const PhysicsObject& object);
	void Simulate(float delta);

	//Temporary accessors
	inline const PhysicsObject& GetObject(unsigned int index) const { return m_objects[index]; }
	inline unsigned int GetNumObjects() const { return (unsigned int) m_objects.size(); }
protected:
private:
	std::vector<PhysicsObject> m_objects;
};

#endif