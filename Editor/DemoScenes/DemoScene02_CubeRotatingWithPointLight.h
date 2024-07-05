#pragma once

#include "DemoScenes/IDemoScene.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"

#include <glm/glm.hpp>

namespace Pecan {

	/// Demo scene that renders a rotating cube with different colored faces
	/// lit by a point light.
	class DemoScene02_CubeRotatingWithPointLight : public IDemoScene
	{
		void _setup() override;
		void _draw(float time) override;
	public:
		void cleanup() override;

	private: /* functions */
		/// Creates vertex array and vertex buffer and fills them with cube's geometry
		void setupCube();
	private:
		/// Vertex array for holding vertex buffers and their layouts
		VertexArray vertexArray;
		/// Shader program for rendering
		Shader shader;

		/// Projection matrix
		glm::mat4 projectionMatrix;
		/// View matrix
		glm::mat4 viewMatrix;

		/// Position of point light
		glm::vec3 lightPos;
		/// Color of point light
		glm::vec3 lightColor;
		/// Intensity of point light
		float lightIntensity;
	};

} // namespace Pecan