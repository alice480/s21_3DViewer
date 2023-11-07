# Проверка версии CMake. Если версия установленой программы
# старее указаной, произайдёт аварийный выход.
cmake_minimum_required(VERSION 3.5)

# Название проекта
project(backend)

# Установка переменной со списком исходников
set(SOURCES objparser.c affinity.c)		

# Создание статической библиотеки
add_library(${PROJECT_NAME} STATIC ${SOURCES})