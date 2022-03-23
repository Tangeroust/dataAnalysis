cmake_minimum_required(VERSION 3.21)
project(homework)

set(CMAKE_CXX_STANDARD 17)

set(JSON BuildTests OFF CACHE INTERNAL "")

add_subdirectory("nlohmann json")
add_executable(homework main.cpp)

target_link_libraries(homework PRIVATE nlohmann_json::nlohmann_json)