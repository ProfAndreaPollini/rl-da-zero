cmake_minimum_required(VERSION 3.21)
project(rl_da_zero)

set(CMAKE_CXX_STANDARD 20)

# raylib
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib
            GIT_REPOSITORY https://github.com/raysan5/raylib.git
            GIT_TAG 0851960397f02a477d80eda2239f90fae14dec64
    )
    FetchContent_GetProperties(raylib)
    if (NOT raylib_POPULATED) # Have we downloaded raylib yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib)
        set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_GAMES    OFF CACHE BOOL "" FORCE)
        set(BUILD_TESTING  OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
    endif()
endif()

# raylib-cpp
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(
            raylib_cpp
            URL https://github.com/RobLoach/raylib-cpp/archive/master.tar.gz
    )
    FetchContent_GetProperties(raylib_cpp)
    if (NOT raylib_cpp_POPULATED) # Have we downloaded raylib-cpp yet?
        set(FETCHCONTENT_QUIET NO)
        FetchContent_Populate(raylib_cpp)
        set(BUILD_RAYLIB_CPP_EXAMPLES OFF CACHE BOOL "" FORCE)
        set(BUILD_TESTING             OFF CACHE BOOL "" FORCE)
        add_subdirectory(${raylib_cpp_SOURCE_DIR} ${raylib_cpp_BINARY_DIR})
    endif()
endif()

add_subdirectory(vendor/fmt)


add_executable(rl_da_zero main.cpp)

add_subdirectory(src)


target_link_libraries(rl_da_zero PRIVATE fmt::fmt-header-only)
set(raylib_VERBOSE 1)
target_link_libraries(rl_da_zero PUBLIC raylib raylib_cpp)
