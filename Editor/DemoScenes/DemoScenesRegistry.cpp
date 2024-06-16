#include "DemoScenesRegistry.h"

#include "DemoScene00_Triangle.h"
#include "DemoScene01_TriangleMovingColored.h"

namespace Pecan {

	typedef DemoScenesRegistry::SceneInfo SceneInfo;

	const std::vector<SceneInfo>& DemoScenesRegistry::getScenes() {
		static const std::vector<SceneInfo> scenes = {
			SceneInfo { "00_Triangle", new DemoScene00_Triangle() },
			SceneInfo { "01_TriangleMovingColored", new DemoScene01_TriangleMovingColored() }
		};
		return scenes;
	}

} // namespace Pecan