
cmake_minimum_required(VERSION 3.8)
project(CIS_343_02)

set(CMAKE_CXX_STANDARD 11)

set(SFML_ROOT SFML-2.5.0-win64/lib/cmake/SFML)
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

include_directories(include)
include_directories(SFML)

set(SOURCE_FILES
        include
        Collision.cpp
        Game.cpp
        main.cpp
        Monster.cpp
        Person.cpp Intro.cpp)

add_executable(CIS_343_02 ${SOURCE_FILES})
target_link_libraries(CIS_343_02 sfml-graphics sfml-audio sfml-window sfml-system)

set(MEDIA_FILES fonts images music sounds sprites)
file(COPY ${MEDIA_FILES} DESTINATION .)