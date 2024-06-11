#pragma once

#include <QOpenGLFunctions_4_5_Core>
#include <mutex>

namespace Pecan {

	/// Renderer is a thread-safe singleton class responsible for all OpenGL calls
	class Renderer : private QOpenGLFunctions_4_5_Core
	{
	public:
		/// Returns the only instance of Renderer.
		/// If called for the first time, the instance is first created and then returned.
		static Renderer* getInstance();
		/// Copy constructor and assignment operator must be deleted
		Renderer(Renderer& other) = delete;
		void operator=(const Renderer&) = delete;

		// ----- general -----
		static void logOpenGLInfo();
		static void setViewport(int x, int y, int width, int height);
		// ----- vertex array -----
		static void createVertexArrays(int n, unsigned* arrays);
		static void deleteVertexArrays(int n, const unsigned* arrays);
		static void bindVertexArray(unsigned array);
		// ----- buffer -----
		static void genBuffers(int n, unsigned* buffers);
		static void bindBuffer(GLenum target, unsigned buffer);
		static void bufferData(GLenum target, long long size, const void* data, GLenum usage);
		// ----- vertex attribute -----
		static void vertexAttribPointer(unsigned index, int size, GLenum type, bool normalized, int stride, long long offset);
		static void enableVertexAttribArray(unsigned index);
		// ----- draw -----
		static void drawArrays(GLenum mode, int first, int count);

	private:
		// Constructor and destructor must be private so that Renderer cannot be instantiated from outside
		Renderer();
		~Renderer() {}

		/// Pointer to the only instance of Renderer
		static Renderer* instance;
		/// Mutex for thread-safe instantiation of Renderer
		static std::mutex mutex;
	};

} // namespace Pecan