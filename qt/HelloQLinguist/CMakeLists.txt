cmake_minimum_required(VERSION 3.20)

project(
    HelloQLinguist
    VERSION 1.0
    DESCRIPTION "Hello QLinguist"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

if(NOT $ENV{QT5LIB_x64_ROOT} STREQUAL "")
    message(STATUS "find QT5LIB_ROOT: " "$ENV{QT5LIB_x64_ROOT}")
else()
    message(FATAL_ERROR "QT5LIB_ROOT not exist!")
endif()

set(SRC 
    "main.cpp"
    "QLinguistWidget.h"
    "QLinguistWidget.cpp"
    "QLinguistWidget.ui"
)


# Qt5 lib
set(CMAKE_PREFIX_PATH $ENV{QT5LIB_x64_ROOT})

find_package(Qt5 COMPONENTS 
    Widgets 
    Core 
    LinguistTools
    REQUIRED
)

set(TS_FILES
    ${CMAKE_SOURCE_DIR}/languages/zh_CN.ts
)
 
qt5_create_translation(QM_FILES ${CMAKE_CURRENT_SOURCE_DIR} ${TS_FILES})
 
add_executable(${PROJECT_NAME}
    ${SRC}
    ${TS_FILES}
    ${QM_FILES}
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Core
)