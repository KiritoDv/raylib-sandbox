set(CMAKE_CXX_STANDARD 20)
project(ImGui)

include_directories("imgui/")
include_directories("imgui/backends/")

add_library( ${PROJECT_NAME} STATIC imgui/imgui_demo.cpp imgui/imgui_draw.cpp imgui/backends/imgui_impl_opengl3.cpp imgui/imgui_tables.cpp imgui/imgui_widgets.cpp imgui/imgui.cpp )
target_include_directories( ${PROJECT_NAME} PUBLIC imgui/)