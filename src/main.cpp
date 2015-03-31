#include "3DEngine.h"
#include "testing.h"

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
	Entity* mainLight = new Entity(Vector3f(0, 4, 0), Quaternion(Vector3f(1, 0, 0), ToRadians(270)), 1.0f);
	Entity* pointLight = new Entity(Vector3f(-1, 1.5, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1.0f);

	mainLight->AddModifier(new DirectionalLight(Vector3f(1, 1, 1), 0.4f, 10, 80.0f, 1.0f));
	pointLight->AddModifier(new PointLight(Vector3f(0, 0, 1), 0.2f, Attenuation(0, 0, 1)));
	pointLight->AddModifier(new RepetitiveLinearMotionModifier(Vector3f(1, 0, 0), 0.015f, 1.0f));

	//AddToScene(mainLight);
	AddToScene(pointLight);

	//Camera
	Entity* mainCamera = new Entity(Vector3f(0, 1, 0), Quaternion(Vector3f(0, 0, 0), 1), 1.0f);

	mainCamera->AddModifier(new CameraComponent(Matrix4f().InitPerspective(ToRadians(70.0f), window.GetAspect(), 0.1f, 1000.0f)));
	mainCamera->AddModifier(new FreeLook(window.GetCenter(), 0.15f));
	mainCamera->AddModifier(new FreeMove(5.0f));

	AddToScene(mainCamera);

	//Environment
	Entity* floorPlane = new Entity(Vector3f(0, 0, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 1.0f);
	Entity* ceilingPlane = new Entity(Vector3f(0, 1, 0), Quaternion(Vector3f(0, 0, 0), ToRadians(0)), 0.3f);

	floorPlane->AddModifier(new MeshRenderer(Mesh("plane.obj"), Material("bricks")));
	ceilingPlane->AddModifier(new MeshRenderer(Mesh("cube.obj"), Material("bricks2")));
	//ceilingPlane->AddModifier(new RepetitiveLinearMotionModifier(Vector3f(0, 1, 0), 0.01f, 2.0f));
	//ceilingPlane->AddModifier(new RepetitiveRotationalMotionModifier(Vector3f(0, 1, 0), 0.02f, 1.0f, false));

	AddToScene(floorPlane);
	AddToScene(ceilingPlane);
}

int main()
{
	Testing::RunAllTests();

	TestGame game;
	Window window(800, 600, "3d game engine");
	RenderingEngine renderer(window);
	
	CoreEngine engine(60, &window, &renderer, &game);
	engine.Start();
	
	return 0;
}