cmake_minimum_required(VERSION 3.10)
project(reVKLearn)

set(CMAKE_CXX_STANDARD 20)

set(DEP_DIR ${CMAKE_CURRENT_SOURCE_DIR}/dependency)

add_executable(${PROJECT_NAME} src/main.cpp)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${DEP_DIR}
    ${DEP_DIR}/glm
    ${DEP_DIR}/GLFW/include
    ${DEP_DIR}/Vulkan/Include
)

target_link_directories(${PROJECT_NAME} PRIVATE
    ${DEP_DIR}/GLFW/lib_mingw64
    ${DEP_DIR}/Vulkan/Lib
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    glfw3
    vulkan-1
    gdi32
    shell32
)