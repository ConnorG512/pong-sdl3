set (PROJECT_NAME "pong")

cmake_minimum_required(VERSION 3.30)

project(${PROJECT_NAME}
  VERSION 1.0
  DESCRIPTION "Pong in SDL 3"
  LANGUAGES CXX)

# OS specific options
if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  # target_compile_options(${PROJECT_NAME} PRIVATE /W4)
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  # target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Wpedantic)
endif()

add_executable(${PROJECT_NAME} 
  src/main.cpp
  src/game_window.h 
  src/game_window.cpp
  src/sprite.h 
  src/sprite.cpp
  src/player_paddle.h 
  src/player_paddle.cpp
  src/gamestate.h
  src/ball.h
  src/ball.cpp 
  src/collision_util.h
  src/collision_util.cpp
  src/number_gen_util.h
  src/number_gen_util.cpp
)

# External libraries
include(FetchContent)
FetchContent_Declare(sdl3
  GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
  GIT_TAG release-3.2.8
)
FetchContent_MakeAvailable(sdl3)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3)
