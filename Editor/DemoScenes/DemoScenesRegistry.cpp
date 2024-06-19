#include "DemoScenesRegistry.h"

#include "DemoScene00_Triangle.h"
#include "DemoScene01_TriangleMovingColored.h"
#include "DemoScene02_CubeRotatingWithDirectionalLight.h"

namespace Pecan {

	typedef DemoScenesRegistry::SceneInfo SceneInfo;

	const std::vector<SceneInfo>& DemoScenesRegistry::getScenes() {
		static const std::vector<SceneInfo> scenes = {
			SceneInfo { "Triangle", new DemoScene00_Triangle() },
			SceneInfo { "Moving Triangle", new DemoScene01_TriangleMovingColored() },
			SceneInfo { "Rotating Cube", new DemoScene02_CubeRotatingWithDirectionalLight() }
		};
		return scenes;
	}

} // namespace Pecan