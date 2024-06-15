#pragma once

#include "IDemoScene.h"

namespace Pecan {

	/// Demo scene that renders a single white triangle in the middle of the screen.
	class DemoScene00_Triangle : public IDemoScene
	{
		void _setup() override;
	public:
		void draw(float time) override;
		void cleanup() override;
	private:
		unsigned vertexArrayObjectID = 0;
		unsigned vertexBufferObjectID = 0;
	};

} // namespace Pecan