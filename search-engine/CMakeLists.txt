cmake_minimum_required(VERSION 3.5)

project(search-engine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(
    search-engine
    main.cpp
    converter_json.h converter_json.cpp
    inverted_index.h inverted_index.cpp
    searchserver.h searchserver.cpp
)

#nlohmann_json
include(FetchContent)

FetchContent_Declare(json URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz)
FetchContent_MakeAvailable(json)
target_link_libraries(search-engine PRIVATE nlohmann_json::nlohmann_json)

#Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL
    https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
set(gtest_disable_pthreads on)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
enable_testing()
target_link_libraries(search-engine PRIVATE gtest_main)
include(GoogleTest)
gtest_discover_tests(search-engine)
