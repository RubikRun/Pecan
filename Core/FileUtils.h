#pragma once

#include <string>

namespace Pecan {

	namespace FileUtils
	{
		/// Reads a text file.
		/// Returns its content in a single string.
		/// @param filepath - Path to the text file to be read
		std::string readTextFile(const char* filepath);
	} // namespace FileUtils

} // namespace Pecan