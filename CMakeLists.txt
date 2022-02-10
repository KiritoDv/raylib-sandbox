cmake_minimum_required(VERSION 3.16)
project(IsometricSandbox)

set(PLATFORM "Web")
set(CMAKE_CXX_STANDARD 20)
add_definitions("-std=c++20")
set(CMAKE_EXECUTABLE_SUFFIX ".html")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)
set(CMAKE_TOOLCHAIN_FILE $ENV{EMSDK}/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake)
set(CMAKE_CROSSCOMPILING_EMULATOR $ENV{EMSDK}/node/14.18.2_64bit/bin/node;--experimental-wasm-threads)

add_subdirectory(libs)
add_subdirectory(libs/raylib)

include_directories(src)
include_directories(src/game)
include_directories(include)

file(GLOB_RECURSE HEADERS src/*.h)
file(GLOB_RECURSE SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -Dsrc_dir="${CMAKE_SOURCE_DIR}/assets" -Ddst_dir="${CMAKE_CURRENT_BINARY_DIR}/assets" -P "${CMAKE_CURRENT_SOURCE_DIR}/Overwrite.cmake")
set_target_properties(${PROJECT_NAME} PROPERTIES LINK_FLAGS "-s USE_GLFW=3 -s ALLOW_MEMORY_GROWTH=1 -s FORCE_FILESYSTEM=1 --preload-file=assets/ --shell-file ${CMAKE_SOURCE_DIR}/src/shell.html")

target_link_libraries(${PROJECT_NAME} PUBLIC raylib)
target_link_libraries(${PROJECT_NAME} PUBLIC imgui)