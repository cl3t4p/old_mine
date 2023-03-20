cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 14)


# Make that the system like Linux who's SDL directory uses <SDL2/SDL> become just <SDL> just like windows
if(NOT SDL2_DIR)
  set(SDL2_DIR "" CACHE PATH "SDL2 directory")
endif()

find_path(SDL2_INCLUDE_DIR SDL.h
        HINTS
        ENV SDL2DIR
        ${SDL2_DIR}
        PATH_SUFFIXES SDL2
        # path suffixes to search inside ENV{SDL2DIR}
        include/SDL2 include
        )

if(WIN32)
  set(JPEG_INCLUDE_DIR "C:/Program Files (x86)/jpeg/include")
  set(JPEG_LIBRARY "C:/Program Files (x86)/jpeg/lib")
endif(WIN32)

if(NOT PNG
   AND WIN32
   AND NOT MSVC)
  set(PNG_LIBRARY "C:/Program Files (x86)/libpng")
  set(PNG_PNG_INCLUDE_DIR "C:/Program Files (x86)/libpng/include")
endif()
# Find the SDL2 and SDL2_image libraries
find_package(SDL2 REQUIRED)

find_package(SDL2_image REQUIRED)

add_executable(
  game
  src/main.cpp
  src/Game.cpp
  src/TextureManager.cpp
  src/GameObject.cpp
  src/Level.cpp
  include/ECS/ECS.h
  include/ECS/Component.h
  include/ECS/SpriteComponent.h
  include/ECS/TransformComponent.h)

target_include_directories(
  ${PROJECT_NAME}
  PUBLIC include
  PUBLIC ${SDL2_INCLUDE_DIRS}
  PUBLIC ${SDL2_IMAGE_INCLUDE_DIRS})

if(WIN32)
  target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES}
                                               SDL2_image::SDL2_image mingw32)
else()
  target_link_libraries(${PROJECT_NAME} PUBLIC ${SDL2_LIBRARIES} SDL2_image::SDL2_image)
endif()

if(NOT APPLE)
  find_package(Threads)
endif()