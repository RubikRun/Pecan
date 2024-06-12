#include "DemoScene01_TriangleMovingColored.h"

#include "Renderer.h"
#include "FileUtils.h"

namespace Pecan {

	// TODO: read from config
	static const char* vertexShaderFilepath = "DemoScenes/Shaders/DemoScene01_vertex.shader";
	static const char* fragmentShaderFilepath = "DemoScenes/Shaders/DemoScene01_fragment.shader";

	void DemoScene01_TriangleMovingColored::_setup() {
		// Read vertex shader and fragment shader's source code
		const std::string vertexShaderSource = FileUtils::readTextFile(vertexShaderFilepath);
		const std::string fragmentShaderSource = FileUtils::readTextFile(fragmentShaderFilepath);
		// Create a shader program with the vertex and fragment shader's source code
		shaderProgramID = Renderer::createShaderProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());

		// Create and bind a vertex array object
		renderer->glCreateVertexArrays(1, &vertexArrayObjectID);
		renderer->glBindVertexArray(vertexArrayObjectID);
	}

	void DemoScene01_TriangleMovingColored::draw(float time) {
		// Use our shader program
		renderer->glUseProgram(shaderProgramID);
		// Animate background color
		const GLfloat backgroundColor[] = {
			sin(time) * 0.5f + 0.5f,
			cos(time) * 0.5f + 0.5f,
			0.0f,
			1.0f
		};
		renderer->glClearBufferfv(GL_COLOR, 0, backgroundColor);
		// Animate offset vertex attribute
		GLfloat offsetAttribData[] = {
			sin(time) * 0.3f,
			cos(time) * 0.2f,
			0.0f, 0.0f
		};
		// Set the same offset attribute to all vertices
		renderer->glVertexAttrib4fv(0, offsetAttribData);
		// Animate color vertex attribute
		GLfloat colorAttribData[] = {
			-(sin(time) * 0.5f) + 0.5f,
			-(cos(time) * 0.5f) + 0.5f,
			0.0f,
			1.0f
		};
		// Set the same color attribute to all vertices
		renderer->glVertexAttrib4fv(1, colorAttribData);
		// Draw triangle by drawing 3 vertices.
		// Their positions are hardcoded inside the vertex shader.
		renderer->glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void DemoScene01_TriangleMovingColored::cleanup() {
		// Delete vertex array object and shader program
		renderer->glDeleteVertexArrays(1, &vertexArrayObjectID);
		renderer->glDeleteProgram(shaderProgramID);
	}

} // namespace Pecan