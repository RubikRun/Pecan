#pragma once

namespace Pecan {

	class Renderer;

	/// A class representing a vertex buffer in our renderer.
	/// A vertex buffer simply holds a buffer of data
	/// that can be used as an array of vertices.
	class VertexBuffer
	{
	public:
		/// Creates an empty uninitialized vertex buffer.
		VertexBuffer();
		/// Deletes the vertex buffer and unbinds it.
		~VertexBuffer();

		/// Creates the underlying vertex buffer object,
		/// initializes it with the given data and binds it.
		/// @param data - raw data to be filled to the vertex buffer
		/// @param size - size of data in bytes
		void create(const void* data, size_t size);
		/// Deletes the vertex buffer and unbinds it.
		void destroy();

		/// Binds the vertex buffer
		void bind() const;
		/// Unbinds the vertex buffer
		void unbind() const;

	private:
		/// ID of the vertex buffer object inside OpenGL
		unsigned id = 0;
		/// Pointer to the Renderer instance
		Renderer* renderer = nullptr;
	};

} // namespace Pecan