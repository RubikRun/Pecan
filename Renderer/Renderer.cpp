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

	unsigned Renderer::compileShader(GLenum shaderType, const char* sourceCode)
	{
		Renderer* renderer = Renderer::getInstance();
		const GLuint shaderID = renderer->glCreateShader(shaderType);
		renderer->glShaderSource(shaderID, 1, &sourceCode, nullptr);
		renderer->glCompileShader(shaderID);

		GLint success;
		renderer->glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);
		if (!success) {
			char infoLog[512];
			renderer->glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
			PECAN_LOG_ERROR("Shader compilation failed: " << infoLog);
		}
		return shaderID;
	}

	unsigned Renderer::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource)
	{
		Renderer* renderer = Renderer::getInstance();
		// Compile shaders
		const GLuint vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
		const GLuint fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
		// Create program, attach shaders to it, and link it
		const GLuint programID = renderer->glCreateProgram();
		renderer->glAttachShader(programID, vertexShaderID);
		renderer->glAttachShader(programID, fragmentShaderID);
		renderer->glLinkProgram(programID);
		// Check if program linked successfully
		GLint success;
		renderer->glGetProgramiv(programID, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			renderer->glGetProgramInfoLog(programID, 512, nullptr, infoLog);
			PECAN_LOG_ERROR("Program linking failed: " << infoLog);
		}
		// Delete the shaders as the program has them now
		renderer->glDeleteShader(vertexShaderID);
		renderer->glDeleteShader(fragmentShaderID);

		return programID;
	}

	Renderer::Renderer()
	{
		initializeOpenGLFunctions();
	}

} // namespace Pecan
