#pragma once

#include "DemoScenes/IDemoScene.h"

namespace Pecan {

	/// Demo scene that renders a single colored triangle that moves around and changes color.
	class DemoScene01_TriangleMovingColored : public IDemoScene
	{
		void _setup() override;
		void _draw(float time) override;
	public:
		void cleanup() override;
	private:
		unsigned vertexArrayObjectID = 0;
		unsigned shaderProgramID = 0;
	};

} // namespace Pecan