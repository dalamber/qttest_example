project(tester_lib)

set(SOURCE_FILES
        src/random.cpp
        src/random.h
        src/async_reply.h
        src/downloader.cpp
        src/downloader.h)

find_package(Qt5Network REQUIRED)

set(TARGET_LIBS
        Qt5::Core
        Qt5::Network)

add_library(tester_lib ${SOURCE_FILES})
target_link_libraries(tester_lib ${TARGET_LIBS})