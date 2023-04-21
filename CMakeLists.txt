cmake_minimum_required(VERSION 3.10)
set(projectName opencv)
project(${projectName})

# include(auto_version.cmake)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

set(OpenCV_DIR /usr/local/opencv4.7/lib/cmake/opencv4)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# include_directories (${CMAKE_SOURCE_DIR}/add/src)

# link_directories (${CMAKE_SOURCE_DIR}/build/archive)

add_executable(demo001 ./cpp/code_001.cpp)

target_link_libraries(demo001 ${OpenCV_LIBS})
