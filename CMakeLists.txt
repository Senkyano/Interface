cmake_minimum_required(VERSION 3.16)
project(DroneProto VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick QuickControls2)

qt_add_executable(DroneProto 
	src/main.cpp
)

qt_add_qml_module(DroneProto
    URI drone_proto
    VERSION 1.0
    QML_FILES ui/main.qml
)

target_link_libraries(DroneProto PRIVATE
	Qt6::Core
	Qt6::Gui
	Qt6::Qml
	Qt6::Quick
	Qt6::QuickControls2
)