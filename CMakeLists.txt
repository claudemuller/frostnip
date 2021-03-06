cmake_minimum_required(VERSION 3.17)
project(frostbit C)

set(SOURCE_FILES src/main.c src/constants.h
        src/animation.c src/animation.h
        src/asset_manager.c src/asset_manager.h
        src/entity_manager.h src/entity_manager.c
        src/game.c src/game.h
        src/display.c src/display.h
        src/vector.c src/vector.h
        src/utils/benchmark.c src/utils/benchmark.h
        src/entity.c src/entity.h
        src/layer_type.c src/layer_type.h
        src/component.c src/component.h
        src/lib/stretchy_buffer.h src/lib/stb_leakcheck.h)
set(CMAKE_C_STANDARD 99)

set(SDL2_ROOT    "D:/libs/sdl2")
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(SDL2_ROOT    "/usr/local/Cellar/sdl2/2.0.12_1")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
if(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    set(SDL2_ROOT    "/usr/local/sdl2")
endif(${CMAKE_SYSTEM_NAME} MATCHES "Linux")
set(SDL2_INCLUDE "${SDL2_ROOT}/include")
set(SDL2_LIB     "${SDL2_ROOT}/lib")
set(SDL2_LIBS    "SDL2")

set(PROJECT_INCLUDE "${PROJECT_SOURCE_DIR}/include")
set(PROJECT_LIB     "${PROJECT_SOURCE_DIR}/lib")

# For completion
include_directories(${PROJECT_INCLUDE})
include_directories(${SDL2_INCLUDE})

link_directories(${PROJECT_LIB})
link_directories(${SDL2_LIB})

add_executable(frostbit ${SOURCE_FILES})

target_link_libraries(frostbit ${SDL2_LIBS})
