cmake_minimum_required(VERSION 3.2)

# Constants
set(PROJECT_NAME "Machiavelli utils")
set(PROJECT_VERSION 0.0.1)
set(TARGET_NAME "utils")

# Project
project(${PROJECT_NAME}
	VERSION ${PROJECT_VERSION}
	LANGUAGES CXX)

# Source files
set(SOURCE_FILES
	"include/utils/definitions.h"
	"include/utils/memleakdetection.h"
	"src/utils/memleakdetection.cpp"
	"include/utils/noncopyable.h"
	"include/utils/platformdefinitions.h"
	"include/utils/cmd/command.hpp"
	"include/utils/cmd/commandhandler.hpp"
	"include/utils/cmd/error.h"
	"include/utils/cmd/errorcategory.h"
	"src/utils/cmd/errorcategory.cpp")

# Binaries
add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})

# Target properties.
set_target_properties(${TARGET_NAME} PROPERTIES LINKER_LANGUAGE CXX)

# Include directory
target_include_directories(${TARGET_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

# Compiler requirements.
target_compile_features(${TARGET_NAME}
	PRIVATE "cxx_range_for")

# Dependencies
