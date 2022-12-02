cmake_minimum_required(VERSION 3.13)  # CMake version check
project(HelloCurses CXX)               # Create project "simple_example"
set(CMAKE_CXX_STANDARD 17)            # Enable c++14 standard

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES hellocurses.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(HelloCurses ${SOURCE_FILES})

# Add libraries
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

target_link_libraries(HelloCurses ${CURSES_LIBRARIES})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
