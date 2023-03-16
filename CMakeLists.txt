cmake_minimum_required(VERSION 3.17)
project(game)

set(CMAKE_CXX_STANDARD 14)



# Add the source files for the project
set(JPEG_INCLUDE_DIR "C:/Program Files (x86)/jpeg/include")
set(JPEG_LIBRARY "C:/Program Files (x86)/jpeg/lib")


if(NOT PNG AND WIN32 AND NOT MSVC)
    set(PNG_LIBRARY "C:/Program Files (x86)/libpng")
    set(PNG_PNG_INCLUDE_DIR "C:/Program Files (x86)/libpng/include")
endif()
# Find the SDL2 and SDL2_image libraries
find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)

add_executable(game src/main.cpp  src/Game.cpp src/TextureManager.cpp src/GameObject.cpp src/Level.cpp include/ECS.h include/Component.h)

target_include_directories(${PROJECT_NAME}
        PUBLIC include
        PUBLIC ${SDL2_INCLUDE_DIRS}
        PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})

if(WIN32 AND NOT MSVC)
    target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image mingw32)
endif()