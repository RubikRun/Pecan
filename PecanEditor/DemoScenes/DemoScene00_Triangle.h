#pragma once

#include "IDemoScene.h"

#include <QOpenGLFunctions_4_5_Core>

namespace Pecan {

	/// Demo scene that renders a single white triangle in the middle of the screen.
	class DemoScene00_Triangle : public IDemoScene
	{
	public:
		/// Creates the demo scene.
		/// @param openGL - pointer to initialized OpenGL functions
		DemoScene00_Triangle(QOpenGLFunctions_4_5_Core* openGL);

		void setup() override;
		void draw() override;
		void cleanup() override;
	private:
		GLuint vertexArrayObjectID = 0;
		GLuint vertexBufferObjectID = 0;
		// Pointer to initialized OpenGL functions
		QOpenGLFunctions_4_5_Core* openGL;
	};

} // namespace Pecan