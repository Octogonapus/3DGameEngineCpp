#include "3DEngine.h"
#include "testing.h"

#include <string>

#include "freeLook.h"
#include "freeMove.h"
#include "repetitiveLinearMotionModifier.h"
#include "repetitiveRotationalMotionModifier.h"
#include "physicsEngineModifier.h"
#include "physicsObjectModifier.h"
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
	Entity* mainCamera = new Entity(Vector3f(0, 1, 0), Quaternion(Vector3f(0, 0, 0), 1), 1);

	mainCamera->AddModifier(new CameraComponent(Matrix4f().InitPerspective(ToRadians(70), window.GetAspect(), 0.1f, 1000)));
	mainCamera->AddModifier(new FreeLook(window.GetCenter(), 0.15f));
	mainCamera->AddModifier(new FreeMove(5.0f));

	AddToScene(mainCamera);

	//Environment
	Entity* floorPlane = new Entity(Vector3f(0, 0, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1);
	Entity* floatingCube = new Entity(Vector3f(0, 1, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 0.3f);

	floorPlane->AddModifier(new MeshRenderer(Mesh("plane.obj"), Material("bricks")));
	floatingCube->AddModifier(new MeshRenderer(Mesh("cube.obj"), Material("bricks2")));
	floatingCube->AddModifier(new RepetitiveLinearMotionModifier(Vector3f(0, 1, 0), 0.01f, 2));
	floatingCube->AddModifier(new RepetitiveRotationalMotionModifier(Vector3f(0, 1, 0), 0.02f, 1, false));

	AddToScene(floorPlane);
	AddToScene(floatingCube);

	//Physics
	PhysicsEngine physicsEngine;
	
	PhysicsObject sphere1 = PhysicsObject(new BoundingSphere(Vector3f(0, 0, 0), 1), Vector3f(0, 0, 1), Vector3f(0, 0, 1), "sphere1");
	PhysicsObject sphere2 = PhysicsObject(new BoundingSphere(Vector3f(0, 0, 10), 1), Vector3f(0, 0, -1), Vector3f(0, 0, 0), "sphere2");

	physicsEngine.AddObject(sphere1);
	physicsEngine.AddObject(sphere2);

	PhysicsEngineModifier* physicsEngineModifier = new PhysicsEngineModifier(physicsEngine);
	Entity* physicsEngineEntity = new Entity();
	physicsEngineEntity->AddModifier(physicsEngineModifier);
	AddToScene(physicsEngineEntity);

	Entity* sphere1Entity = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	sphere1Entity->AddModifier(new PhysicsObjectModifier(&physicsEngineModifier->GetPhysicsEngine().GetObject("sphere1")));
	sphere1Entity->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks")));

	Entity* sphere2Entity = new Entity(Vector3f(0, 0, 0), Quaternion(), 1.0f);
	sphere2Entity->AddModifier(new PhysicsObjectModifier(&physicsEngineModifier->GetPhysicsEngine().GetObject("sphere2")));
	sphere2Entity->AddModifier(new MeshRenderer(Mesh("sphere.obj"), Material("bricks")));

	AddToScene(sphere1Entity);
	AddToScene(sphere2Entity);
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