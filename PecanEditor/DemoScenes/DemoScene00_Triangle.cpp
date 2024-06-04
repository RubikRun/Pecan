#include "DemoScene00_Triangle.h"

namespace Pecan {

	DemoScene00_Triangle::DemoScene00_Triangle(QOpenGLFunctions_4_5_Core* openGL)
		: openGL(openGL)
	{}

	void DemoScene00_Triangle::setup() {
		// Create and bind vertex array
		openGL->glCreateVertexArrays(1, &vertexArrayObjectID);
		openGL->glBindVertexArray(vertexArrayObjectID);
		// Create and bind vertex buffer
		openGL->glGenBuffers(1, &vertexBufferObjectID);
		openGL->glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
		// Data of triangle's vertices
		const GLfloat vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			+0.5f, -0.5f, 0.0f,
			+0.0f, +0.5f, 0.0f
		};
		openGL->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Declare position attribute
		openGL->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), reinterpret_cast<GLvoid*>(0));
		// Enable position attribute
		openGL->glEnableVertexAttribArray(0);
		// Unbind vertex array
		openGL->glBindVertexArray(0);
	}

	void DemoScene00_Triangle::draw() {
		// Draw triangle
		openGL->glBindVertexArray(vertexArrayObjectID);
		openGL->glDrawArrays(GL_TRIANGLES, 0, 3);
		openGL->glBindVertexArray(0);
	}

	void DemoScene00_Triangle::cleanup() {
		openGL->glDeleteVertexArrays(1, &vertexArrayObjectID);
	}

} // namespace Pecan