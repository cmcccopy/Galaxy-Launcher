

#add_executable(Galaxy-Launcher main.cpp)
add_executable(Galaxy-Launcher ${IMGUI_SOURCE})

target_include_directories(Galaxy-Launcher PUBLIC ${IMGUI_INCLUDE_DIR})
target_link_libraries(Galaxy-Launcher PUBLIC ${LINK_LIBS})


#这意味着 Galaxy-Launcher 可执行文件可以包含位于包含目录列表中的头文件。
target_include_directories(Galaxy-Launcher PUBLIC ${CMAKE_SOURCE_DIR}/external/add)
#使用该命令将库文件指定给编译对象
target_link_libraries(Galaxy-Launcher PUBLIC ExternalAdd) 
#get_property(IMGUI_DIR2 GLOBAL PROPERTY IMGUI_DIR)
message("IMGUI_DIR: ${IMGUI_INCLUDE_DIR}.")