#pragma once

#include "IDemoScene.h"

namespace Pecan {

	/// Demo scene that renders a single white triangle in the middle of the screen.
	class DemoScene00_Triangle : public IDemoScene
	{
	public:
		void setup() override;
		void draw() override;
		void cleanup() override;
	private:
		unsigned vertexArrayObjectID = 0;
		unsigned vertexBufferObjectID = 0;
	};

} // namespace Pecan