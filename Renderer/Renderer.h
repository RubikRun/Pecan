#pragma once

#include <QOpenGLFunctions_4_5_Core>
#include <mutex>

namespace Pecan {

	/// Renderer is a thread-safe singleton class responsible for all OpenGL calls
	class Renderer : public QOpenGLFunctions_4_5_Core
	{
	public:
		/// Returns the only instance of Renderer.
		/// If called for the first time, the instance is first created and then returned.
		static Renderer* getInstance();
		/// Copy constructor and assignment operator must be deleted
		Renderer(Renderer& other) = delete;
		void operator=(const Renderer&) = delete;

		/// Logs info about OpenGL version, vendor, etc.
		static void logOpenGLInfo();

		/// Compiles given shader's source code.
		/// @param shaderType - Specifies the type of shader to be compiled
		/// @param source - Source code of the shader
		/// @return Compiled shader's ID
		static unsigned compileShader(GLenum shaderType, const char* sourceCode);

		/// Creates a shader program from given source code of shaders.
		/// @param vertexShaderSource - Source code of the vertex shader to be compiled and used in the program
		/// @param fragmentShaderSource - Source code of the fragment shader to be compiled and used in the program
		/// @return Created shader program's ID
		static unsigned createShaderProgram(const char* vertexShaderSource, const char* fragmentShaderSource);

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