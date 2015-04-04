#ifndef PHYSICSENGINE_H_INCLUDED
#define PHYSICSENGINE_H_INCLUDED

#include <vector>

#include "physicsObject.h"

class PhysicsEngine
{
public:
	PhysicsEngine& operator=(const PhysicsEngine& x);

	//Add an object to the engine
	void AddObject(const PhysicsObject& object);
	//Simulate all objects
	void SimulateAll(float delta);
	//Handle all collisions for all objects
	void HandleCollisions();
protected:
private:
	std::vector<PhysicsObject> m_objects;
};

#endif