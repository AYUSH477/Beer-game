cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

project(beer-game)

set (CMAKE_BINARY_DIR ../)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_executable(beergame
    ${COMMON_SOURCE_FILES}
    main.cpp
    beergamewindow.cpp
    beergamewindow.h
    beergamewindow.ui
    ../resources/resources.qrc
)

add_subdirectory(client)
add_subdirectory(server)

target_link_libraries(beergame PRIVATE Qt5::Widgets Qt5::Network Qt5::Core Qt5::Gui)


