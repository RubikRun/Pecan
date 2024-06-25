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

	void Renderer::logOpenGLInfo() {
		Renderer* renderer = Renderer::getInstance();
		PECAN_LOG_INFO("OpenGL Vendor: " << renderer->glGetString(GL_VENDOR));
		PECAN_LOG_INFO("OpenGL Version: " << renderer->glGetString(GL_VERSION));
		PECAN_LOG_INFO("OpenGL Renderer: " << renderer->glGetString(GL_RENDERER));
	}

	unsigned Renderer::compileShader(GLenum shaderType, const char* sourceCode) {
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

	unsigned Renderer::createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource) {
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

	GLenum Renderer::getShaderDataTypeOpenGLBaseType(ShaderDataType type) {
		switch (type) {
			case ShaderDataType::Float:    return GL_FLOAT;
			case ShaderDataType::Float2:   return GL_FLOAT;
			case ShaderDataType::Float3:   return GL_FLOAT;
			case ShaderDataType::Float4:   return GL_FLOAT;
			case ShaderDataType::Mat3:     return GL_FLOAT;
			case ShaderDataType::Mat4:     return GL_FLOAT;
			case ShaderDataType::Int:      return GL_INT;
			case ShaderDataType::Int2:     return GL_INT;
			case ShaderDataType::Int3:     return GL_INT;
			case ShaderDataType::Int4:     return GL_INT;
			case ShaderDataType::Bool:     return GL_BOOL;
		}

		PECAN_LOG_ERROR("Unknown ShaderDataType.");
		return 0;
	}

	unsigned Renderer::getShaderDataTypeSize(ShaderDataType type) {
		switch (type) {
			case ShaderDataType::Float:    return 4;
			case ShaderDataType::Float2:   return 4 * 2;
			case ShaderDataType::Float3:   return 4 * 3;
			case ShaderDataType::Float4:   return 4 * 4;
			case ShaderDataType::Mat3:     return 4 * 3 * 3;
			case ShaderDataType::Mat4:     return 4 * 4 * 4;
			case ShaderDataType::Int:      return 4;
			case ShaderDataType::Int2:     return 4 * 2;
			case ShaderDataType::Int3:     return 4 * 3;
			case ShaderDataType::Int4:     return 4 * 4;
			case ShaderDataType::Bool:     return 1;
		}

		PECAN_LOG_ERROR("Unknown ShaderDataType.");
		return 0;
	}

	unsigned Renderer::getShaderDataTypeComponentCount(ShaderDataType type) {
		switch (type) {
			case ShaderDataType::Float:   return 1;
			case ShaderDataType::Float2:  return 2;
			case ShaderDataType::Float3:  return 3;
			case ShaderDataType::Float4:  return 4;
			case ShaderDataType::Mat3:    return 3 * 3;
			case ShaderDataType::Mat4:    return 4 * 4;
			case ShaderDataType::Int:     return 1;
			case ShaderDataType::Int2:    return 2;
			case ShaderDataType::Int3:    return 3;
			case ShaderDataType::Int4:    return 4;
			case ShaderDataType::Bool:    return 1;
		}

		PECAN_LOG_ERROR("Unknown ShaderDataType.");
		return 0;
	}

	Renderer::Renderer() {
		initializeOpenGLFunctions();
	}

} // namespace Pecan
