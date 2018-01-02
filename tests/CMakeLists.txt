project(tester_tests)

find_package(Qt5Test REQUIRED)

set(SOURCE_FILES
        src/main.cpp
        src/test_main.cpp
        src/test_main.h)

set(TARGET_LIBS
        Qt5::Test
        tester_lib)

add_executable(tester_tests ${SOURCE_FILES})
target_link_libraries(tester_tests ${TARGET_LIBS})