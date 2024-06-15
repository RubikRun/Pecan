#pragma once

#include "DemoScenes/IDemoScene.h"

#include <vector>
#include <string>

namespace Pecan {

	/// DemoScenesRegistry is a thread-safe singleton class
	/// for keeping track of existing demo scenes and providing info about them.
	class DemoScenesRegistry
	{
	public:
		/// Returns the only instance of DemoScenesRegistry.
		/// If called for the first time, the instance is first created with our demo scenes
		/// and then returned.
		static DemoScenesRegistry* getInstance();
		/// Copy constructor and assignment operator must be deleted
		DemoScenesRegistry(DemoScenesRegistry& other) = delete;
		void operator=(const DemoScenesRegistry&) = delete;

		/// Structure that holds info about a demo scene and a pointer to an instance of it
		struct SceneInfo
		{
			std::string name;
			IDemoScene* scene;
		};

		/// Returns the list of scenes and their infos
		const std::vector<SceneInfo>& getScenes() const { return scenes; }

	private:
		/// List of all existing demo scenes
		std::vector<SceneInfo> scenes;

		// Constructor and destructor must be private so that DemoScenesRegistry cannot be instantiated from outside
		DemoScenesRegistry();
		~DemoScenesRegistry() {}

		/// Pointer to the only instance of DemoScenesRegistry
		static DemoScenesRegistry* instance;
		/// Mutex for thread-safe instantiation of DemoScenesRegistry
		static std::mutex mutex;
	};

} // namespace Pecan