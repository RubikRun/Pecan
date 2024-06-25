#include "VertexArray.h"

#include "PecanLogger.h"

namespace Pecan {

	VertexArray::VertexArray()
		: renderer(Renderer::getInstance())
	{}

	VertexArray::~VertexArray() {
		destroy();
	}

	void VertexArray::create() {
		renderer->glCreateVertexArrays(1, &id);
		bind();
	}

	void VertexArray::destroy() {
		unbind();
		renderer->glDeleteVertexArrays(1, &id);
		id = 0;
		// Clear the vector of vertex buffers.
		// NOTE: This will not necessary delete the vertex buffers,
		//       it will only delete them from this vertex array - it will delete the pointers.
		//       Since the pointers are reference-counted,
		//       a vertex buffer will be deleted if it's referenced only by this vertex array.
		//       If it's referenced by another vertex array, or used in another place, it will not be deleted here.
		vertexBuffers.clear();
	}

	void VertexArray::bind() const {
		renderer->glBindVertexArray(id);
	}

	void VertexArray::unbind() const {
		renderer->glBindVertexArray(0);
	}

	void VertexArray::addVertexBuffer(const VertexBufferPtr& vertexBuffer) {
		if (vertexBuffer == nullptr) {
			PECAN_LOG_ERROR("Trying to add a null vertex buffer to a vertex array. It will not be added.");
			return;
		}
		const BufferLayout& layout = vertexBuffer->getLayout();
		// Validity check for a vertex buffer with an empty layout.
		if (layout.getElements().empty()) {
			PECAN_LOG_ERROR("Trying to add a vertex buffer with an empty layout to a vertex array. It will not be added.");
			return;
		}
		const std::vector<BufferElement>& layoutElements = layout.getElements();
		// Bind the vertex array and the vertex buffer
		bind();
		vertexBuffer->bind();
		// Traverse layout elements
		for (unsigned index = 0; index < layoutElements.size(); index++) {
			const BufferElement& element = layoutElements[index];
			// For each element, enable a vertex attribute at that index
			renderer->glEnableVertexAttribArray(index);
			// and describe the vertex attribute's
			renderer->glVertexAttribPointer(
				index,
				element.getComponentCount(), // number of components,
				Renderer::getShaderDataTypeOpenGLBaseType(element.type), // type of each component,
				element.normalized ? GL_TRUE : GL_FALSE, // normalized flag,
				layout.getStride(), // stride in bytes until the same attribute of the next vertex,
				reinterpret_cast<GLvoid*>((long long)(element.offset)) // offset in bytes of the attribute from the beginning of the vertex.
			);
		}
		// Push the vertex buffer to the vector of vertex buffers inside the vertex array
		vertexBuffers.push_back(vertexBuffer);
	}

} // namespace Pecan