cmake_minimum_required(VERSION 3.10)
project(mp7b)

set (CMAKE_CXX_STANDARD 11)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

file(GLOB_RECURSE MP7B_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
add_library(mp7b_src ${MP7B_SRC})
target_include_directories(mp7b_src PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(mp7b ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(mp7b mp7b_src)

file(GLOB_RECURSE MP7B_TEST_SRC ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)
add_executable(tests ${MP7B_TEST_SRC})
target_link_libraries(tests mp7b_src)
target_link_libraries(tests ${CONAN_LIBS})
