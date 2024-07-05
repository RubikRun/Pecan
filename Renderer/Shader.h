#pragma once

#include "Renderer.h"
#include "glm/glm.hpp"

#include <unordered_map>

namespace Pecan {

	/// A class representing a shader program in our renderer.
	class Shader
	{
	public:
		/// Creates an empty uninitialized shader program.
		Shader();
		/// Deletes the shader program and unbinds it.
		~Shader();

		/// Creates the underlying shader program object with given source code for vertex shader and fragment shader.
		/// @param vertexShaderSource - Source code for the vertex shader
		/// @param fragmentShaderSource - Source code for the fragment shader
		void create(const char* vertexShaderSource, const char* fragmentShaderSource);
		/// Deletes the shader program and unbinds it.
		void destroy();

		/// Binds the shader program
		void bind() const;
		/// Unbinds the shader program
		void unbind() const;

		/// Functions for setting the value of a uniform inside the shader
		/// @param uniformName - Name of the uniform inside the shader whose value should be set
		/// @param value - Value to be set to the uniform inside the shader. Different functions for different types of this value.
		void setUniform1f(const char* uniformName, float value);
		void setUniform3fv(const char* uniformName, const glm::vec3& value);
		void setUniformMatrix4fv(const char* uniformName, const glm::mat4& value);

	private: /* functions */
		/// Compiles given shader's source code.
		/// "Shader" here means a single shader type, for example a vertex shader.
		/// It does NOT mean a whole shader program.
		/// @param shaderType - Specifies the type of shader to be compiled
		/// @param source - Source code of the shader
		/// @return Compiled shader's ID
		unsigned compileShader(GLenum shaderType, const char* sourceCode);

		/// Returns the location inside the shader of the uniform with the given name.
		/// If such uniform doesn't exist, returns -1.
		/// @param uniformName - Name of the uniform whose location we want to retrieve
		int getUniformLocation(const std::string& uniformName) const;

	private: /* variables */
		/// A map that caches locations of uniforms inside the shader.
		/// The uniform locations in a given shader do not change,
		/// so if we need to access them repeatedly
		/// it's not necessary to retrieve them with OpenGL calls every time.
		/// First time we retrieve a location of a given uniform
		/// we will cache it inside this map
		/// and next times when we need it we can just read it from the cache.
		/// It maps uniform names to uniform locations.
		mutable std::unordered_map<std::string, int> uniformLocationCache;

		/// ID of the shader program object inside OpenGL
		unsigned id = 0;
		/// Pointer to the Renderer instance
		Renderer* renderer = nullptr;
	};

} // namespace Pecan