#ifndef MODIFIER_H_INCLUDED
#define MODIFIER_H_INCLUDED

#include "transform.h"
#include "entity.h"
#include "input.h"
class RenderingEngine;
class Shader;

class Modifier
{
public:
	Modifier() :
		m_parent(0) {}
	virtual ~Modifier() {}

	virtual void ProcessInput(const Input& input, float delta) {}
	virtual void Update(float delta) {}
	virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const {}
	
	virtual void AddToEngine(CoreEngine* engine) const { }
	
	inline Transform* GetTransform()             { return m_parent->GetTransform(); }
	inline const Transform& GetTransform() const { return *m_parent->GetTransform(); }
	
	virtual void SetParent(Entity* parent) { m_parent = parent; }
private:
	Entity* m_parent;
	
	Modifier(const Modifier& other) {}
	void operator=(const Modifier& other) {}
};

#endif
