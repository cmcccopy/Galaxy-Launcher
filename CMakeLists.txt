cmake_minimum_required(VERSION 3.10)

project(Galaxy-Launcher
        LANGUAGES CXX ## 指定项目语言
        VERSION 0.1.9.0 # Major.Minor.Patch.Tweak
)

set(CMAKE_CXX_STANDARD 17) ##指定CXX的标准
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## input 文件的地址是根据${CMAKE_SOURCE_DIR}的相对路径进行寻址的 
## output 是根据${CMAKE_BINARY_DIR}的相对路径进行寻址的
configure_file(Configure.h.in "${CMAKE_SOURCE_DIR}/Configure.h") 
##这里可以使用绝对路径进行代替

# GLFW 
set(GLFW_DIR ${CMAKE_SOURCE_DIR}/external/glfw)
option(GLFW_BUILD_EXAMPLES "Build the GLFW example programs" OFF) ##GLFW会根据这些OPTION选择编译那些module
option(GLFW_BUILD_TESTS "Build the GLFW test programs" OFF)
option(GLFW_BUILD_DOCS "Build the GLFW documentation" OFF)
option(GLFW_INSTALL "Generate installation target" OFF)
option(GLFW_DOCUMENT_INTERNALS "Include internals in documentation" OFF)

add_subdirectory(${GLFW_DIR} glfw_binary EXCLUDE_FROM_ALL) ##将GLFW引入到我们的项目

#GLFW的头文件
list(APPEND IMGUI_INCLUDE_DIR ${GLFW_DIR}/include) 
list(APPEND IMGUI_INCLUDE_DIR ${GLFW_DIR}/deps)

list(APPEND LINK_LIBS glfw) ##将glfw添加到库

# vulkan
find_package(Vulkan REQUIRED)
list(APPEND LINK_LIBS "Vulkan::Vulkan")

# imgui
set(IMGUI_DIR ${CMAKE_SOURCE_DIR}/external/imgui)
list(APPEND IMGUI_INCLUDE_DIR ${IMGUI_DIR} ${IMGUI_DIR}/backends)

# SOURCE
list(
  APPEND
  IMGUI_SOURCE
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
  ${IMGUI_DIR}/backends/imgui_impl_vulkan.cpp
  ${IMGUI_DIR}/imgui.cpp
  ${IMGUI_DIR}/imgui_draw.cpp
  ${IMGUI_DIR}/imgui_demo.cpp
  ${IMGUI_DIR}/imgui_tables.cpp
  ${IMGUI_DIR}/imgui_widgets.cpp
)



set_property(GLOBAL PROPERTY IMGUI_DIR ${IMGUI_DIR})
set_property(GLOBAL PROPERTY IMGUI_SOURCE )
set_property(GLOBAL PROPERTY LINK_LIBS)
set_property(GLOBAL PROPERTY IMGUI_INCLUDE_DIR)

add_subdirectory(${CMAKE_SOURCE_DIR}/external/add)
add_subdirectory(./src)#到src找CMakeLists文件