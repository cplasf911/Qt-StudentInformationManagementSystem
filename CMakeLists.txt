cmake_minimum_required(VERSION 3.20)
project(QtStudy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/usr/local/Cellar/qt/6.2.1")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(QtStudy student.cpp student.h MainWidget.cpp MainWidget.h EditStudentMessageBox.cpp EditStudentMessageBox.h config.h main.cpp)
target_link_libraries(QtStudy
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

