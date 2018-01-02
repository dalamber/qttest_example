project(tester_app)

set(SOURCE_FILES
        src/main.cpp
        src/main_widget.cpp
        src/main_widget.h)

set(TARGET_LIBS
        Qt5::Core
        Qt5::Widgets
        tester_lib)

include_directories(lib)

add_executable(tester_app ${SOURCE_FILES})
target_link_libraries(tester_app ${TARGET_LIBS})