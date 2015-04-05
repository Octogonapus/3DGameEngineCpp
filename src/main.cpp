#include "3DEngine.h"
#include "testing.h"

#include <string>
#include <iostream>

#include "freeLook.h"
#include "freeMove.h"
#include "repetitiveLinearMotionModifier.h"
#include "repetitiveRotationalMotionModifier.h"
#include "physicsEngine.h"
#include "physicsObject.h"
#include "boundingSphere.h"

class TestGame : public Game
{
public:
	TestGame() {}
	
	virtual void Init(const Window& window);
	void Update(float delta);
protected:
private:
	TestGame(const TestGame& other) {}
	void operator=(const TestGame& other) {}
};

void TestGame::Init(const Window& window)
{
	//Materials
	Material bricks("bricks", Texture("bricks.jpg"), 0.0f, 0, Texture("bricks_normal.jpg"), Texture("bricks_disp.png"), 0.03f, -0.5f);
	Material bricks2("bricks2", Texture("bricks2.jpg"), 0.0f, 0, Texture("bricks2_normal.png"), Texture("bricks2_disp.jpg"), 0.04f, -1.0f);

	//Standard square mesh (1x1)
	IndexedModel square;
	{
		square.AddVertex(1.0f, -1.0f, 0.0f);  square.AddTexCoord(Vector2f(1.0f, 1.0f));
		square.AddVertex(1.0f, 1.0f, 0.0f);   square.AddTexCoord(Vector2f(1.0f, 0.0f));
		square.AddVertex(-1.0f, -1.0f, 0.0f); square.AddTexCoord(Vector2f(0.0f, 1.0f));
		square.AddVertex(-1.0f, 1.0f, 0.0f);  square.AddTexCoord(Vector2f(0.0f, 0.0f));
		square.AddFace(0, 1, 2); square.AddFace(2, 1, 3);
	}
	Mesh customMesh("square", square.Finalize());

	//Light
	Entity* mainLight = new Entity(Vector3f(0, 4, 0), Quaternion(Vector3f(1, 0, 0), ToRadians(270)), 1);
	Entity* pointLight = new Entity(Vector3f(-1, 1.5, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);

	mainLight->AddModifier(new DirectionalLight(Vector3f(1, 1, 1), 0.4f, 10, 80, 1));
	pointLight->AddModifier(new PointLight(Vector3f(0, 0, 1), 0.4f, Attenuation(0, 0, 1)));
	pointLight->AddModifier(new RepetitiveLinearMotionModifier(Vector3f(1, 0, 0), 0.015f, 1));
	//pointLight->AddModifier(new FreeMove(5.0f));

	AddToScene(mainLight);
	//AddToScene(pointLight);

	//Camera
	Entity* mainCamera = new Entity(Vector3f(-10, 5, 5), Quaternion(Vector3f(0, 0, 0), 0), 1);

	mainCamera->AddModifier(new CameraComponent(Matrix4f().InitPerspective(ToRadians(70), window.GetAspect(), 0.1f, 1000)));
	mainCamera->AddModifier(new FreeLook(window.GetCenter(), 0.15f));
	mainCamera->AddModifier(new FreeMove(15));

	AddToScene(mainCamera);

	//Environment
	/*Entity* floorPlane = new Entity(Vector3f(0, 0, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* floatingCube = new Entity(Vector3f(0, 1, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 0.3f);

	floorPlane->AddModifier(new MeshRenderer(Mesh("plane.obj"), Material("bricks")));
	floatingCube->AddModifier(new MeshRenderer(Mesh("cube.obj"), Material("bricks2")));
	floatingCube->AddModifier(new RepetitiveLinearMotionModifier(Vector3f(0, 1, 0), 0.01f, 2));
	floatingCube->AddModifier(new RepetitiveRotationalMotionModifier(Vector3f(0, 1, 0), 0.02f, 1, false));

	AddToScene(floorPlane);
	AddToScene(floatingCube);*/

	Entity* sphere1 = new Entity(Vector3f(0, 0, -4), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* sphere2 = new Entity(Vector3f(0, 0, 1), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* sphere3 = new Entity(Vector3f(0, 0, 3), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* sphere4 = new Entity(Vector3f(0, 0, 5), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* sphere5 = new Entity(Vector3f(0, 0, 7), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);

	sphere1->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks")));
	sphere2->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks2")));
	sphere3->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks2")));
	sphere4->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks2")));
	sphere5->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks")));

	AddToScene(sphere1);
	AddToScene(sphere2);
	AddToScene(sphere3);
	AddToScene(sphere4);
	AddToScene(sphere5);

	//Physics
	PhysicsEngine physicsEngine = PhysicsEngine();

	PhysicsObject sphere1Rep = PhysicsObject(sphere1, new BoundingSphere(Vector3f(0, 0, -4), 1), Vector3f(0, 0, 1), Vector3f(0, 0, 0), false);
	PhysicsObject sphere2Rep = PhysicsObject(sphere2, new BoundingSphere(Vector3f(0, 0, 1), 1), Vector3f(0, 0, 0), Vector3f(0, 0, 0), false);
	PhysicsObject sphere3Rep = PhysicsObject(sphere3, new BoundingSphere(Vector3f(0, 0, 3), 1), Vector3f(0, 0, 0), Vector3f(0, 0, 0), false);
	PhysicsObject sphere4Rep = PhysicsObject(sphere4, new BoundingSphere(Vector3f(0, 0, 5), 1), Vector3f(0, 0, 0), Vector3f(0, 0, 0), false);
	PhysicsObject sphere5Rep = PhysicsObject(sphere5, new BoundingSphere(Vector3f(0, 0, 7), 1), Vector3f(0, 0, 0), Vector3f(0, 0, 0), false);

	physicsEngine.AddObject(sphere1Rep);
	physicsEngine.AddObject(sphere2Rep);
	physicsEngine.AddObject(sphere3Rep);
	physicsEngine.AddObject(sphere4Rep);
	physicsEngine.AddObject(sphere5Rep);

	SetPhysicsEngine(physicsEngine);
}

int main()
{
	Testing::RunAllTests();

	TestGame game;
	Window window(800, 600, "3D Game Engine");
	RenderingEngine renderer(window);
	
	CoreEngine engine(60, &window, &renderer, &game);
	engine.Start();
	
	return 0;
}