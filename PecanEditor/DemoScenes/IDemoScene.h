#pragma once

namespace Pecan {

	/// Interface for demo scenes used in Pecan's editor
	class IDemoScene
	{
	public:
		virtual ~IDemoScene() {}
		/// Setup function that loads the scene. To be called once at the beginning.
		virtual void setup() = 0;
		/// Draw function that draws the scene. To be called every frame after loading the scene.
		virtual void draw() = 0;
		/// Cleanup function that unloads the scene. To be called once at the end.
		virtual void cleanup() {}
	};

} // namespace Pecan