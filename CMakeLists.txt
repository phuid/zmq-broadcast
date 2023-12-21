cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

project(cppzmq-examples CXX)

# place binaries and libraries according to GNU standards

include(GNUInstallDirs)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

find_package(Threads)
find_package(cppzmq)

add_executable(
    server
    s.cpp
)
target_link_libraries(
    server
    PRIVATE cppzmq ${CMAKE_THREAD_LIBS_INIT}
)

add_executable(
    client
    c.cpp
)
target_link_libraries(
    client
    PRIVATE cppzmq ${CMAKE_THREAD_LIBS_INIT}
)
