#include "DemoScene02_CubeRotatingWithPointLight.h"

#include "Renderer/Renderer.h"
#include "FileUtils.h"
#include "Config/Config.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace Pecan {

	void DemoScene02_CubeRotatingWithPointLight::_setup() {
		// Read vertex shader and fragment shader's source code
		const std::string vertexShaderSource = FileUtils::readTextFile(Config::getDemoScene02_vertexShaderFilepath().c_str());
		const std::string fragmentShaderSource = FileUtils::readTextFile(Config::getDemoScene02_fragmentShaderFilepath().c_str());
		// Create shader program with the vertex and fragment shader's source code
		shader.create(vertexShaderSource.c_str(), fragmentShaderSource.c_str());

		// Setup projection matrix and view matrix
		projectionMatrix = glm::perspective(glm::radians(45.0f), float(Config::getWindowWidth()) / float(Config::getWindowHeight()), 0.1f, 100.0f);
		viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -3.0f));
		// Setup light properties
		lightPos = glm::vec3(5.0f, 5.0f, 5.0f);
		lightColor = glm::vec3(1.0f, 1.0f, 1.0f);
		lightIntensity = 1.0f;

		// Setup cube's geometry
		setupCube();

		// Enable depth testing so that the closer faces of the cube can be drawn on top of further faces
		renderer->glEnable(GL_DEPTH_TEST);
	}

	void DemoScene02_CubeRotatingWithPointLight::_draw(float time) {
		// Clear with background color and clear depth buffer
		renderer->glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Bind shader program to be used for rendering
		shader.bind();

		// Create model matrix (rotate over time)
		const glm::mat4 model = glm::rotate(glm::mat4(1.0f), time * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

		// Set uniform values in shader
		shader.setUniformMatrix4fv("u_model", model);
		shader.setUniformMatrix4fv("u_view", viewMatrix);
		shader.setUniformMatrix4fv("u_projection", projectionMatrix);
		shader.setUniform3fv("u_lightPos", lightPos);
		shader.setUniform3fv("u_lightColor", lightColor);
		shader.setUniform1f("u_lightIntensity", lightIntensity);

		// Draw the cube
		renderer->glDrawArrays(GL_TRIANGLES, 0, 36);
	}

	void DemoScene02_CubeRotatingWithPointLight::cleanup() {
		// Delete vertex array object and unbind it
		vertexArray.destroy();
		// Delete shader program and unbind it
		shader.destroy();
		// Disable depth testing
		renderer->glDisable(GL_DEPTH_TEST);
	}

	void DemoScene02_CubeRotatingWithPointLight::setupCube() {
		const GLfloat vertices[6 * 6 * 9] = {
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f,

			-0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f, -0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,
			-0.5f, -0.5f,   0.5f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f,

			-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f, -0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 0.0f, 1.0f, 0.0f, -1.0f, 0.0f, 0.0f,

			0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			0.5f,  0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			0.5f, -0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,
			0.5f,  0.5f,  0.5f, 0.0f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f,

			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f,  0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,
			-0.5f, -0.5f, -0.5f, 1.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f,

			-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f,  0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,
			-0.5f,  0.5f, -0.5f, 1.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f
		};
		// Create a vertex buffer from cube's vertices and describe its layout
		VertexBufferPtr vertexBuffer = std::make_shared<VertexBuffer>();
		vertexBuffer->create(
			vertices,
			sizeof(vertices),
			{
				{ ShaderDataType::Float3, "position" },
				{ ShaderDataType::Float3, "color" },
				{ ShaderDataType::Float3, "normal" }
			}
		);
		// Create a vertex array and add vertex buffer to it
		vertexArray.create();
		vertexArray.addVertexBuffer(vertexBuffer);
	}

} // namespace Pecan