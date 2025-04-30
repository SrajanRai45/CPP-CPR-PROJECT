cmake_minimum_required(VERSION 3.10)
project(MyProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add CPR library
add_subdirectory(extern/cpr)

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add executable
add_executable(MyExecutable src/main.cpp)

# Link CPR library
target_link_libraries(MyExecutable PRIVATE cpr::cpr)
