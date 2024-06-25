#pragma once

#include "Renderer.h"

#include <memory>

namespace Pecan {

	/// An element from a layout of a vertex buffer.
	/// Usually corresponds to a vertex attribute inside the shader.
	struct BufferElement
	{
		/// Creates an unitialized buffer element
		BufferElement() {}
		/// Creates a buffer element
		BufferElement(ShaderDataType type, const std::string& name, bool normalized = false);
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
	class BufferLayout
	{
	public:
		/// Creates an empty unitialized buffer layout
		BufferLayout() {}
		/// Creates a buffer layout with the given buffer elements
		BufferLayout(const std::initializer_list<BufferElement>& elements);

		/// Returns the stride between two consecutive vertices in the buffer,
		/// equal to the size in bytes of a single vertex.
		inline unsigned getStride() const { return stride; }
		/// Returns the elements of the layout
		inline const std::vector<BufferElement>& getElements() const { return elements; }

		/// Iterators for beginning and end of layout's elements
		std::vector<BufferElement>::iterator begin() { return elements.begin(); }
		std::vector<BufferElement>::iterator end() { return elements.end(); }
		std::vector<BufferElement>::const_iterator begin() const { return elements.begin(); }
		std::vector<BufferElement>::const_iterator end() const { return elements.end(); }

	private: /* functions */
		/// Calculates the offset of each layout element
		/// and the overall stride between two consecutive vertices.
		void calculateOffsetsAndStride();

	private: /* variables */
		/// Vector of layout's elements
		std::vector<BufferElement> elements;
		/// Stride between two consecutive vertices in the buffer
		unsigned stride = 0;
	};

	/// A class representing a vertex buffer in our renderer
	/// and the layout of its vertices and vertex attributes.
	class VertexBuffer
	{
	public:
		/// Creates an empty uninitialized vertex buffer.
		VertexBuffer();
		/// Deletes the vertex buffer and unbinds it.
		~VertexBuffer();

		/// Creates the underlying vertex buffer object with some layout,
		/// initializes it with the given data and binds it.
		/// @param data - raw data to be filled to the vertex buffer
		/// @param size - size of data in bytes
		/// @param inLayout - layout of vertex buffer's vertices
		void create(const void* data, size_t size, const BufferLayout& inLayout);
		/// Deletes the vertex buffer and unbinds it.
		void destroy();

		/// Returns a constant reference to the vertex buffer's layout
		const BufferLayout& getLayout() const { return layout; }

		/// Binds the vertex buffer
		void bind() const;
		/// Unbinds the vertex buffer
		void unbind() const;

	private:
		/// Layout of the vertex buffer
		BufferLayout layout;
		/// ID of the vertex buffer object inside OpenGL
		unsigned id = 0;
		/// Pointer to the Renderer instance
		Renderer* renderer = nullptr;
	};
	typedef std::shared_ptr<VertexBuffer> VertexBufferPtr;

} // namespace Pecan