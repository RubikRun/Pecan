#pragma once

#include "DemoScenes/IDemoScene.h"

#include <vector>
#include <string>

namespace Pecan {

	class DemoScenesRegistry
	{
	public:
		/// Structure that holds info about a demo scene and a pointer to an instance of it
		struct SceneInfo
		{
			std::string name;
			IDemoScene* scene;
		};
		/// Returns the list of scenes and their infos
		static const std::vector<SceneInfo>& getScenes();
	};

} // namespace Pecan