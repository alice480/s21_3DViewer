# Проверка версии CMake. Если версия установленой программы
# старее указаной, произайдёт аварийный выход.
cmake_minimum_required(VERSION 3.5)

# Название проекта
project(giflib)

# Установка переменной со списком исходников
set(SOURCES 
    giflib/dgif_lib.c 
    giflib/egif_lib.c 
    giflib/gif_err.c 
    giflib/gif_font.c 
    giflib/gif_hash.c 
    giflib/gifalloc.c 
    giflib/quantize.c 
)		

# Создание статической библиотеки
add_library(${PROJECT_NAME} STATIC ${SOURCES})
