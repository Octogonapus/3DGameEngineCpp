#include "Testing.h"

#include "boundingSphere.h"
#include "aabb.h"
#include "plane.h"
#include "physicsObject.h"

#include <iostream>
#include <cassert>

void Testing::RunAllTests()
{
	BoundingSphere::Test();
	AABB::Test();
	Plane::Test();
	PhysicsObject::Test();
}