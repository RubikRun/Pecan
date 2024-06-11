#include "Renderer.h"

#include "PecanLogger.h"

namespace Pecan {

	Renderer* Renderer::instance = nullptr;
	std::mutex Renderer::mutex;

	Renderer* Renderer::getInstance() {
		std::lock_guard<std::mutex> lock(mutex);
		if (instance == nullptr)
		{
			instance = new Renderer();
		}
		return instance;
	}

	void Renderer::logOpenGLInfo()
	{
		Renderer* renderer = Renderer::getInstance();
		PECAN_LOG_INFO("OpenGL Vendor: " << renderer->glGetString(GL_VENDOR));
		PECAN_LOG_INFO("OpenGL Version: " << renderer->glGetString(GL_VERSION));
		PECAN_LOG_INFO("OpenGL Renderer: " << renderer->glGetString(GL_RENDERER));
	}

	void Renderer::setViewport(int x, int y, int width, int height)
	{
		Renderer::getInstance()->glViewport(GLint(x), GLint(y), GLsizei(width), GLsizei(height));
	}

	void Renderer::createVertexArrays(int n, unsigned* arrays)
	{
		Renderer::getInstance()->glCreateVertexArrays(n, arrays);
	}

	void Renderer::bindVertexArray(unsigned array)
	{
		Renderer::getInstance()->glBindVertexArray(array);
	}

	void Renderer::genBuffers(int n, unsigned* buffers)
	{
		Renderer::getInstance()->glGenBuffers(n, buffers);
	}

	void Renderer::bindBuffer(GLenum target, unsigned buffer)
	{
		Renderer::getInstance()->glBindBuffer(target, buffer);
	}

	void Renderer::bufferData(GLenum target, long long size, const void* data, GLenum usage)
	{
		Renderer::getInstance()->glBufferData(target, size, data, usage);
	}

	void Renderer::vertexAttribPointer(unsigned index, int size, GLenum type, bool normalized, int stride, long long offset)
	{
		Renderer::getInstance()->glVertexAttribPointer(
			index,
			size,
			type,
			normalized ? GL_TRUE : GL_FALSE,
			stride,
			reinterpret_cast<GLvoid*>(offset)
		);
	}

	void Renderer::enableVertexAttribArray(unsigned index)
	{
		Renderer::getInstance()->glEnableVertexAttribArray(index);
	}

	void Renderer::drawArrays(GLenum mode, int first, int count)
	{
		Renderer::getInstance()->glDrawArrays(mode, first, count);
	}

	void Renderer::deleteVertexArrays(int n, const unsigned* arrays)
	{
		Renderer::getInstance()->glDeleteVertexArrays(n, arrays);
	}

	Renderer::Renderer()
	{
		initializeOpenGLFunctions();
	}

} // namespace Pecan
