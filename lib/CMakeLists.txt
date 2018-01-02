project(tester_lib)

set(SOURCE_FILES
        src/random.cpp
        src/random.h)

set(TARGET_LIBS
        Qt5::Core)

add_library(tester_lib ${SOURCE_FILES})
target_link_libraries(tester_lib ${TARGET_LIBS})