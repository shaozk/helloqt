cmake_minimum_required(VERSION 3.20)

project(
    HelloQt
    VERSION 1.0
    DESCRIPTION "Hello Qt"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)


set(SRC 
    "main.cpp"
    "HelloQt.h"
    "HelloQt.cpp"
    "HelloProperty.h"
    "HelloProperty.cpp"

    )

add_executable(${PROJECT_NAME}
    ${SRC}
)

if(NOT $ENV{QSLOG_PATH} STREQUAL "")
    message(STATUS "find QSLOG_PATH: " "$ENV{QSLOG_PATH}")
else()
    message(FATAL_ERROR "QSLOG_PATH not exist!")
endif()


if(NOT $ENV{QT5LIB_X64_ROOT} STREQUAL "")
    message(STATUS "find QT5LIB_ROOT: " "$ENV{QT5LIB_X64_ROOT}")
else()
    message(FATAL_ERROR "QT5LIB_ROOT not exist!")
endif()


# QsLog lib
add_library(qslog SHARED IMPORTED GLOBAL)
set_property(TARGET qslog PROPERTY IMPORTED_IMPLIB_RELEASE "$ENV{QSLOG_PATH}/lib/release/QsLog2.lib")
set_property(TARGET qslog PROPERTY IMPORTED_LOCATION_RELEASE "$ENV{QSLOG_PATH}/lib/release/QsLog2.dll")
set_property(TARGET qslog PROPERTY IMPORTED_IMPLIB_DEBUG "$ENV{QSLOG_PATH}/lib/debug/QsLog2.lib")
set_property(TARGET qslog PROPERTY IMPORTED_LOCATION_DEBUG "$ENV{QSLOG_PATH}/lib/debug/QsLog2.dll")

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
    PRIVATE qslog
    PRIVATE Qt5::Widgets
    PRIVATE Qt5::Core
    PRIVATE Qt5::Concurrent
)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:qslog> $<TARGET_FILE_DIR:${PROJECT_NAME}>
)

