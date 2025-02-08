cmake_minimum_required(VERSION 3.31.5)

# Set the project name
project(MyCppProject VERSION 0.2)


# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
find_package(SQLite3 REQUIRED)

include(FetchContent)
FetchContent_Declare(cpr GIT_REPOSITORY https://github.com/libcpr/cpr.git
                         GIT_TAG dec9422db3af470641f8b0d90e4b451c4daebf64) # Replace with your desired git commit from: https://github.com/libcpr/cpr/releases
FetchContent_MakeAvailable(cpr)
# Add the executable
add_executable(cpp_project main.cpp)
# Add cxxopts header file from the include directory
target_sources(cpp_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/sqllite_models.cpp)
target_include_directories(cpp_project PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(cpp_project PRIVATE cpr::cpr SQLite::SQLite3)
