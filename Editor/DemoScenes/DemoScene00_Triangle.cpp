#include "DemoScene00_Triangle.h"

#include "Renderer.h"

namespace Pecan {

	void DemoScene00_Triangle::_setup() {
		// Set clear color to be black
		renderer->glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		// Create and bind vertex array
		renderer->glCreateVertexArrays(1, &vertexArrayObjectID);
		renderer->glBindVertexArray(vertexArrayObjectID);
		// Create and bind vertex buffer
		renderer->glGenBuffers(1, &vertexBufferObjectID);
		renderer->glBindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
		// Data of triangle's vertices
		const GLfloat vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			+0.5f, -0.5f, 0.0f,
			+0.0f, +0.5f, 0.0f
		};
		renderer->glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Declare position attribute
		renderer->glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(GLfloat), 0);
		// Enable position attribute
		renderer->glEnableVertexAttribArray(0);
	}

	void DemoScene00_Triangle::draw(float time) {
		// Clear the background
		renderer->glClear(GL_COLOR_BUFFER_BIT);
		// Draw triangle
		renderer->glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void DemoScene00_Triangle::cleanup() {
		// Delete vertex array and unbind it
		renderer->glDeleteVertexArrays(1, &vertexArrayObjectID);
		renderer->glBindVertexArray(0);
		vertexArrayObjectID = 0;
		// Delete vertex buffer and unbind it
		renderer->glDeleteBuffers(1, &vertexBufferObjectID);
		renderer->glBindBuffer(GL_ARRAY_BUFFER, 0);
		vertexBufferObjectID = 0;
	}

} // namespace Pecan