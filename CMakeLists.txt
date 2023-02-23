cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(PokemonGame)

set(SOURCES
        code/main.cpp
        code/Move.cpp
        code/MoveLibrary.cpp
        code/Player.cpp
        code/Pokemon.cpp
        code/PokemonLibrary.cpp
        code/Type.cpp
        code/Arena.hpp code/Arena.cpp)

add_executable(main ${SOURCES} code/Arena.cpp)

set_target_properties(main PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        )

target_include_directories(main PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/code
        )

#allow program to find the code/data folder
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/code/data DESTINATION ${CMAKE_BINARY_DIR}/bin)