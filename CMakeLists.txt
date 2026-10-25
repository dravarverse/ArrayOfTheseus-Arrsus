cmake_minimum_required(VERSION 3.15)
project(ArrayOfTheseus LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(arrsus STATIC src/arrsus.cpp)
target_include_directories(arrsus PUBLIC include)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE arrsus)

target_include_directories(arrsus PUBLIC include)
set_target_properties(arrsus PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/lib"
)