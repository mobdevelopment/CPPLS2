cmake_minimum_required(VERSION 3.2)

###############################################################################
## Constants
###############################################################################
set(PROJECT_NAME "Machiavelli")
set(PROJECT_VERSION 0.0.1)
set(CMAKE_MODULE_PATH
    ${CMAKE_MODULE_PATH}
    "${CMAKE_SOURCE_DIR}/../cmake/modules")
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})


###############################################################################
## Project
###############################################################################
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)


###############################################################################
## 3rd party libraries
###############################################################################
# School telnet library.
set(TELNET_LIB_NAME "telnet")

set(TELNET_LIB_SOURCE_FILES
	"lib/telnet/circularbuffer.h"
	"lib/telnet/clientcommand.h"
	"lib/telnet/clientinfo.h"
	"lib/telnet/socket.cpp"
	"lib/telnet/socket.h"
	"lib/telnet/sync_queue.h"
	"lib/telnet/throw.cpp"
	"lib/telnet/throw.h")

add_library(${TELNET_LIB_NAME} STATIC ${TELNET_LIB_SOURCE_FILES})
target_include_directories(${TELNET_LIB_NAME} PUBLIC "${PROJECT_SOURCE_DIR}/lib/telnet")
# target_link_libraries(${TELNET_LIB_NAME} PUBLIC "ws2_32.lib")
target_compile_definitions(${TELNET_LIB_NAME} PUBLIC "WIN32_LEAN_AND_MEAN")

set_target_properties(${TELNET_LIB_NAME} PROPERTIES LINKER_LANGUAGE CXX)


###############################################################################
## 1st party libraries
###############################################################################
add_subdirectory("utils")
add_subdirectory("netw")


###############################################################################
## Executables
###############################################################################
add_subdirectory("machiavelli")
