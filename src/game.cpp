#include "game.h"
#include "renderingEngine.h"
#include <iostream>

void Game::ProcessInput(const Input& input, float delta)
{
	m_inputTimer.StartInvocation();
	m_root.ProcessInputAll(input, delta);
	m_inputTimer.StopInvocation();
}

void Game::Update(float delta)
{
	m_updateTimer.StartInvocation();
	m_root.UpdateAll(delta);
	//TODO: Simulate all physics objects in the physics engine
	//TODO: Handle collisions for all physics objects in the physics engine
	m_updateTimer.StopInvocation();
}

void Game::Render(RenderingEngine* renderingEngine)
{
	renderingEngine->Render(m_root);
}
