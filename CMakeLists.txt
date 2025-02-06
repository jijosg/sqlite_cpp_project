cmake_minimum_required(VERSION 3.31.5)

# Set the project name
project(MyCppProject VERSION 0.2)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(cpp_project com/volvo/main.cpp)