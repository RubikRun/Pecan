#pragma once

#include "VertexBuffer.h"

#include <vector>

namespace Pecan {

	/// A class representing a vertex array in our renderer.
	/// A vertex array consists of multiple vertex buffers and contains the state of their layouts.
	class VertexArray
	{
	public:
		/// Creates an empty uninitialized vertex array.
		VertexArray();
		/// Deletes the vertex array and unbinds it.
		~VertexArray();

		/// Creates the underlying vertex array object and binds it.
		void create();
		/// Deletes the vertex array and unbinds it.
		void destroy();

		/// Binds the vertex array
		void bind() const;
		/// Unbinds the vertex array
		void unbind() const;

		/// Adds a new vertex buffer to the vertex array
		void addVertexBuffer(const VertexBufferPtr& vertexBuffer);

	private: /* variables */
		/// Vector of vertex buffers associated with the vertex array
		std::vector<VertexBufferPtr> vertexBuffers;
		/// ID of the vertex array object inside OpenGL
		unsigned id = 0;
		/// Pointer to the Renderer instance
		Renderer* renderer = nullptr;
	};

} // namespace Pecan