cmake_minimum_required(VERSION 3.20)

project(
    HelloQMutex
    VERSION 1.0
    DESCRIPTION "Hello QVideo"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(SRC 
    "main.cpp"
    "HelloQVideo.h"
    "HelloQVideo.cpp"
    "VideoView.h"
    "VideoView.cpp"
    "VideoView.ui"
)

add_executable(${PROJECT_NAME}
    ${SRC}
)
set_property(TARGET ${PROJECT_NAME} PROPERTY QT4_NO_LINK_QTMAIN ON)

if(NOT $ENV{QT5LIB_ROOT} STREQUAL "")
    message(STATUS "find QT5LIB_ROOT: " "$ENV{QT5LIB_ROOT}")
else()
    message(FATAL_ERROR "QT5LIB_ROOT not exist!")
endif()


# Qt5 lib
set(CMAKE_PREFIX_PATH $ENV{QT5LIB_ROOT})

find_package(Qt5 COMPONENTS 
    Widgets 
    Core 
    Multimedia 
    MultimediaWidgets
    REQUIRED
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Core
    PRIVATE Qt5::Multimedia 
    PRIVATE Qt5::MultimediaWidgets
)

