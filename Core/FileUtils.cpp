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

		void readTextFileWithPerLineFunc(const char* filepath, const std::function<void(const std::string&)>& perLineFunc) {
			// Open file stream to the given filepath
			std::ifstream file(filepath);
			if (!file.is_open()) {
				PECAN_LOG_ERROR("Requested text file cannot be opened: " << filepath);
				return;
			}
			// Read from file line by line
			std::string line;
			int lineIdx = 0;
			while (std::getline(file, line)) {
				// Call the per line function with each line from the file
				perLineFunc(line);
				lineIdx++;
			}
			// Close file stream
			file.close();
			if (file.is_open()) {
				PECAN_LOG_ERROR("Requested text file cannot be closed: " << filepath);
			}

		}
	} // namespace FileUtils
} // namespace Pecan