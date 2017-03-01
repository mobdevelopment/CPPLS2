cmake_minimum_required(VERSION 3.2)

# Constants
set(PROJECT_NAME "Machiavelli netw")
set(PROJECT_VERSION 0.0.1)
set(TARGET_NAME "netw")

# Project
project(${PROJECT_NAME}
	VERSION ${PROJECT_VERSION}
	LANGUAGES CXX)

# Source files
set(SOURCE_FILES
	"include/netw/tcp/server.h"
	"include/netw/telnet/server.h"
	"include/netw/telnet/serverclient.h"
	"src/netw/tcp/server.cpp"
	"src/netw/telnet/server.cpp"
	"src/netw/telnet/serverclient.cpp")

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
target_link_libraries(${TARGET_NAME} "utils")
target_link_libraries(${TARGET_NAME} ${TELNET_LIB_NAME})
