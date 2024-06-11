#include "DemoScene00_Triangle.h"

#include "Renderer.h"

namespace Pecan {

	void DemoScene00_Triangle::setup() {
		// Create and bind vertex array
		Renderer::createVertexArrays(1, &vertexArrayObjectID);
		Renderer::bindVertexArray(vertexArrayObjectID);
		// Create and bind vertex buffer
		Renderer::genBuffers(1, &vertexBufferObjectID);
		Renderer::bindBuffer(GL_ARRAY_BUFFER, vertexBufferObjectID);
		// Data of triangle's vertices
		const GLfloat vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			+0.5f, -0.5f, 0.0f,
			+0.0f, +0.5f, 0.0f
		};
		Renderer::bufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		// Declare position attribute
		Renderer::vertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(GLfloat), 0);
		// Enable position attribute
		Renderer::enableVertexAttribArray(0);
		// Unbind vertex array
		Renderer::bindVertexArray(0);
	}

	void DemoScene00_Triangle::draw() {
		// Draw triangle
		Renderer::bindVertexArray(vertexArrayObjectID);
		Renderer::drawArrays(GL_TRIANGLES, 0, 3);
		Renderer::bindVertexArray(0);
	}

	void DemoScene00_Triangle::cleanup() {
		Renderer::deleteVertexArrays(1, &vertexArrayObjectID);
	}

} // namespace Pecan