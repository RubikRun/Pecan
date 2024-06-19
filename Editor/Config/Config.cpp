#include "Config.h"

#include "FileUtils.h"
#include "PecanLogger.h"

namespace Pecan {

	static const char* CONFIG_FILEPATH = "Config/editor.config";

	int Config::windowPositionX = -1;
	int Config::windowPositionY = -1;
	int Config::windowWidth = -1;
	int Config::windowHeight = -1;
	int Config::controlsDialogWidth = -1;
	std::string Config::demoScene01_vertexShaderFilepath;
	std::string Config::demoScene01_fragmentShaderFilepath;
	std::string Config::demoScene02_vertexShaderFilepath;
	std::string Config::demoScene02_fragmentShaderFilepath;
	QFont Config::buttonFont;
	int Config::buttonMinHeight = -1;

	void Config::init() {
		FileUtils::readTextFileWithPerLineFunc(
			CONFIG_FILEPATH,
			Config::handleDeclaration
		);
	}

	void Config::handleDeclaration(const std::string& decl) {
		const size_t equalsSignIdx = decl.find('=');
		if (equalsSignIdx == std::string::npos) {
			PECAN_LOG_WARNING("Config contains a line without '='. That line will be ignored.");
			return;
		}
		const std::string varName = decl.substr(0, equalsSignIdx);
		if (varName.empty()) {
			PECAN_LOG_WARNING("Config contains a line with an empty variable name. That line will be ignored.");
			return;
		}
		const std::string varValueStr = decl.substr(equalsSignIdx + 1);
		if (varValueStr.empty()) {
			PECAN_LOG_WARNING("Config contains a line with an empty variable value. That line will be ignored.");
			return;
		}

		bool varNameFound = false;

// Here we define a macro for each data type that we support in a config file.
// We already have the value that has to be assigned to the variable - varValueStr,
// and we also have the name of the variable - varName.
// These macros here check if a variable with this name exists
// and if it does, they try to parse the given varValueStr to the expected type
// and assign it to the corresponding variable in our config.
// If the parsing fails, the macros will just skip this declaration and log an error message.
#define HANDLE_DECLARATION_INT(VAR_NAME) \
if (varName == #VAR_NAME) { \
	varNameFound = true; \
	try { \
		const int varValue = std::stoi(varValueStr); \
		VAR_NAME = varValue; \
	} \
	catch (const std::exception& e) { \
		/* Cast exception to void to suppress compiler warning of not using the exception */ \
		(void)e;  \
		PECAN_LOG_ERROR("Config contains a line that assigns a value to a variable that's supposed to be an integer," \
			"but the provided value is not an integer. That line will be ignored."); \
		return; \
	} \
}

#define HANDLE_DECLARATION_STRING(VAR_NAME) \
if (varName == #VAR_NAME) { \
	varNameFound = true; \
	/* A string value is supposed to begin and end with double quotes - '"' */ \
	/* so we need its length to be at least 2 and the first and last character to be '"' */ \
	if (varValueStr.size() < 2 || varValueStr[0] != '"' || varValueStr.back() != '"') { \
		PECAN_LOG_ERROR("Config contains a line that assigns a value to a variable that's supposed to be a string, " \
			"but provided value is not a valid string enclosed in quotes. That line will be ignored."); \
		return; \
	} \
	/* Extract the actual string value that's between the 2 double quotes */ \
	const std::string varValueInnerStr = varValueStr.substr(1, varValueStr.size() - 2); \
	VAR_NAME = varValueInnerStr; \
}

#define HANDLE_DECLARATION_FONT(VAR_NAME) \
if (varName == #VAR_NAME) { \
	varNameFound = true; \
	bool valid = false; \
\
	if (varValueStr.size() >= 2 && varValueStr[0] == '(' && varValueStr.back() == ')') { \
		const size_t commaIdx = varValueStr.find(','); \
		if (commaIdx != std::string::npos) { \
			const std::string fontFamilyPart = varValueStr.substr(1, commaIdx - 1); \
			if (fontFamilyPart.size() >= 2 && fontFamilyPart[0] == '"' && fontFamilyPart.back() == '"') { \
				const std::string fontFamily = fontFamilyPart.substr(1, fontFamilyPart.size() - 2); \
				const std::string fontSizePart = varValueStr.substr(commaIdx + 1, varValueStr.size() - (commaIdx + 1) - 1); \
				try { \
					const int fontSize = std::stoi(fontSizePart); \
					VAR_NAME = QFont(fontFamily.c_str(), fontSize); \
					valid = true; \
				} \
				catch (const std::exception& e) { \
					/* Cast exception to void to suppress compiler warning of not using the exception */ \
					(void)e; \
					/* do nothing, just leave valid be false, as it already is */ \
				} \
			} \
		} \
	} \
\
	if (!valid) { \
		PECAN_LOG_ERROR("Config contains a line that assigns a value to a variable that's supposed to be a font, " \
			"but provided value is not a valid font. Should be in this format: \"(\"font_family\", font_size)\"" \
			"where font_size is an integer. That line will be ignored."); \
		return; \
	} \
}

		// Handle all variables in our config using the macros for the corresponding types.
		HANDLE_DECLARATION_INT(windowPositionX);
		HANDLE_DECLARATION_INT(windowPositionY);
		HANDLE_DECLARATION_INT(windowWidth);
		HANDLE_DECLARATION_INT(windowHeight);
		HANDLE_DECLARATION_INT(controlsDialogWidth);
		HANDLE_DECLARATION_STRING(demoScene01_vertexShaderFilepath);
		HANDLE_DECLARATION_STRING(demoScene01_fragmentShaderFilepath);
		HANDLE_DECLARATION_STRING(demoScene02_vertexShaderFilepath);
		HANDLE_DECLARATION_STRING(demoScene02_fragmentShaderFilepath);
		HANDLE_DECLARATION_INT(buttonMinHeight);
		HANDLE_DECLARATION_FONT(buttonFont);
		// Check if we did find the variable with one of the handling macros
		if (!varNameFound) {
			PECAN_LOG_ERROR("Config contains a line that assigns a value to a variable that doesn't exist in our config. That line will be ignored.");
		}

#undef HANDLE_DECLARATION_INT
#undef HANDLE_DECLARATION_STRING
#undef HANDLE_DECLARATION_FONT
	}

} // namespace Pecan