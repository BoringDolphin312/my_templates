cmake_minimum_required(VERSION 3.5)
project(template_project)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(QT NAMES Qt6 REQUIRED COMPONENTS Core Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Widgets)

execute_process(COMMAND rm ${CMAKE_SOURCE_DIR}/compile_commands.json)
execute_process(COMMAND ln -s ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json)

file(GLOB PROJECT_SOURCE
    ${CMAKE_SOURCE_DIR}/ui/*/*.cpp
    )

file(GLOB PROJECT_UI
    ${CMAKE_SOURCE_DIR}/ui/*/*.ui
    )

file(GLOB PROJECT_HEADER
    ${CMAKE_SOURCE_DIR}/ui/*/*.hpp
    ${CMAKE_SOURCE_DIR}/ui/*/*.h
    )

qt_add_executable(${PROJECT_NAME} 
    MANUAL_FINALIZATION
    ${PROJECT_SOURCE}
    ${PROJECT_UI}
    ${PROJECT_HEADER}
    resources.qrc
    )

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Core 
    Qt${QT_VERSION_MAJOR}::Widgets
    )

qt_finalize_executable(${PROJECT_NAME})
