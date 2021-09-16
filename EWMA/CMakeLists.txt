cmake_minimum_required(VERSION 3.10)

project(
  Ewma
  VERSION 0.1
  DESCRIPTION "Ewma"
  LANGUAGES CXX)

## APP OUTPUT
set(TARGET_APP ${CMAKE_PROJECT_NAME}.out)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_BUILD_TYPE RelWithDebInfo)
#set(CMAKE_BUILD_TYPE Release)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(${TARGET_APP} main.cpp Ewma.cpp)

target_compile_definitions(${TARGET_APP} PUBLIC )
target_include_directories(${TARGET_APP} PUBLIC )
target_link_libraries(${TARGET_APP} )
