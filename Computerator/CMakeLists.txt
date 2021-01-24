add_executable(computerator MainApp.cpp MainFrame.cpp)
target_link_libraries(computerator ${wxWidgets_LIBRARIES})
target_include_directories(computerator PUBLIC ${wxWidgets_INCLUDE_DIRS})