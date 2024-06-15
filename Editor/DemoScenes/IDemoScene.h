#pragma once

#include "Renderer.h"

namespace Pecan {

	/// Interface for demo scenes used in Pecan's editor
	class IDemoScene
	{
	public:
		virtual ~IDemoScene() {}
		/// Setup function that loads the scene.
		/// To be called once at the beginning, but AFTER a window is created and there is an OpenGL context.
		void setup() {
			renderer = Renderer::getInstance();
			_setup();
		}
		/// Draw function that draws the scene.
		/// To be called every frame after loading the scene with setup().
		/// To be implemented by derived classes with specific functionality.
		/// @param time - Current time at which the scene should be drawn
		virtual void draw(float time) = 0;
		/// Cleanup function that unloads the scene.
		/// To be called once at the end.
		/// To be implemented by derived classes with specific functionality
		virtual void cleanup() {}

	protected:
		/// Pointer to the Renderer instance to be used by derived classes
		Renderer* renderer = nullptr;
	private:
		/// Setup function that loads the scene.
		/// To be implemented by derived classes with specific functionality.
		virtual void _setup() = 0;
	};

} // namespace Pecan