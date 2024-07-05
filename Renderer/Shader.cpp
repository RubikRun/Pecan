#include "Shader.h"

#include "PecanLogger.h"

#include <glm/gtc/type_ptr.hpp>

namespace Pecan {

	Shader::Shader()
		: renderer(Renderer::getInstance())
	{}

	Shader::~Shader() {
		destroy();
	}

	void Shader::create(const char* vertexShaderSource, const char* fragmentShaderSource) {
		// Compile shaders
		const GLuint vertexShaderID = compileShader(GL_VERTEX_SHADER, vertexShaderSource);
		const GLuint fragmentShaderID = compileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
		// Create program, attach shaders to it, and link it
		id = renderer->glCreateProgram();
		renderer->glAttachShader(id, vertexShaderID);
		renderer->glAttachShader(id, fragmentShaderID);
		renderer->glLinkProgram(id);
		// Check if program linked successfully
		GLint success;
		renderer->glGetProgramiv(id, GL_LINK_STATUS, &success);
		if (!success) {
			char infoLog[512];
			renderer->glGetProgramInfoLog(id, 512, nullptr, infoLog);
			PECAN_LOG_ERROR("Shader program linking failed: " << infoLog);
		}
		// Delete the shaders as the program has them now
		renderer->glDeleteShader(vertexShaderID);
		renderer->glDeleteShader(fragmentShaderID);
	}

	void Shader::destroy() {
		unbind();
		renderer->glDeleteProgram(id);
		id = 0;
		/// Clear the cache of uniform locations
		/// since they apply specifically to the shader being destroyed here.
		uniformLocationCache.clear();
	}

	void Shader::bind() const {
		renderer->glUseProgram(id);
	}

	void Shader::unbind() const {
		renderer->glUseProgram(0);
	}

	void Shader::setUniform1f(const char* uniformName, float value) {
		const GLint location  = getUniformLocation(uniformName);
		renderer->glUniform1f(location, value);
	}

	void Shader::setUniform3fv(const char* uniformName, const glm::vec3& value) {
		const GLint location = getUniformLocation(uniformName);
		renderer->glUniform3fv(location, 1, glm::value_ptr(value));
	}

	void Shader::setUniformMatrix4fv(const char* uniformName, const glm::mat4& value) {
		const GLint location = getUniformLocation(uniformName);
		renderer->glUniformMatrix4fv(location, 1, GL_FALSE, &value[0][0]);
	}

	unsigned Shader::compileShader(GLenum shaderType, const char* sourceCode) {
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

	GLint Shader::getUniformLocation(const std::string& uniformName) const {
		// If we have the location of this uniform cached, retrieve it from cache
		const auto cacheIt = uniformLocationCache.find(uniformName);
		if (cacheIt != uniformLocationCache.end()) {
			return cacheIt->second;
		}
		// Otherwise retrieve it by asking OpenGL for the location
		const GLint location = renderer->glGetUniformLocation(id, uniformName.c_str());
		if (location < 0) {
			PECAN_LOG_ERROR("Trying to set value for uniform \"" << uniformName << "\" inside a shader, but such uniform doesn't exist.");
		}
		// Cache the location so that it can be reused in next calls to this function
		uniformLocationCache[uniformName] = location;
		return location;
	}

} // namespace Pecan