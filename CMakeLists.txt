cmake_minimum_required(VERSION 3.31)
project(Window)

set(CMAKE_CXX_STANDARD 20)

#
# I M P O R T A N T !
#
# If using a different version of glfw, be sure to modify the add_subdirectory command.
# e.g. if using v2.5, add_subdirectory(lib/glfw-2.5) will likely be the correct directory.
#
add_subdirectory(lib/glfw-3.4)
include_directories(lib/glad/include)
add_executable(Window window.cpp lib/glad/src/glad.c)
target_link_libraries(Window glfw)
