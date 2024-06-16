#pragma once

#include "Renderer.h"
#include "TimeUtils.h"

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
			// Begin timer after scene's setup has finished
			timer.reset();
		}
		/// Draw function that draws the scene.
		/// To be called every frame after loading the scene with setup().
		void draw() {
			_draw(timer.getTime());
		}
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

		/// Draw function that draws the scene.
		/// To be implemented by derived classes with specific functionality.
		/// @param time - Time elapsed since the scene's setup
		virtual void _draw(float time) = 0;
		/// Timer keeping track of elapsed time since the demo scene was last setup
		TimeUtils::Timer timer;
	};

} // namespace Pecan