cmake_minimum_required(VERSION 3.5)

project(QtGifImage)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# set(CMAKE_PREFIX_PATH "~/Qt/6.5.1/gcc_64")

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt6 COMPONENTS Core Gui REQUIRED)

set(PROJECT_SOURCES
    gifimage/qgifimage.cpp
)

# Расположение заголовочных файлов
include_directories(
    3rdParty/giflib
    gifimage
)

# Добавление подпроекта, указывается имя директории
add_subdirectory(3rdParty)

add_library(${PROJECT_NAME} STATIC ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Core
    Qt6::Gui
    giflib
)
