#ifndef PHYSICSENGINE_H_INCLUDED
#define PHYSICSENGINE_H_INCLUDED

#include <vector>

#include "physicsObject.h"

class PhysicsEngine
{
public:
	PhysicsEngine& operator=(const PhysicsEngine& x);

	void AddObject(const PhysicsObject& object);
	void SimulateAll(float delta);
	void HandleCollisions();
protected:
private:
	std::vector<PhysicsObject> m_objects;
};

#endif