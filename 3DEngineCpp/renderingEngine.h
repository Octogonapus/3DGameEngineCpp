#ifndef RENDERINGENGINE_H
#define RENDERINGENGINE_H

#include "camera.h"
#include "lighting.h"
#include "mappedValues.h"
#include "material.h"
#include <vector>
#include <map>
class GameObject;
class Mesh;

class RenderingEngine : public MappedValues
{
public:
	RenderingEngine();
	
	void Render(GameObject* object);
	
	inline Camera& GetMainCamera() { return *m_mainCamera; }
	inline BaseLight* GetActiveLight() { return m_activeLight; }
	
	inline void AddLight(BaseLight* light) { m_lights.push_back(light); }
	inline void AddCamera(Camera* camera) { m_mainCamera = camera; }
	
	inline unsigned int GetSamplerSlot(const std::string& samplerName) { return m_samplerMap[samplerName]; }
	inline Matrix4f GetLightMatrix() { return m_lightMatrix; }
	
	virtual void UpdateUniformStruct(const Transform& transform, const Material& material, Shader* shader, 
		const std::string& uniformName, const std::string& uniformType) 
	{
		throw uniformType + " is not supported by the rendering engine";
	}
	
	virtual ~RenderingEngine();
protected:
private:
	static const Matrix4f s_biasMatrix;

	RenderingEngine(const RenderingEngine& other) {}
	void operator=(const RenderingEngine& other) {}

	void BlurShadowMap(Texture* shadowMap, float blurAmt);
	void ApplyFilter(Shader* filter, Texture* source, Texture* dest);
	
	Camera* m_mainCamera;
	Camera* m_altCamera;
	GameObject* m_altCameraObject;
	
	Material* m_planeMaterial;
	Transform m_planeTransform;
	Mesh* m_plane;
	Texture* m_tempTarget;
	
	BaseLight* m_activeLight;
	Shader* m_defaultShader;
	Shader* m_shadowMapShader;
	Shader* m_nullFilter;
	Shader* m_gausBlurFilter;
	Matrix4f m_lightMatrix;

	std::vector<BaseLight*> m_lights;
	std::map<std::string, unsigned int> m_samplerMap;
};

#endif // RENDERINGENGINE_H
