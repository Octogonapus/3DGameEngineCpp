#ifndef ENTITYOBJECT_H_INCLUDED
#define ENTITYOBJECT_H_INCLUDED

#include <vector>
#include "transform.h"
#include "input.h"
class Camera;
class CoreEngine;
class Modifier;
class Shader;
class RenderingEngine;

class Entity
{
public:
	Entity(const Vector3f& pos = Vector3f(0,0,0), const Quaternion& rot = Quaternion(0,0,0,1), float scale = 1.0f) : 
		m_transform(pos, rot, scale),
		m_coreEngine(0) {}
		
	virtual ~Entity();
	
	Entity* AddChild(Entity* child);
	Entity* AddModifier(Modifier* component);
	
	void ProcessInputAll(const Input& input, float delta);
	void UpdateAll(float delta);
	void RenderAll(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const;
	
	std::vector<Entity*> GetAllAttached();
	
	inline Transform* GetTransform() { return &m_transform; }
	void SetEngine(CoreEngine* engine);
protected:
private:
	std::vector<Entity*>          m_children;
	std::vector<Modifier*>        m_modifiers;
	Transform                     m_transform;
	CoreEngine*                   m_coreEngine;

	void ProcessInput(const Input& input, float delta);
	void Update(float delta);
	void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const;
	
	Entity(const Entity& other) {}
	void operator=(const Entity& other) {}
};

#endif
