#pragma once

#include <string>
#include <QFont>

namespace Pecan {

	/// Class containing user-configurable global data
	class Config
	{
	public:
		/// Reads config from the config file,
		/// initializing all variables with the values from file
		static void init();

		/// Getters for config variables
		static int getWindowPositionX() { return Config::windowPositionX; }
		static int getWindowPositionY() { return Config::windowPositionY; }
		static int getWindowWidth() { return Config::windowWidth; }
		static int getWindowHeight() { return Config::windowHeight; }
		static int getControlsDialogWidth() { return Config::controlsDialogWidth; }
		static const std::string& getDemoScene01_vertexShaderFilepath() { return Config::demoScene01_vertexShaderFilepath; }
		static const std::string& getDemoScene01_fragmentShaderFilepath() { return Config::demoScene01_fragmentShaderFilepath; }
		static const std::string& getDemoScene02_vertexShaderFilepath() { return Config::demoScene02_vertexShaderFilepath; }
		static const std::string& getDemoScene02_fragmentShaderFilepath() { return Config::demoScene02_fragmentShaderFilepath; }
		static const QFont& getButtonFont() { return Config::buttonFont; }
		static int getButtonMinHeight() { return Config::buttonMinHeight; }

	private: /* functions */
		/// Handles a variable declaration from config file.
		/// A variable declaration is a string in format "var_name=var_value".
		/// It assigns the given var_value to the variable with the given var_name in our config.
		/// Note that the variable has to exist in our config,
		/// in other words we have to support it here in order for config files to be able to assign a value to it.
		static void handleDeclaration(const std::string& decl);
	private: /* variables */
		static int windowPositionX;
		static int windowPositionY;
		static int windowWidth;
		static int windowHeight;
		static int controlsDialogWidth;
		static std::string demoScene01_vertexShaderFilepath;
		static std::string demoScene01_fragmentShaderFilepath;
		static std::string demoScene02_vertexShaderFilepath;
		static std::string demoScene02_fragmentShaderFilepath;
		static QFont buttonFont;
		static int buttonMinHeight;
	};

} // namespace Pecan