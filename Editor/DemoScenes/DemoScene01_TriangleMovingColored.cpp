#include "DemoScene01_TriangleMovingColored.h"

#include "Renderer.h"
#include "FileUtils.h"
#include "Config/Config.h"

namespace Pecan {

	void DemoScene01_TriangleMovingColored::_setup() {
		// Read vertex shader and fragment shader's source code
		const std::string vertexShaderSource = FileUtils::readTextFile(Config::getVertexShaderFilepath().c_str());
		const std::string fragmentShaderSource = FileUtils::readTextFile(Config::getFragmentShaderFilepath().c_str());
		// Create a shader program with the vertex and fragment shader's source code
		shaderProgramID = Renderer::createShaderProgram(vertexShaderSource.c_str(), fragmentShaderSource.c_str());

		// Create and bind a vertex array object
		renderer->glCreateVertexArrays(1, &vertexArrayObjectID);
		renderer->glBindVertexArray(vertexArrayObjectID);
	}

	void DemoScene01_TriangleMovingColored::_draw(float time) {
		// Animate background color
		const GLfloat backgroundColor[] = {
			sin(time) * 0.5f + 0.5f,
			cos(time) * 0.5f + 0.5f,
			0.0f,
			1.0f
		};
		renderer->glClearBufferfv(GL_COLOR, 0, backgroundColor);
		// Use our shader program
		renderer->glUseProgram(shaderProgramID);
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
		// Delete vertex array object and unbind it
		renderer->glDeleteVertexArrays(1, &vertexArrayObjectID);
		renderer->glBindVertexArray(0);
		vertexArrayObjectID = 0;
		// Delete shader program and stop using it
		renderer->glDeleteProgram(shaderProgramID);
		renderer->glUseProgram(0);
		shaderProgramID = 0;
	}

} // namespace Pecan