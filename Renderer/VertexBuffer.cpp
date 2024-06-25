#include "VertexBuffer.h"

namespace Pecan {

	BufferElement::BufferElement(ShaderDataType type, const std::string& name, bool normalized)
		: name(name), type(type), size(Renderer::getShaderDataTypeSize(type)), offset(0), normalized(normalized)
	{}

	unsigned BufferElement::getComponentCount() const {
		return Renderer::getShaderDataTypeComponentCount(type);
	}

	BufferLayout::BufferLayout(const std::initializer_list<BufferElement>& elements)
		: elements(elements)
	{
		calculateOffsetsAndStride();
	}

	void BufferLayout::calculateOffsetsAndStride() {
		unsigned offset = 0;
		// Loop over layout's elements and calculate each element's offset
		for (auto& element : elements) {
			// The offset of each element should be equal to the summed size in bytes of all previous elements
			element.offset = offset;
			offset += element.size;
		}
		// In the end we have a sum of the sizes of all elements
		// so this is equal to the size of the whole vertex which is equal to the stride.
		stride = offset;
	}

	VertexBuffer::VertexBuffer()
		: renderer(Renderer::getInstance())
	{}

	VertexBuffer::~VertexBuffer() {
		destroy();
	}

	void VertexBuffer::create(const void* data, size_t size, const BufferLayout& inLayout) {
		// Generate vertex buffer object, bind it and fill it with given data
		renderer->glGenBuffers(1, &id);
		bind();
		renderer->glBufferData(GL_ARRAY_BUFFER, (long long)(size), data, GL_STATIC_DRAW);
		// Set given layout
		layout = inLayout;
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