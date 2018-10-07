
cmake_minimum_required(VERSION 3.8)
project(CIS_343_02)

set(CMAKE_CXX_STANDARD 11)

set(SFML_DIR SFML-2.5.0-win64/lib/cmake/SFML)

find_package(SFML COMPONENTS graphics audio REQUIRED)

include_directories(include)
include_directories(SFML)

set(SOURCE_FILES
        include
        Collision.cpp
        Game.cpp
        main.cpp
        Monster.cpp
        Person.cpp Intro.cpp
        Animator.cpp
        Collectable.cpp
        Coin.cpp
        Sandwich.cpp)

add_executable(CIS_343_02 ${SOURCE_FILES})
target_link_libraries(CIS_343_02 sfml-graphics sfml-audio sfml-window sfml-system)

set(MEDIA_FILES fonts images music sounds sprites)
file(COPY ${MEDIA_FILES} DESTINATION .)