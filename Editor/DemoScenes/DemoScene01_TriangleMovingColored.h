#pragma once

#include "DemoScenes/IDemoScene.h"
#include "Renderer/VertexArray.h"

namespace Pecan {

	/// Demo scene that renders a single colored triangle that moves around and changes color.
	class DemoScene01_TriangleMovingColored : public IDemoScene
	{
		void _setup() override;
		void _draw(float time) override;
	public:
		void cleanup() override;
	private:
		VertexArray vertexArray;
		unsigned shaderProgramID = 0;
	};

} // namespace Pecan