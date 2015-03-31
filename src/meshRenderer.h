#ifndef MESHRENDERER_H_INCLUDED
#define MESHRENDERER_H_INCLUDED

#include "modifier.h"
#include "mesh.h"

class MeshRenderer : public Modifier
{
public:
	MeshRenderer(const Mesh& mesh, const Material& material) :
		m_mesh(mesh),
		m_material(material) {}

	virtual void Render(const Shader& shader, const RenderingEngine& renderingEngine, const Camera& camera) const
	{
		shader.Bind();
		shader.UpdateUniforms(GetTransform(), m_material, renderingEngine, camera);
		m_mesh.Draw();
	}
protected:
private:
	Mesh m_mesh;
	Material m_material;
};

#endif
