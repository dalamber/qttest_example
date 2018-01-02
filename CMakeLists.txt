cmake_minimum_required(VERSION 3.6)
project(tester)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Widgets REQUIRED)

include_directories(./)

add_subdirectory(app)
add_subdirectory(lib)
add_subdirectory(tests)