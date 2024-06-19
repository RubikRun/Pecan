#pragma once

#include <string>
#include <functional>

namespace Pecan {

	namespace FileUtils
	{
		/// Reads a text file.
		/// Returns its content in a single string.
		/// @param filepath - Path to the text file to be read
		std::string readTextFile(const char* filepath);

		/// Reads a text file line by line and applies a given function to each line.
		/// @param filepath - Path to the text file to be read
		/// @param perLineFunc - A function to be applied to each line. It takes in the line as a string
		void readTextFileWithPerLineFunc(const char* filepath, const std::function<void(const std::string&)>& perLineFunc);
	} // namespace FileUtils

} // namespace Pecan