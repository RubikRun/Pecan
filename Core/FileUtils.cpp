#include "FileUtils.h"
#include "PecanLogger.h"

#include <sstream>
#include <fstream>

namespace Pecan {
	namespace FileUtils {
		std::string readTextFile(const char* filepath) {
			// Open file stream to the given filepath
			std::ifstream file(filepath);
			if (!file.is_open()) {
				PECAN_LOG_ERROR("Requested text file cannot be opened: " << filepath);
				return std::string();
			}
			// Read whole file into a single string stream
			std::stringstream buffer;
			buffer << file.rdbuf();
			// Close file stream
			file.close();
			if (file.is_open()) {
				PECAN_LOG_ERROR("Requested text file cannot be closed: " << filepath);
			}
			// Return the contents of the string stream as a string
			return buffer.str();
		}
	} // namespace FileUtils
} // namespace Pecan