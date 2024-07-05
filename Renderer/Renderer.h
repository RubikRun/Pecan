#pragma once

#include <QOpenGLFunctions_4_5_Core>
#include <mutex>

namespace Pecan {

	/// Enum for shader data types that we support in Pecan.
	/// They are mapped to concrete data types of GLSL, HLSL, etc.
	enum class ShaderDataType
	{
		None = 0, Float = 1, Float2 = 2, Float3 = 3, Float4 = 4, Mat3 = 5, Mat4 = 6, Int = 7, Int2 = 8, Int3 = 9, Int4 = 10, Bool = 11
	};

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

		/// Returns the OpenGL base data type corresponding to the given shader data type.
		/// Here "base type" means that the given shader data type can be multi-component
		/// and the function will return the type of a single component of that type.
		static GLenum getShaderDataTypeOpenGLBaseType(ShaderDataType type);

		/// Returns size in bytes of a given shader data type
		static unsigned getShaderDataTypeSize(ShaderDataType type);

		/// Returns number of components of a given shader data type
		static unsigned getShaderDataTypeComponentCount(ShaderDataType type);

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