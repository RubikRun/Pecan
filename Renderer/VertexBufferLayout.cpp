#include "VertexBufferLayout.h"

namespace Pecan {

	VertexBufferElement::VertexBufferElement(ShaderDataType type, const std::string& name, bool normalized)
		: name(name), type(type), size(Renderer::getShaderDataTypeSize(type)), offset(0), normalized(normalized)
	{}

	unsigned VertexBufferElement::getComponentCount() const {
		return Renderer::getShaderDataTypeComponentCount(type);
	}

	VertexBufferLayout::VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements)
		: elements(elements)
	{
		calculateOffsetsAndStride();
	}

	void VertexBufferLayout::calculateOffsetsAndStride() {
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

} // namespace Pecan