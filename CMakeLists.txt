cmake_minimum_required(VERSION 3.23)

set(CMAKE_CXX_STANDARD 20)

project(HyperStrike_Engine)
project(HyperStrike_Client)
project(HyperStrike_Server)
project(HyperStrike_AssetCompiler)

file(GLOB_RECURSE HyperStrike_Engine_Source Engine/*.cpp Engine/*.hpp)
file(GLOB_RECURSE HyperStrike_Client_Source Client/*.cpp Client/*.hpp)
file(GLOB_RECURSE HyperStrike_Server_Source Server/*.cpp Server/*.hpp)
file(GLOB_RECURSE HyperStrike_AssetCompiler_Source AssetCompiler/*.cpp AssetCompiler/*.hpp)

# externals
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenXR CONFIG REQUIRED)
find_package(Jolt CONFIG REQUIRED)
find_package(zstd CONFIG REQUIRED)
find_package(simdjson CONFIG REQUIRED)
find_package(fastgltf CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(enkiTS CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

add_subdirectory(external)

add_library(HyperStrike_Engine ${HyperStrike_Engine_Source})
target_include_directories(HyperStrike_Engine PRIVATE ./)
target_link_libraries(HyperStrike_Engine PUBLIC
    spdlog
    Jolt::Jolt
    enkiTS::enkiTS
    zstd::libzstd
    simdjson::simdjson
    )

add_executable(HyperStrike_Client ${HyperStrike_Client_Source})
target_include_directories(HyperStrike_Client PRIVATE ./)
target_link_libraries(HyperStrike_Client PRIVATE 
    HyperStrike_Engine 
    OpenXR::headers OpenXR::openxr_loader
    glfw
    Vulkan::Vulkan
    )

add_executable(HyperStrike_Server ${HyperStrike_Server_Source})
target_include_directories(HyperStrike_Server PRIVATE ./)
target_link_libraries(HyperStrike_Server PRIVATE 
    HyperStrike_Engine
    )

add_executable(HyperStrike_AssetCompiler ${HyperStrike_AssetCompiler_Source})
target_include_directories(HyperStrike_AssetCompiler PRIVATE ./ ${Stb_INCLUDE_DIR})
target_link_libraries(HyperStrike_AssetCompiler PRIVATE
    HyperStrike_Engine
    fastgltf::fastgltf
    )
