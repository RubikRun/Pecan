#include "VertexBuffer.h"

#include "Renderer.h"

namespace Pecan {
	VertexBuffer::VertexBuffer()
		: renderer(Renderer::getInstance())
	{}

	VertexBuffer::~VertexBuffer() {
		destroy();
	}

	void VertexBuffer::create(const void* data, size_t size) {
		renderer->glGenBuffers(1, &id);
		renderer->glBindBuffer(GL_ARRAY_BUFFER, id);
		renderer->glBufferData(GL_ARRAY_BUFFER, (long long)(size), data, GL_STATIC_DRAW);
	}

	void VertexBuffer::destroy() {
		unbind();
		renderer->glDeleteBuffers(1, &id);
		id = 0;
	}

	void VertexBuffer::bind() const {
		renderer->glBindBuffer(GL_ARRAY_BUFFER, id);
	}

	void VertexBuffer::unbind() const {
		renderer->glBindBuffer(GL_ARRAY_BUFFER, 0);
	}

} // namespace Pecan