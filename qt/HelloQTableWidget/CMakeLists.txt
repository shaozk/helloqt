cmake_minimum_required(VERSION 3.20)

project(
    HelloQTableWidget
    VERSION 1.0
    DESCRIPTION "Hello QTableWidget"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)


set(SRC 
    "main.cpp"
    "HelloQTableWidget.h"
    "HelloQTableWidget.cpp"
    "HelloQTableWidget.ui"

    )

add_executable(${PROJECT_NAME}
    ${SRC}
)


# Qt5 lib
set(CMAKE_PREFIX_PATH $ENV{QT5LIB_X64_ROOT})

find_package(Qt5 COMPONENTS 
    Widgets 
    Core 
    Concurrent
    Network
    REQUIRED
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE "$ENV{QSLOG_PATH}/include"
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Core
    PRIVATE Qt5::Concurrent
)