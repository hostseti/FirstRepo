cmake_minimum_required(VERSION 3.5)
project(WindowChat LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

IF(WIN32)
SET(GUI_TYPE WIN32)
ENDIF(WIN32)

IF (APPLE)
SET(GUI_TYPE MACOSX_BUNDLE)
ENDIF (APPLE)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(WindowChat ${GUI_TYPE}
    main.cpp
    common_header.h

    serverchat.cpp
    serverchat.h
    serverchat.ui

    clientchat.cpp
    clientchat.h
    clientchat.ui
)
target_link_libraries(WindowChat PRIVATE Qt5::Widgets)
