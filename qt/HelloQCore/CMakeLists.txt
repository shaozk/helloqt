cmake_minimum_required(VERSION 3.20)

project(
    HelloQCore
    VERSION 1.0
    DESCRIPTION "Hello QCore"
    LANGUAGES CXX
)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/ui)

set(SRC 
    "main.cpp"

 "HelloQMap.h" "HelloQMap.cpp")

add_executable(${PROJECT_NAME}
    ${SRC}
)


if(NOT $ENV{QT5LIB_X64_ROOT} STREQUAL "")
    message(STATUS "find QT5LIB_ROOT: " "$ENV{QT5LIB_X64_ROOT}")
else()
    message(FATAL_ERROR "QT5LIB_ROOT not exist!")
endif()

# Qt5 lib
set(CMAKE_PREFIX_PATH $ENV{QT5LIB_X64_ROOT})

find_package(Qt5 COMPONENTS 
    Core 
    REQUIRED
)

target_include_directories(${PROJECT_NAME} 
    PRIVATE "$ENV{QSLOG_PATH}/include"
)

target_link_libraries(${PROJECT_NAME} 
    PRIVATE Qt5::Core
)

