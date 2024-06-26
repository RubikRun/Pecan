#pragma once

#include "DemoScenes/IDemoScene.h"
#include "Renderer/VertexArray.h"

#include <glm/glm.hpp>

namespace Pecan {

	/// Demo scene that renders a rotating cube with different colored faces
	/// lit by a directional light.
	class DemoScene02_CubeRotatingWithDirectionalLight : public IDemoScene
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
		/// ID of OpenGL shader program created from our GLSL shaders
		unsigned shaderProgramID = 0;

		/// Projection matrix
		glm::mat4 projectionMatrix;
		/// View matrix
		glm::mat4 viewMatrix;

		/// Direction of directional light
		glm::vec3 lightDir;
		/// Color of directional light
		glm::vec3 lightColor;
		/// Intensity of directional light
		float lightIntensity;
	};

} // namespace Pecan