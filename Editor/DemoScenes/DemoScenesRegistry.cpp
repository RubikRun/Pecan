#include "DemoScenesRegistry.h"

#include "DemoScene00_Triangle.h"
#include "DemoScene01_TriangleMovingColored.h"

namespace Pecan {

	DemoScenesRegistry* DemoScenesRegistry::instance = nullptr;
	std::mutex DemoScenesRegistry::mutex;

	DemoScenesRegistry* DemoScenesRegistry::getInstance() {
		std::lock_guard<std::mutex> lock(mutex);
		if (instance == nullptr)
		{
			instance = new DemoScenesRegistry();
		}
		return instance;
	}

	DemoScenesRegistry::DemoScenesRegistry()
		// Initialize scenes by hardcoding the names and classes of our existing demo scenes
		: scenes({
			SceneInfo { "00_Triangle", new DemoScene00_Triangle() },
			SceneInfo { "01_TriangleMovingColored", new DemoScene01_TriangleMovingColored() }
		})
	{}

} // namespace Pecan