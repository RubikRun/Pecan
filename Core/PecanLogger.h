#include <iostream>

#define PECAN_LOGGER_ERRORS 1
#define PECAN_LOGGER_WARNINGS 1
#define PECAN_LOGGER_DEBUG 1
#define PECAN_LOGGER_INFO 1

// TODO: use ifdef instead of if so that the check is done at compile time instead of run time
#define PECAN_LOG_ERROR(msg) if (PECAN_LOGGER_ERRORS) { std::cout << "[ERROR]: " << msg << std::endl; }
#define PECAN_LOG_WARNING(msg) if (PECAN_LOGGER_WARNINGS) { std::cout << "[WARNING]: " << msg << std::endl; }
#define PECAN_LOG_DEBUG(msg) if (PECAN_LOGGER_DEBUG) { std::cout << "[DEBUG]: " << msg << std::end;l }
#define PECAN_LOG_INFO(msg) if (PECAN_LOGGER_INFO) { std::cout << "[INFO]: " << msg << std::endl; }