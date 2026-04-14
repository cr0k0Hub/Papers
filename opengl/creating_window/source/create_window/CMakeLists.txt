cmake_minimum_required(VERSION 4.2)
project(create_window)

set(CMAKE_CXX_STANDARD 23)

add_executable(create_window src/main.cpp
        lib/glad/include/glad/glad.h)

# --- Подключаем GLFW ---
find_package(glfw3 REQUIRED)

# --- Подключаем GLAD ---
# Добавляем заголовочные файлы GLAD
include_directories(${CMAKE_SOURCE_DIR}/lib/glad/include)
# Собираем исходный код GLAD в отдельную библиотеку
add_library(glad STATIC ${CMAKE_SOURCE_DIR}/lib/glad/src/glad.c)

# --- Линкуем библиотеки ---
target_link_libraries(create_window glfw glad ${GLFW_LIBRARIES})