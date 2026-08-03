cmake_minimum_required(VERSION 3.20)

project(
    TireSim
    VERSION 0.1.5
    DESCRIPTION "Real-time soft-body tire like simulation C++ Project"
    LANGUAGES CXX
    )

add_executable(
    TireSim
    src/main.cpp
    src/Particle1D.cpp
    src/Spring1D.cpp
    src/CsvWriter.cpp
    )

target_compile_features(
    TireSim
    PRIVATE
    cxx_std_20
)

target_include_directories(
    TireSim
    PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(
        TireSim
        PRIVATE
        /W4
        /permissive-
    )
else()
    target_compile_options(
        TireSim
        PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
endif()