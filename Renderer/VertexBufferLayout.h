#pragma once

#include "Renderer.h"
#include "PecanLogger.h"

namespace Pecan {

	/// An element from a layout of a vertex buffer.
	/// Usually corresponds to a vertex attribute inside the shader.
	struct VertexBufferElement
	{
		/// Creates an unitialized buffer element
		VertexBufferElement() {}
		/// Creates a buffer element
		VertexBufferElement(ShaderDataType type, const std::string& name, bool normalized = false);
		/// Returns number of components of the buffer element
		unsigned getComponentCount() const;

		/// Name of buffer element, usually corresponding to name of vertex attribute
		std::string name;
		/// Data type of buffer element, usually corresponding to the shader type of the vertex attribute
		ShaderDataType type = ShaderDataType::None;
		/// Size in bytes of buffer element
		unsigned size = 0;
		/// Offset in bytes of buffer element relative to the beginning of a vertex.
		/// Should be calculated when we use this buffer element inside a buffer layout.
		unsigned offset = 0;
		/// Flag for whether the corresponding vertex attribute should be normalized
		bool normalized = false;
	};

	/// Layout of a vertex buffer
	class VertexBufferLayout
	{
	public:
		/// Creates an empty unitialized vertex buffer layout
		VertexBufferLayout() {}
		/// Creates a vertex buffer layout with the given buffer elements
		VertexBufferLayout(const std::initializer_list<VertexBufferElement>& elements);

		/// Returns the stride between two consecutive vertices in the buffer,
		/// equal to the size in bytes of a single vertex.
		inline unsigned getStride() const { return stride; }
		/// Returns the elements of the layout
		inline const std::vector<VertexBufferElement>& getElements() const { return elements; }

		/// Iterators for beginning and end of layout's elements
		std::vector<VertexBufferElement>::iterator begin() { return elements.begin(); }
		std::vector<VertexBufferElement>::iterator end() { return elements.end(); }
		std::vector<VertexBufferElement>::const_iterator begin() const { return elements.begin(); }
		std::vector<VertexBufferElement>::const_iterator end() const { return elements.end(); }

	private: /* functions */
		/// Calculates the offset of each layout element
		/// and the overall stride between two consecutive vertices.
		void calculateOffsetsAndStride();

	private: /* variables */
		/// Vector of layout's elements
		std::vector<VertexBufferElement> elements;
		/// Stride between two consecutive vertices in the buffer
		unsigned stride = 0;
	};

} // namespace Pecan